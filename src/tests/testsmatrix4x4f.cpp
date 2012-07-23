#include <cstdio>

#include "tests/testsmatrix4x4f.h"
#include "core/matrix4x4.h"

namespace meh {

Matrix4x4<float> TestsMatrix4x4f::newMatrix() {
    Matrix4x4<float> mat;
    mat[0] = 1;
    mat[1] = 2;
    mat[2] = 3;
    mat[3] = 4;
    mat[4] = 5;
    mat[5] = 6;
    mat[6] = 7;
    mat[7] = 8;
    mat[8] = 9;
    mat[9] = 1;
    mat[10] = 2;
    mat[11] = 3;
    mat[12] = 4;
    mat[13] = 5;
    mat[14] = 6;
    mat[15] = 7;
    return mat;
}

bool TestsMatrix4x4f::testLookAtVector3dVector3dVector3d() {
    Matrix4x4<float> mat = newMatrix();
    mat.lookAt(Vector3d<float>(1,2,3), Vector3d<float>(2,3,4), Vector3d<float>(3,4,5));
   
    bool ok = true;
    ok = ok && testFloat(mat[0], 0.4082f);
    ok = ok && testFloat(mat[4],-0.8164f);
    ok = ok && testFloat(mat[8], 0.4082f);
    ok = ok && testFloat(mat[12], 0.0000f);
    ok = ok && testFloat(mat[1],-0.7071f);
    ok = ok && testFloat(mat[5], 0.0000f);
    ok = ok && testFloat(mat[9], 0.7071f);
    ok = ok && testFloat(mat[13],-1.4142f);
    ok = ok && testFloat(mat[2],-0.5773f);
    ok = ok && testFloat(mat[6],-0.5773f);
    ok = ok && testFloat(mat[10],-0.5773f);
    ok = ok && testFloat(mat[14], 3.4641f);
    ok = ok && testFloat(mat[3], 0.0000f);
    ok = ok && testFloat(mat[7], 0.0000f);
    ok = ok && testFloat(mat[11], 0.0000f);
    ok = ok && testFloat(mat[15], 1.0000f);

    return ok;
}

bool TestsMatrix4x4f::testLookAtVector3dVector3d() {
    Matrix4x4<float> mat = newMatrix();
    mat.lookAt(Vector3d<float>(0,1,5), Vector3d<float>(2,5,1));
   
    bool ok = true;
    ok = ok && testFloat(mat[0],-0.9203f);
    ok = ok && testFloat(mat[4], 0.3834f);
    ok = ok && testFloat(mat[8],-0.0766f);
    ok = ok && testFloat(mat[12], 0.0000f);

    ok = ok && testFloat(mat[1], 0.3910f);
    ok = ok && testFloat(mat[5], 0.9024f);
    ok = ok && testFloat(mat[9],-0.1804f);
    ok = ok && testFloat(mat[13], 0.0000f);

    ok = ok && testFloat(mat[2],-0.0000f);
    ok = ok && testFloat(mat[6],-0.1961f);
    ok = ok && testFloat(mat[10],-0.9805f);
    ok = ok && testFloat(mat[14], 0.0000f);

    ok = ok && testFloat(mat[3], 0.0000f);
    ok = ok && testFloat(mat[7], 0.0000f);
    ok = ok && testFloat(mat[11], 0.0000f);
    ok = ok && testFloat(mat[15], 1.0000f);

    return ok;
}

bool TestsMatrix4x4f::testToIdentity() {
    Matrix4x4<float> mat = newMatrix();
    mat.toIdentity();
   
    bool ok = true;
    ok = ok && testFloat(mat[0], 1.0000f);
    ok = ok && testFloat(mat[1], 0.0000f);
    ok = ok && testFloat(mat[2], 0.0000f);
    ok = ok && testFloat(mat[3], 0.0000f);
    ok = ok && testFloat(mat[4], 0.0000f);
    ok = ok && testFloat(mat[5], 1.0000f);
    ok = ok && testFloat(mat[6], 0.0000f);
    ok = ok && testFloat(mat[7], 0.0000f);
    ok = ok && testFloat(mat[8], 0.0000f);
    ok = ok && testFloat(mat[9], 0.0000f);
    ok = ok && testFloat(mat[10], 1.0000f);
    ok = ok && testFloat(mat[11], 0.0000f);
    ok = ok && testFloat(mat[12], 0.0000f);
    ok = ok && testFloat(mat[13], 0.0000f);
    ok = ok && testFloat(mat[14], 0.0000f);
    ok = ok && testFloat(mat[15], 1.0000f);
    return ok;
}

bool TestsMatrix4x4f::testInvert() {
    Matrix4x4<float> mat = newMatrix();
    mat[7] = 1.0f;
    mat.invert();
    bool ok = true;
    ok = ok && testFloat(mat[0],-0.1481f);
    ok = ok && testFloat(mat[1],-0.0000f);
    ok = ok && testFloat(mat[2], 0.1111f);
    ok = ok && testFloat(mat[3], 0.0373f);
    ok = ok && testFloat(mat[4],-1.7513f);
    ok = ok && testFloat(mat[5],-0.1428f);
    ok = ok && testFloat(mat[6],-0.2222f);
    ok = ok && testFloat(mat[7], 1.1164f);
    ok = ok && testFloat(mat[8], 1.6137f);
    ok = ok && testFloat(mat[9], 0.2857f);
    ok = ok && testFloat(mat[10], 0.1111f);
    ok = ok && testFloat(mat[11],-1.0105f);
    ok = ok && testFloat(mat[12],-0.0476f);
    ok = ok && testFloat(mat[13],-0.1428f);
    ok = ok && testFloat(mat[14],-0.0000f);
    ok = ok && testFloat(mat[15], 0.1904f);

    mat.print();
    return ok;
}

bool TestsMatrix4x4f::testDeterminant() {
    Matrix4x4<float> mat = newMatrix();
    if (!testFloat(mat.determinant(), 0.0000f)) {
        return false;
    }

    mat[7] = 1.0f;
    if (!testFloat(mat.determinant(), -189.00f)) {
        return false;
    }

    return true;
}

bool TestsMatrix4x4f::testFloat(float a, float b) {
    float epsilon = 0.05;
    if (fabs(b-a) < epsilon) {
        return true;
    }
    return false;
}

void TestsMatrix4x4f::tests() {
    if (!testLookAtVector3dVector3dVector3d()) {
        printf("testLookAtVector3dVector3dVector3d FAILED!\n");
    } else {
        printf("testLookAtVector3dVector3dVector3d OK!\n");
    }

    if (!testLookAtVector3dVector3d()) {
        printf("testLookAtVector3dVector3d FAILED!\n");
    } else {
        printf("testLookAtVector3dVector3d OK!\n");
    }

    if (!testToIdentity()) {
        printf("testToIdentity FAILED!\n");
    } else {
        printf("testToIdentity OK!\n");
    }

    if (!testDeterminant()) {
        printf("testDeterminant FAILED!\n");
    } else {
        printf("testDeterminant OK!\n");
    }

    if (!testInvert()) {
        printf("testInvert FAILED!\n");
    } else {
        printf("testInvert OK!\n");
    }
}

}
