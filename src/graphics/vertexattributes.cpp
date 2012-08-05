#include <vector>

#include "graphics/vertexattributes.h"
#include "graphics/vertexattribute.h"
#include "graphics/shaderprogram.h"

using namespace std;

namespace meh {

string VertexAttributes::positionAttribute = "meh_position";
string VertexAttributes::textureCoordinatesAttribute = "meh_texcoord";

VertexAttributes::VertexAttributes() :
    totalDim(0) {
}

void VertexAttributes::addAttribute(VertexAttribute attribute) {
    attributes.push_back(attribute);
    totalDim += attribute.dimension();
}

void VertexAttributes::enable(ShaderProgram& shaderProgram) {
    for (auto attribute = attributes.begin(); attribute != attributes.end(); attribute++) {
        shaderProgram.enableVertexAttribute(attribute->name());
        shaderProgram.setVertexAttribute(attribute->name(), attribute->dimension(), attribute->offset(), totalDim, GL_FLOAT, false);
    }
}

} // namespace meh
