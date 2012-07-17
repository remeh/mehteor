#ifndef MEH_IBO_H
#define MEH_IBO_H

#include "GL/glew.h"

namespace meh {

class IBO {
    private:
        GLuint iboId;

        /**
         * True when the state on the GPU isn't the same as the current instance.
         */
        bool drty;

        GLfloat* elems;

        /**
         * Number of elements.
         */
        int sze;

        /**
         * Dimension of elements.
         */
        int dim;

        /**
         * When this IBO is dynamic, we should use GL_DYNAMIC_DRAW instead of GL_STATIC_DRAW
         */
        bool dyn;

    protected:
    public:
        /**
         * Default constructor.
         *
         * @param dynamic whether this IBO is dynamic (elements will regularly change)
         */
        IBO(bool dynamic = false);
        ~IBO();
    
        void setElements(unsigned int size, unsigned int dimension, float* elements);

        /**
         * Binds the IBO.
         */
        void bind();

        /**
         * Unbinds the IBO.
         */
        void unbind();

        /**
         * Returns the number of elements.
         * @return the number of elements.
         */
        const int size() {
            return sze;
        }

        /**
         * Returns the dimension of elements.
         * @return the dimension of elements.
         */
        const int dimension() {
            return dim;
        }
};

} // namespace meh

#endif // MEH_IBO_H
