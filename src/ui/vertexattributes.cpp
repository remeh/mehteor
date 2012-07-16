#include <vector>

#include "ui/vertexattributes.h"
#include "ui/vertexattribute.h"
#include "ui/shaderprogram.h"

using namespace std;

namespace meh {

string VertexAttributes::positionAttribute = "meh_position";
string VertexAttributes::textureCoordinatesAttribute = "meh_texcoord";

VertexAttributes::VertexAttributes() {
}

void VertexAttributes::addAttribute(VertexAttribute attribute) {
    attributes.push_back(attribute);
    totalDim += attribute.dimension();
}

void VertexAttributes::enable(ShaderProgram& shaderProgram) {
    for (auto attribute = attributes.begin(); attribute != attributes.end(); attribute++) {
        shaderProgram.enableVertexAttribute(attribute->name());
        printf("Activated %s\n",attribute->name().c_str());
        shaderProgram.setVertexAttribute(attribute->name(), attribute->dimension(), GL_FLOAT, false);
        printf("Set %s\n",attribute->name().c_str());
    }
}

} // namespace meh
