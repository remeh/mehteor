#include <vector>

#include "ui/vertexattributes.h"
#include "ui/vertexattribute.h"
#include "ui/shaderprogram.h"

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
        printf("Activated %s\n",attribute->name().c_str());
        // printf("setVertexAttribute %s, dim: %i, offset: %i, totalDim: %i\n",attribute->name().c_str(), attribute->dimension(), attribute->offset(),totalDim);
        shaderProgram.setVertexAttribute(attribute->name(), attribute->dimension(), attribute->offset(), totalDim, GL_FLOAT, false);
        printf("Set %s\n",attribute->name().c_str());
    }
}

} // namespace meh
