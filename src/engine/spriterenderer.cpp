#include <cmath>

#include "engine/spriterenderer.h"
#include "engine/sprite.h"

namespace meh {

SpriteRenderer::SpriteRenderer() :
    SpriteRenderer(1000) {
}

SpriteRenderer::SpriteRenderer(unsigned int size) :
    msh(nullptr), 
    lastUsedTexture(nullptr),
    sze(size),
    idx(0),
    spriteBuffered(0),
    shaderProgram(nullptr),
    isRendering(false) {

    vrtices = new GLfloat[sze*Sprite::SIZE];
    elmts = new GLuint[sze*6]; // two triangles = 6 elements

    unsigned int j = 0;
    for (unsigned int i = 0; i < sze*6; i+=6) {
        elmts[i] = j;
        elmts[i+1] = j+1;
        elmts[i+2] = j+2;
        elmts[i+3] = j+2;
        elmts[i+4] = j+3;
        elmts[i+5] = j;
        j += 4;
    }

    VertexAttributes vertexAttributes;
    vertexAttributes.addAttribute(VertexAttribute(3,0,VertexAttributes::positionAttribute));
    vertexAttributes.addAttribute(VertexAttribute(2,3,VertexAttributes::textureCoordinatesAttribute));
    vertexAttributes.addAttribute(VertexAttribute(4,5,VertexAttributes::tintColorAttribute));

    msh = new Mesh(vertexAttributes);

    init();
}

SpriteRenderer::~SpriteRenderer() {
    deinit(true);
}

void SpriteRenderer::init() {
    idx = 0;
    spriteBuffered = 0;
}

void SpriteRenderer::deinit(bool deleteMemory) {
    if (deleteMemory) {
        if (msh) {
            delete msh;
            msh = nullptr;
        }
        if (vrtices) {
            delete[] vrtices;
            vrtices = nullptr;
        }
        if (elmts) {
            delete[] elmts;
            elmts = nullptr;
        }
    }
}

void SpriteRenderer::switchTexture(Texture* newTexture) {
    if (newTexture != lastUsedTexture) {
        if (lastUsedTexture != nullptr) {
            render();
        }
        invTexW = 1.0f/newTexture->width();
        invTexH = 1.0f/newTexture->height();
    }
    lastUsedTexture = newTexture;
}

void SpriteRenderer::draw(Texture* texture, float x, float y, float w, float h, float centerX, float centerY,
                        float scaleX, float scaleY, float rotation, float texX, float texY, float texW, float texH,
                        float r, float g, float b, float a, bool flipX, bool flipY) {
    if (!isRendering) {
        printf("ERROR: illegal state: call to draw() but the renderer isn't in rendering mode.\n");
        return;
    }

    if (spriteBuffered >= sze) {
        render();
    }

    switchTexture(texture);

    // TODO scale and rotation

    // Computes from texture coordinates to normalized values (between [0.0f;1.0f])
    // Y-inversed (texture are y-inversed in memory) 
    float u = texX*invTexW;
    float v = (texY+texH)*invTexH;
    float uu = (texX+texW)*invTexW;
    float vv = texY*invTexH;

    // flipped on x-axis
    if (flipX) {
        float tmp = u;
        u = uu;
        uu = tmp;
    }
    // flipped on y-axis
    if (flipY)
    {
        float tmp = v;
        v = vv;
        vv = tmp;
    }

    // vertex
    vrtices[idx++] = x;
    vrtices[idx++] = y;
    vrtices[idx++] = 0.0f;
    // texcoord
    vrtices[idx++] = u;
    vrtices[idx++] = v;
    // tint 
    vrtices[idx++] = r;
    vrtices[idx++] = g;
    vrtices[idx++] = b;
    vrtices[idx++] = a;

    // vertex
    vrtices[idx++] = x+w;
    vrtices[idx++] = y;
    vrtices[idx++] = 0.0f;
    // texcoord
    vrtices[idx++] = uu;
    vrtices[idx++] = v;
    // opacity
    vrtices[idx++] = r;
    vrtices[idx++] = g;
    vrtices[idx++] = b;
    vrtices[idx++] = a;

    // vertex
    vrtices[idx++] = x+w;
    vrtices[idx++] = y+h;
    vrtices[idx++] = 0.0f;
    // texcoord
    vrtices[idx++] = uu;
    vrtices[idx++] = vv;
    // opacity
    vrtices[idx++] = r;
    vrtices[idx++] = g;
    vrtices[idx++] = b;
    vrtices[idx++] = a;

    // vertex
    vrtices[idx++] = x;
    vrtices[idx++] = y+h;
    vrtices[idx++] = 0.0f;
    // texcoord
    vrtices[idx++] = u;
    vrtices[idx++] = vv;
    // opacity
    vrtices[idx++] = r;
    vrtices[idx++] = g;
    vrtices[idx++] = b;
    vrtices[idx++] = a;

    spriteBuffered++;
}

void SpriteRenderer::draw(Sprite& sprite) {
    if (sprite.visible()) {
        draw(sprite.texture(), sprite.getX(), sprite.getY(), sprite.getWidth(), sprite.getHeight(), sprite.getRotationCenter().x(), sprite.getRotationCenter().y(),
                sprite.getScaleX(), sprite.getScaleY(), sprite.getRotation(), sprite.getTextureRegion().x(), sprite.getTextureRegion().y(),
                sprite.getTextureRegion().width(), sprite.getTextureRegion().height(), sprite.getTint().x(), sprite.getTint().y(), sprite.getTint().z(), sprite.getTint().i(), false, false); 
    }
}

void SpriteRenderer::begin(ShaderProgram* shaderProgram) {
    if (!shaderProgram) {
       printf("ERROR: SpriteRenderer::begin(ShaderProgram*) called with a shaderProgram as nullptr.\n"); 
       return;
    }
    if (isRendering) {
        printf("ERROR: illegal state: the renderer was already in the rendering state.\n");
        return;
    }

    shaderProgram->enable();    
    // Set the camera position
    shaderProgram->setUniformMatrix4x4(ShaderProgram::modelViewProjectionAttribute, mdelViewMatrix);

    shaderProgram->setUniformf("meh_tintcolor", 1.0f, 0.5f, 0.5f, 0.5f);
    this->shaderProgram = shaderProgram;

    // We enter in the rendering state
    isRendering = true;
}

void SpriteRenderer::end() {
    if (isRendering) {
        if (idx > 0) {
            render();
        }
        shaderProgram->disable();
        shaderProgram = nullptr;

        // We're no longer rendering
        isRendering = false;

        deinit(false);
        init();
    } else {
        printf("ERROR: illegal state: call to end() but the renderer isn't in rendering mode.\n");
    }
}

void SpriteRenderer::render() {
    if (!isRendering) {
        printf("ERROR: illegal state: call to render() but the renderer isn't in rendering mode.\n");
        return;
    }
    
    if (idx > 0) {
        lastUsedTexture->bind(0);

        msh->setVertices(spriteBuffered*4, Sprite::VERTEX_SIZE, vrtices);
        msh->setElements(spriteBuffered*2, 3, elmts);

        // printf("renders %i sprites, %i vertices in %i elements\n",spriteBuffered, spriteBuffered*4,spriteBuffered*2);

        msh->bind(*shaderProgram);
        msh->render();
        msh->unbind();
    }

    deinit(false);
    init();
}

} // namespace meh 
