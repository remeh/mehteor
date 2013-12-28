#include <string>

#include "graphics/vertexattribute.h"
#include "graphics/shaderprogram.h"

using namespace std;

namespace meh
{

VertexAttribute::VertexAttribute(int dimension, int offset, string name) :
    nme(name),
    dim(dimension),
    off(offset)
{
}

} // namespace meh

