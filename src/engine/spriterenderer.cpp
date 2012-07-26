#include "engine/spriterenderer.h"
#include "engine/resourcesmanager.h"
#include "engine/sprite.h"

namespace meh {

SpriteRenderer::SpriteRenderer(ResourcesManager& resourcesManager) :
    rsourcesManager(resourcesManager) {
    VertexAttributes vertexAttributes;
    vertexAttributes.addAttribute(VertexAttribute(3,0,VertexAttributes::positionAttribute));
    vertexAttributes.addAttribute(VertexAttribute(2,3,VertexAttributes::textureCoordinatesAttribute));
    msh = new Mesh(vertexAttributes);
}

SpriteRenderer::~SpriteRenderer() {
    if (msh) {
        delete msh;
        msh = nullptr;
    }
}

void SpriteRenderer::draw(Sprite& sprite, ShaderProgram& shaderProgram) {
    sprite.texture().bind(0);

    GLfloat vertices[] = {
        sprite.rect().x(), sprite.rect().y(), 0.0f, 0.0f, 0.0f,
        sprite.rect().x()+sprite.rect().width(), sprite.rect().y(), 0.0f, 1.0f, 0.0f,
        sprite.rect().x()+sprite.rect().width(), sprite.rect().y()+sprite.rect().height(), 0.0f, 1.0f, 1.0f,
        sprite.rect().x(), sprite.rect().y()+sprite.rect().height(), 0.0f, 0.0f, 1.0f
    };

    GLuint elements[] = {
        0, 1 ,2,
        2, 3, 0
    };

    msh->setVertices(4,5,vertices);
    msh->setElements(2,3,elements);

    msh->bind(shaderProgram);
    msh->render(shaderProgram);
    msh->unbind();
}

void SpriteRenderer::render() {

}

} // namespace meh 
