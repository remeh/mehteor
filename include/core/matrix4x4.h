#ifndef MEH_MATRIX4X4_H
#define MEH_MATRIX4X4_H

#include <cstdio> // printf
#include "core/vector2d.h"
#include "core/vector3d.h"

namespace meh {

template<typename T>
class Matrix4x4 {
    public: // static
        const static int M00 = 0;
        const static int M10 = 1;
        const static int M20 = 2;
        const static int M30 = 3;
        const static int M01 = 4;
        const static int M11 = 5;
        const static int M21 = 6;
        const static int M31 = 7;
        const static int M02 = 8;
        const static int M12 = 9;
        const static int M22 = 10;
        const static int M32 = 11;
        const static int M03 = 12;
        const static int M13 = 13;
        const static int M23 = 14;
        const static int M33 = 15;

    private:
        T v[16];

    protected:
    public:
        Matrix4x4() {
            toIdentity();
        }

        /**
         * Sets the specified member of the matrix
         */
        Matrix4x4<T>& set(int indice, T value) {
            v[indice] = value;
        }

        T* values() {
            return v;
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
        Matrix4x4<T> operator*(Matrix4x4<T>& other) {
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
            return tmp;
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
         * Sets the matrix to an orthographic projection.
         */
        Matrix4x4<T>& toOrtho(T left, T right, T bottom, T top, T near, T far) {
            toIdentity();
            T xOrth = 2 / (right-left);
            T yOrth = 2 / (top-bottom);
            T zOrth = -2 / (far-near);
            float tx = -(right+left)/(right-left);
            float ty = -(top+bottom)/(top-bottom);
            float tz = -(far+near)/(far-near);

            v[M00] = xOrth;
            v[M10] = 0;
            v[M20] = 0;
            v[M30] = 0.0f;
            v[M01] = 0;
            v[M11] = yOrth;
            v[M21] = 0;
            v[M31] = 0.0f;
            v[M02] = 0;
            v[M12] = 0;
            v[M22] = zOrth;
            v[M32] = 0.0f;
            v[M03] = tx;
            v[M13] = ty;
            v[M23] = tz;
            v[M33] = 1.0f;

            return *this;
        }

        /**
         * Sets the matrix to an orthographic projection with the origin at x,y seeing width and height.
         * The near plane is set to 0 and the far plane to 1.
         */
        Matrix4x4<T>& toOrtho2D(T x, T y, T width, T height) {
            toOrtho(x, x+width, y, y+height, 0, 1);
            return *this;
        }

        /**
         * Sets this matrix to a translation matrix.
         * @param vector the translation vector.
         * @return this matrix set to a translation matrix.
         */
        Matrix4x4<T>& toTranslation(Vector3d<T>& vector) {
            toIdentity();
            v[M03] = vector.x();
            v[M13] = vector.y();
            v[M23] = vector.z();
            return *this;
        }

        Matrix4x4<T>& lookAt(Vector3d<T> position, Vector3d<T> target, Vector3d<T> upVector) {
            Vector3d<T> tmp(target.x(), target.y(), target.z());
            tmp = tmp - position;

            lookAt(tmp,upVector);

            Matrix4x4<T> mat;
            Vector3d<T> posTmp(position.x(),position.y(),position.z());
            posTmp = posTmp*-1.0f;
            mat.toTranslation(posTmp);

            *this = (*this)*mat;

            return *this;
        }

        Matrix4x4<T>& lookAt(Vector3d<T> direction, Vector3d<T> up) {
            Vector3d<T> vecZ(direction.x(), direction.y(), direction.z());
            vecZ.normalize();

            Vector3d<T> vecX(direction.x(), direction.y(), direction.z());
            vecX = vecX.normalize();
            vecX.crossProduct(up);
            vecX = vecX.normalize();

            Vector3d<T> vecY(vecX.x(),vecX.y(),vecX.z());
            vecY = vecY.crossProduct(vecZ).normalize();

            toIdentity();

            v[M00] = vecX.x();
            v[M01] = vecX.y();
            v[M02] = vecX.z();
            v[M10] = vecY.x();
            v[M11] = vecY.y();
            v[M12] = vecY.z();
            v[M20] = -vecZ.x();
            v[M21] = -vecZ.y();
            v[M22] = -vecZ.z();

            return *this;
        }

        /**
         * Returns the value of the specified member.
         * @return the value of the specified member.
         */
        T value(int indice) {
            return v[indice];
        }

        // XXX to remove
        void print() {
            printf("%f %f %f %f\n",v[M00], v[M01], v[M02], v[M03]);
            printf("%f %f %f %f\n",v[M10], v[M11], v[M12], v[M13]);
            printf("%f %f %f %f\n",v[M20], v[M21], v[M22], v[M23]);
            printf("%f %f %f %f\n",v[M30], v[M31], v[M32], v[M33]);
        }
};

} // namespace meh

#endif // MEH_MATRIX4X4_H
