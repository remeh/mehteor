#ifndef MEH_MATRIX4X4_H
#define MEH_MATRIX4X4_H

#include "core/vector2d.h"

namespace meh {

template<typename T>
class Matrix4x4 {
    public: // static
        const static int M00 = 0;
        const static int M01 = 1;
        const static int M02 = 2;
        const static int M03 = 3;
        const static int M10 = 4;
        const static int M11 = 5;
        const static int M12 = 6;
        const static int M13 = 7;
        const static int M20 = 8;
        const static int M21 = 9;
        const static int M22 = 10;
        const static int M23 = 11;
        const static int M30 = 12;
        const static int M31 = 13;
        const static int M32 = 14;
        const static int M33 = 15;

    private:
        T v[16];

    protected:
    public:
        Matrix4x4() {
            v[M00] = v[M11] = v[M22] = v[M33] = 1;
        }

        /**
         * Sets the specified member of the matrix
         */
        Matrix4x4<T>& set(int indice, T value) {
            v[indice] = value;
        }

        Matrix4x4<T>& toIdentity() {
           v[M00] = 1; v[M01] = 0; v[M02] = 0; v[M03] = 0;
           v[M10] = 0; v[M11] = 1; v[M12] = 0; v[M13] = 0;
           v[M20] = 0; v[M21] = 0; v[M22] = 1; v[M23] = 0;
           v[M30] = 0; v[M31] = 0; v[M32] = 0; v[M33] = 1;
           return *this;
        }

        /**
         * Sets the value of this Matrix4x4 with another one values.
         * @param other the values
         */
        Matrix4x4& set(Matrix4x4<T>& other) {
            v[M00] = other.value(M00); v[M01] = other.value(M01); v[M02] = other.value(M02); v[M03] = other.value(M03);
            v[M10] = other.value(M10); v[M11] = other.value(M11); v[M12] = other.value(M12); v[M13] = other.value(M13);
            v[M20] = other.value(M20); v[M21] = other.value(M21); v[M22] = other.value(M22); v[M23] = other.value(M23);
            v[M30] = other.value(M30); v[M31] = other.value(M31); v[M32] = other.value(M32); v[M33] = other.value(M33);
            return *this;
        }

        T& operator[](int idx) {
            return v[idx];
        }

        /**
        * Multiplies this Matrix4x4 by another one.
        */
        Matrix4x4<T>& mul(Matrix4x4<T>& other) {
            Matrix4x4<T> tmp;
            tmp[M00] = v[M00] * other.value(M00) + v[M01] * other.value(M10) + v[M02] * other.value(M20) + v[M03] * other.value(M30);
            tmp[M01] = v[M00] * other.value(M01) + v[M01] * other.value(M11) + v[M02] * other.value(M21) + v[M03] * other.value(M31);
            tmp[M02] = v[M00] * other.value(M02) + v[M01] * other.value(M12) + v[M02] * other.value(M22) + v[M03] * other.value(M32);
            tmp[M03] = v[M00] * other.value(M03) + v[M01] * other.value(M13) + v[M02] * other.value(M23) + v[M03] * other.value(M33);

            tmp[M10] = v[M10] * other.value(M00) + v[M11] * other.value(M10) + v[M12] * other.value(M20) + v[M13] * other.value(M30);
            tmp[M11] = v[M10] * other.value(M01) + v[M11] * other.value(M11) + v[M12] * other.value(M21) + v[M13] * other.value(M31);
            tmp[M12] = v[M10] * other.value(M02) + v[M11] * other.value(M12) + v[M12] * other.value(M22) + v[M13] * other.value(M32);
            tmp[M13] = v[M10] * other.value(M03) + v[M11] * other.value(M13) + v[M12] * other.value(M23) + v[M13] * other.value(M33);

            tmp[M20] = v[M20] * other.value(M00) + v[M21] * other.value(M10) + v[M22] * other.value(M20) + v[M23] * other.value(M30);
            tmp[M21] = v[M20] * other.value(M01) + v[M21] * other.value(M11) + v[M22] * other.value(M21) + v[M23] * other.value(M31);
            tmp[M22] = v[M20] * other.value(M02) + v[M21] * other.value(M12) + v[M22] * other.value(M22) + v[M23] * other.value(M32);
            tmp[M23] = v[M20] * other.value(M03) + v[M21] * other.value(M13) + v[M22] * other.value(M23) + v[M23] * other.value(M33);

            tmp[M30] = v[M30] * other.value(M00) + v[M31] * other.value(M10) + v[M32] * other.value(M20) + v[M33] * other.value(M30);
            tmp[M31] = v[M30] * other.value(M01) + v[M31] * other.value(M11) + v[M32] * other.value(M21) + v[M33] * other.value(M31);
            tmp[M32] = v[M30] * other.value(M02) + v[M31] * other.value(M12) + v[M32] * other.value(M22) + v[M33] * other.value(M32);
            tmp[M33] = v[M30] * other.value(M03) + v[M31] * other.value(M13) + v[M32] * other.value(M23) + v[M33] * other.value(M33);
            this->set(tmp);
            return *this;
        }

