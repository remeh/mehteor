#include "GL/glew.h"
#include "mehteor.h"

#include "tests/testsmatrix4x4f.h"

using namespace meh;

int main(int argc, char* argv[]) {
    System::init();

    TestsMatrix4x4f testMatrix;
    testMatrix.tests();

    System::deinit();
}
