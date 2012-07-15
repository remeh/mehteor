/*
 *      quaternion.h
 *      
 *      Copyright 2009 Remy Mathieu <remeh@remeh.fr>
 *      
 */

/**
 * \file
 * 	quaternion.h
 * \brief
 * 	A simple quaternion implementation.
 * 	The quaternion can be used to apply a rotation on a vector
 * \author
 * 	Remy Mathieu
 * \version
 * 	0.1
 * \date
 * 	14 mai 2009
 */

#ifndef MEH_QUATERNION_H
#define MEH_QUATERNION_H

#include <iostream>
#include <cmath>
#include "vector2d.h" 

namespace meh
{
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
        Quaternion<T> getConjuguate()
        {
            return Quaternion<T>(-x,-y,-z,w);
        }

        /**
         * Setter from a vector
         */
        Quaternion<T>
        operator=(const Vector<T>& v)
        {
            Quaternion<T> tmp;
            tmp.x = v.x;
            tmp.y = v.y;
            tmp.z = v.z;
            tmp.w = 0;
            return tmp;
        }
        
        /**
         * Quaternion multiplication
         */
        Quaternion<T> operator*(const Quaternion<T>& q) {
            Quaternion<T> tmp;
            tmp.w = this->w*q.w - this->x*q.x - this->y*q.y - this->z*q.z;
            tmp.x = this->w*q.x + this->x*q.w + this->y*q.z - this->z*q.y;
            tmp.y = this->w*q.y - this->x*q.z + this->y*q.w + this->z*q.x;
            tmp.z = this->w*q.z + this->x*q.y - this->y*q.x + this->z*q.w;
            return tmp;
        }

        /**
         * Apply a q-rotation on a vector
         */
        Vector<T> operator*(const Vector<T>& vec) {
            Vector<T> vn = vec;
            vn.normalize();

            Quaternion<T> vecQ;
            vecQ.x = vn.x;
            vecQ.y = vn.y;
            vecQ.z = vn.z;
            vecQ.w = 0.0f;

            Quaternion<T> res = vecQ * getConjuguate();
            res = *this * res;

            return (Vector<T>(res.x, res.y, res.z));
        }

        /**
         * To init a quaternion.
         * This quaternion represent a rotation of 'degree' around the axis 'axis'
         *
         * \param axis : the axis around which the rotation is computed
         * \param degree : the degree of rotation
         */
        void
        fromAxis(const Vector<T>& axis, float degree) {
            float angle = degree*M_PIOVER180;

            float angleOverTwo = angle*0.5;
            float fSin = sin(angleOverTwo);
                    
            w = cos(angleOverTwo);
            x = (axis.x*fSin);
            y = (axis.y*fSin);
            z = (axis.z*fSin);
        }

        /**
         * Reset the quaternion to the identity matrix
         */
        void identity() {
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
