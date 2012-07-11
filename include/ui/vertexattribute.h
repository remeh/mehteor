#ifndef MEH_VERTEXATTRIBUTE_H
#define MEH_VERTEXATTRIBUTE_H

#include <string>
#include <list>
#include <SDL/SDL.h>
#include "GL/glew.h"

using namespace std;

namespace meh {

class VertexAttribute {
        string nme;
        int dim;
    private:
    protected:
    public:
        VertexAttribute(int dimension, string name);

        int dimension() {
            return dim;
        }
        string name() {
            return nme;
        }
};

}

#endif // MEH_VERTEXATTRIBUTE_H