        /**
         * Returns this matrix determinant. Code from LibGDX.
         * @return this matrix determinant.
         */
        T determinant() {
            return (v[M30] * v[M21] * v[M12] * v[M03]
                    - v[M20] * v[M31] * v[M12] * v[M03]
                    - v[M30] * v[M11] * v[M22] * v[M03]
                    + v[M10] * v[M31] * v[M22] * v[M03]
                    + v[M20] * v[M11] * v[M32] * v[M03]
                    - v[M10] * v[M21] * v[M32] * v[M03]
                    - v[M30] * v[M21] * v[M02] * v[M13]
                    + v[M20] * v[M31] * v[M02] * v[M13]
                    + v[M30] * v[M01] * v[M22] * v[M13]
                    - v[M00] * v[M31] * v[M22] * v[M13]
                    - v[M20] * v[M01] * v[M32] * v[M13]
                    + v[M00] * v[M21] * v[M32] * v[M13]
                    + v[M30] * v[M11] * v[M02] * v[M23]
                    - v[M10] * v[M31] * v[M02] * v[M23] 
                    - v[M30] * v[M01] * v[M12] * v[M23]
                    + v[M00] * v[M31] * v[M12] * v[M23]
                    + v[M10] * v[M01] * v[M32] * v[M23]
                    - v[M00] * v[M11] * v[M32] * v[M23]
                    - v[M20] * v[M11] * v[M02] * v[M33]
                    + v[M10] * v[M21] * v[M02] * v[M33]
                    + v[M20] * v[M01] * v[M12] * v[M33]
                    - v[M00] * v[M21] * v[M12] * v[M33]
                    - v[M10] * v[M01] * v[M22] * v[M33]
                    + v[M00] * v[M11] * v[M22] * v[M33]);
        }

