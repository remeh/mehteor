#ifndef MEH_QUATERNION_H
#define MEH_QUATERNION_H

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#ifndef M_PIOVER180
#define M_PIOVER180 0.017453292519943295
#endif

#include <iostream>
#include <cmath>
#include "vector2d.h" 

namespace meh
{

/**
 * 	A simple quaternion implementation.
 *
 * 	The quaternion can be used to apply a rotation on vectors.
 */
template<typename T>
class Quaternion
{
    private:
        /**
         * Coordinates of the quaternion
         */
        T x,y,z,w;

    public:
        Quaternion() : x(0), y(0), z(0), w(1) {};

        Quaternion(const Vector2d<T>& vec, T nz, T nw) : x(vec.x()), y(vec.y()), z(nz), w(nw) {};

        Quaternion(const Vector3d<T>& vec, T nw) : x(vec.x()), y(vec.y()), z(vec.z()), w(nw) {};

        Quaternion(T nx, T ny, T nz, T nw) : x(nx), y (ny), z(nz), w(nw) {};

        /**
         * Set the values of the quaternion
         */
        void
        set(T nx, T ny, T nz, T nw)
        {
            x = nx; y = ny; z = nz; w = nw;
        }

        /**
         * Return the length of the quaternion
         */
        T length()
        {
            return sqrt(x*x + y*y + z*z + w*w);
        }

        /**
         * Normalize the quaternion
         */
        void normalize()
        {
            T len = length();
            x /= len;
            y /= len;
            z /= len;
            x /= len;
        }

        /**
         * Return the conjuguate of the quaternion
         */
        Quaternion<T> conjuguate()
        {
            return Quaternion<T>(-x,-y,-z,w);
        }

        /**
         * Setter from a vector
         */
        Quaternion<T>&
        operator=(const Vector3d<T>& v)
        {
            x = v.x();
            y = v.y();
            z = v.z();
            w = 0;
            return *this;
        }
        
        /**
         * Quaternion multiplication
         */
        Quaternion<T>& operator*(const Quaternion<T>& q) {
            w = this->w*q.w - this->x*q.x - this->y*q.y - this->z*q.z;
            x = this->w*q.x + this->x*q.w + this->y*q.z - this->z*q.y;
            y = this->w*q.y - this->x*q.z + this->y*q.w + this->z*q.x;
            z = this->w*q.z + this->x*q.y - this->y*q.x + this->z*q.w;
            return *this;
        }

        /**
         * Apply a q-rotation on a vector
         */
        Vector3d<T>& operator*(const Vector3d<T>& vec) {
            Vector3d<T> vn = vec;
            vn.normalize();

            Quaternion<T> vecQ;
            vecQ.x = vn.x;
            vecQ.y = vn.y;
            vecQ.z = vn.z;
            vecQ.w = 0.0f;

            Quaternion<T> res = vecQ * conjuguate();
            res = *this * res;

            return (Vector3d<T>(res.x, res.y, res.z));
        }

        /**
         * To init a quaternion.
         * This quaternion represent a rotation of 'degree' around the axis 'axis'
         *
         * \param axis : the axis around which the rotation is computed
         * \param degree : the degree of rotation
         */
        void fromAxis(const Vector3d<T>& axis, float degree) {
            float angle = degree*M_PIOVER180;

            float angleOverTwo = angle*0.5;
            float fSin = sin(angleOverTwo);
                    
            w = cos(angleOverTwo);
            x = (axis.x()*fSin);
            y = (axis.y()*fSin);
            z = (axis.z()*fSin);
        }

        /**
         * Reset the quaternion to the identity matrix
         */
        void toIdentity() {
            x = y = z = 0;
            w = 1;
        }

        /**
         * Writing in an output stream
        */
        inline friend std::ostream& operator <<( std::ostream& out, const Quaternion<T>& q ) {
            out << "[" << q.x << ", " << q.y << ", " << q.z << ", " << q.w << "]";
            return out;
        }
};
} // end of namespace meh

#endif // MEH_QUATERNION_H
