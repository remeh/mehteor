#ifndef MEH_TEST_MATRIX4X4_H
#define MEH_TEST_MATRIX4X4_H

#include "core/matrix4x4.h"

namespace meh {

class TestsMatrix4x4f {
    private:
    protected:
    public:
        TestsMatrix4x4f() {}; 
       
        Matrix4x4<float> newMatrix();

        bool testLookAtVector3dVector3dVector3d();
        bool testLookAtVector3dVector3d();
        bool testToIdentity();
        bool testDeterminant();
        bool testInvert();
        bool testFloat(float a, float b);

        void tests();
};

}

#endif // MEH_TEST_MATRIX4X4_H