        /**
         * Inverts this Matrix if applicable. Code from LibGDX.
         */
        Matrix4x4<T>& invert() {
            Matrix4x4<T> tmp;
            T det = determinant();
            if (det == 0) {
                return *this;
            }
            T invDet = 1.0f/det;
            tmp[M00] = v[M12] * v[M23] * v[M31] - v[M13] * v[M22] * v[M31] + v[M13] * v[M21] * v[M32] - v[M11]
                * v[M23] * v[M32] - v[M12] * v[M21] * v[M33] + v[M11] * v[M22] * v[M33];
            tmp[M01] = v[M03] * v[M22] * v[M31] - v[M02] * v[M23] * v[M31] - v[M03] * v[M21] * v[M32] + v[M01]
                * v[M23] * v[M32] + v[M02] * v[M21] * v[M33] - v[M01] * v[M22] * v[M33];
            tmp[M02] = v[M02] * v[M13] * v[M31] - v[M03] * v[M12] * v[M31] + v[M03] * v[M11] * v[M32] - v[M01]
                * v[M13] * v[M32] - v[M02] * v[M11] * v[M33] + v[M01] * v[M12] * v[M33];
            tmp[M03] = v[M03] * v[M12] * v[M21] - v[M02] * v[M13] * v[M21] - v[M03] * v[M11] * v[M22] + v[M01]
                * v[M13] * v[M22] + v[M02] * v[M11] * v[M23] - v[M01] * v[M12] * v[M23];
            tmp[M10] = v[M13] * v[M22] * v[M30] - v[M12] * v[M23] * v[M30] - v[M13] * v[M20] * v[M32] + v[M10]
                * v[M23] * v[M32] + v[M12] * v[M20] * v[M33] - v[M10] * v[M22] * v[M33];
            tmp[M11] = v[M02] * v[M23] * v[M30] - v[M03] * v[M22] * v[M30] + v[M03] * v[M20] * v[M32] - v[M00]
                * v[M23] * v[M32] - v[M02] * v[M20] * v[M33] + v[M00] * v[M22] * v[M33];
            tmp[M12] = v[M03] * v[M12] * v[M30] - v[M02] * v[M13] * v[M30] - v[M03] * v[M10] * v[M32] + v[M00]
                * v[M13] * v[M32] + v[M02] * v[M10] * v[M33] - v[M00] * v[M12] * v[M33];
            tmp[M13] = v[M02] * v[M13] * v[M20] - v[M03] * v[M12] * v[M20] + v[M03] * v[M10] * v[M22] - v[M00]
                * v[M13] * v[M22] - v[M02] * v[M10] * v[M23] + v[M00] * v[M12] * v[M23];
            tmp[M20] = v[M11] * v[M23] * v[M30] - v[M13] * v[M21] * v[M30] + v[M13] * v[M20] * v[M31] - v[M10]
                * v[M23] * v[M31] - v[M11] * v[M20] * v[M33] + v[M10] * v[M21] * v[M33];
            tmp[M21] = v[M03] * v[M21] * v[M30] - v[M01] * v[M23] * v[M30] - v[M03] * v[M20] * v[M31] + v[M00]
                * v[M23] * v[M31] + v[M01] * v[M20] * v[M33] - v[M00] * v[M21] * v[M33];
            tmp[M22] = v[M01] * v[M13] * v[M30] - v[M03] * v[M11] * v[M30] + v[M03] * v[M10] * v[M31] - v[M00]
                * v[M13] * v[M31] - v[M01] * v[M10] * v[M33] + v[M00] * v[M11] * v[M33];
            tmp[M23] = v[M03] * v[M11] * v[M20] - v[M01] * v[M13] * v[M20] - v[M03] * v[M10] * v[M21] + v[M00]
                * v[M13] * v[M21] + v[M01] * v[M10] * v[M23] - v[M00] * v[M11] * v[M23];
            tmp[M30] = v[M12] * v[M21] * v[M30] - v[M11] * v[M22] * v[M30] - v[M12] * v[M20] * v[M31] + v[M10]
                * v[M22] * v[M31] + v[M11] * v[M20] * v[M32] - v[M10] * v[M21] * v[M32];
            tmp[M31] = v[M01] * v[M22] * v[M30] - v[M02] * v[M21] * v[M30] + v[M02] * v[M20] * v[M31] - v[M00]
                * v[M22] * v[M31] - v[M01] * v[M20] * v[M32] + v[M00] * v[M21] * v[M32];
            tmp[M32] = v[M02] * v[M11] * v[M30] - v[M01] * v[M12] * v[M30] - v[M02] * v[M10] * v[M31] + v[M00]
                * v[M12] * v[M31] + v[M01] * v[M10] * v[M32] - v[M00] * v[M11] * v[M32];
            tmp[M33] = v[M01] * v[M12] * v[M20] - v[M02] * v[M11] * v[M20] + v[M02] * v[M10] * v[M21] - v[M00]
                * v[M12] * v[M21] - v[M01] * v[M10] * v[M22] + v[M00] * v[M11] * v[M22];
            v[M00] = tmp[M00] * invDet;
            v[M01] = tmp[M01] * invDet;
            v[M02] = tmp[M02] * invDet;
            v[M03] = tmp[M03] * invDet;
            v[M10] = tmp[M10] * invDet;
            v[M11] = tmp[M11] * invDet;
            v[M12] = tmp[M12] * invDet;
            v[M13] = tmp[M13] * invDet;
            v[M20] = tmp[M20] * invDet;
            v[M21] = tmp[M21] * invDet;
            v[M22] = tmp[M22] * invDet;
            v[M23] = tmp[M23] * invDet;
            v[M30] = tmp[M30] * invDet;
            v[M31] = tmp[M31] * invDet;
            v[M32] = tmp[M32] * invDet;
            v[M33] = tmp[M33] * invDet;
            return *this;
        }

        /**
         * Returns the value of the specified member.
         * @return the value of the specified member.
         */
        T value(int indice) {
            return v[indice];
        }

};

} // namespace meh

#endif // MEH_MATRIX4X4_H
