#include <string>

#include "ui/vertexattribute.h"
#include "ui/shaderprogram.h"

using namespace std;

namespace meh {

VertexAttribute::VertexAttribute(int dimension, string name) :
    nme(name),
    dim(dimension) {
}

} // namespace meh

