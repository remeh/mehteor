#include "engine/spriterenderer.h"
#include "engine/resourcesmanager.h"
#include "engine/sprite.h"

namespace meh {

SpriteRenderer::SpriteRenderer(ResourcesManager& resourcesManager) :
    SpriteRenderer(resourcesManager, 1000) {
}

SpriteRenderer::SpriteRenderer(ResourcesManager& resourcesManager, int size) :
    msh(nullptr), 
    rsourcesManager(resourcesManager),
    lastUsedTexture(nullptr),
    sze(size),
    idx(0),
    idxElements(0),
    nElements(0),
    shaderProgram(nullptr) {
    init();
}

SpriteRenderer::~SpriteRenderer() {
    deinit();
}

void SpriteRenderer::init() {
    vrtices = new GLfloat[sze*Sprite::SIZE];
    elmts = new GLuint[sze*6]; // two triangles = 6 elements
    idx = 0;
    idxElements = 0;
    nElements = 0;
}

void SpriteRenderer::deinit() {
    if (vrtices) {
        delete[] vrtices;
        vrtices = nullptr;
    }
    if (elmts) {
        delete[] elmts;
        elmts = nullptr;
    }
    if (msh) {
        delete msh;
        msh = nullptr;
    }
    idx = 0;
    idxElements = 0;
    nElements = 0;
}

void SpriteRenderer::directDraw(Sprite& sprite, ShaderProgram& shaderProgram) {
    VertexAttributes vertexAttributes;
    vertexAttributes.addAttribute(VertexAttribute(3,0,VertexAttributes::positionAttribute));
    vertexAttributes.addAttribute(VertexAttribute(2,3,VertexAttributes::textureCoordinatesAttribute));
    msh = new Mesh(vertexAttributes);

    GLfloat vertices[] = {
        sprite.rect().x(), sprite.rect().y(), 0.0f, 0.0f,
        sprite.rect().x()+sprite.rect().width(), sprite.rect().y(), 1.0f, 0.0f,
        sprite.rect().x()+sprite.rect().width(), sprite.rect().y()+sprite.rect().height(), 1.0f, 1.0f,
        sprite.rect().x(), sprite.rect().y()+sprite.rect().height(), 0.0f, 1.0f
    };
    GLuint elements[] = {
        0, 1 ,2,
        2, 3, 0
    };
    shaderProgram.enable();
    sprite.texture()->bind(0);
    msh->setVertices(4,4,vertices);
    msh->setElements(2,3,elements);
    msh->bind(shaderProgram);
    shaderProgram.setUniformMatrix4x4(ShaderProgram::modelViewProjectionAttribute, mdelViewMatrix);
    msh->render();
    msh->unbind();
    shaderProgram.disable();

    delete msh;
    msh = nullptr;
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
                        bool flipX, bool flipY) {
    switchTexture(texture);

    // TODO scale and rotation

    // Computes from texture coordinates to normalized values (between [0.0f;1.0f])
    float u = texX*invTexW;
    float v = texY*invTexH;
    float uu = (texX+texW)*invTexW;
    float vv = (texY+texH)*invTexH;

    // flipped on x-axis
    if (flipX) {
        float tmp = u;
        u = uu;
        uu = tmp;
    }
    // flipped on y-axis
    if (flipY) {
        float tmp = v;
        v = vv;
        vv = tmp;
    }

    vrtices[idx++] = x;
    vrtices[idx++] = y;
    vrtices[idx++] = u;
    vrtices[idx++] = v;

    vrtices[idx++] = x+w;
    vrtices[idx++] = y;
    vrtices[idx++] = uu;
    vrtices[idx++] = v;

    vrtices[idx++] = x+w;
    vrtices[idx++] = y+h;
    vrtices[idx++] = uu;
    vrtices[idx++] = vv;

    vrtices[idx++] = x;
    vrtices[idx++] = y+h;
    vrtices[idx++] = u;
    vrtices[idx++] = vv;

    elmts[idxElements++] = nElements;
    elmts[idxElements++] = nElements+1;
    elmts[idxElements++] = nElements+2;
    elmts[idxElements++] = nElements+2;
    elmts[idxElements++] = nElements+3;
    elmts[idxElements++] = nElements;
    nElements+=4;
}

void SpriteRenderer::draw(Sprite& sprite) {
    draw(sprite.texture(), sprite.x(), sprite.y(), sprite.width(), sprite.height(), 0.0f, 0.0f,
            1.0f, 1.0f, 0.0f, 0.0f, 0.0f, sprite.textureRegion().width(), sprite.textureRegion().height(), false, false); 
}

void SpriteRenderer::begin(ShaderProgram* shaderProgram) {
    if (!shaderProgram) {
       printf("ERROR: SpriteRenderer::begin(ShaderProgram*) called with a shaderProgram as nullptr.\n"); 
       return;
    }
    shaderProgram->enable();    
    shaderProgram->setUniformMatrix4x4(ShaderProgram::modelViewProjectionAttribute, mdelViewMatrix);
    this->shaderProgram = shaderProgram;
}

void SpriteRenderer::end() {
    if (idx > 0) {
        render();
    }
    shaderProgram->disable();
    shaderProgram = nullptr;
}

void SpriteRenderer::render() {
    if (msh) {
        delete msh;
        msh = nullptr;
    }
    
    if (idx > 0) {
        VertexAttributes vertexAttributes;
        vertexAttributes.addAttribute(VertexAttribute(2,0,VertexAttributes::positionAttribute));
        vertexAttributes.addAttribute(VertexAttribute(2,2,VertexAttributes::textureCoordinatesAttribute));
        msh = new Mesh(vertexAttributes);
        msh->setVertices(idx/(2+2), 2+2, vrtices);
        msh->setElements(idxElements/3, 3, elmts);

        printf("renders %i vertices in %i elements\n",idx/4,idxElements/3);

        lastUsedTexture->bind(0);
        msh->bind(*shaderProgram);
        msh->render();
        msh->unbind();
    }

    deinit();
    init();
}

} // namespace meh 
