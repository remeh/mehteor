#ifndef MEH_VECTOR3D_H
#define MEH_VECTOR3D_H

#include <cstdio> // printf
#include <cmath>

namespace meh {

template<typename T>
class Vector3d {
    private:
        T _x;
        T _y;
        T _z;

    protected:
    public:
        /**
         * Default consturctor.
         */
        Vector3d() : _x(0), _y(0), _z(0) {}

        /**
         * Default constructor with values.
         */
        Vector3d(T x, T y, T z) : _x(x), _y(y), _z(z) {
        }

        T x() const { return _x; }
        T y() const { return _y; }
        T z() const { return _z; }

        /**
         * Sets the value of x.
         * @param x the new value
         */
        Vector3d<T>& setX(T x) {
            _x = x;
            return *this;
        }

        /**
         * Sets the value of y.
         * @param y the new value
         */
        Vector3d<T>& setY(T y) {
            _y = y;
            return *this;
        }

        /**
         * Sets the value of z.
         * @param z the new value
         */
        Vector3d<T>& setZ(T z) {
            _z = z;
            return *this;
        }

        /**
         * Sets the value of x, y and z.
         * @param x the new value for x
         * @param y the new value for y
         * @param z the new value for z
         */
        Vector3d<T>& setXYZ(T x, T y, T z) {
            _x = x;
            _y = y;
            _z = z;
            return *this;
        }

        /**
         * Adds this vector to another one and returns the result.
         * @param other the other vector
         * @return the result of the addition
         */
        Vector3d<T> operator+(Vector3d<T>& other) {
            return Vector3d<T>(_x+other.x(), _y+other.y(), _z+other.z());
        }

        /**
         * Substracts this vector to another one and returns the result.
         * @param other the other vector
         * @return the result of the substraction 
         */
        Vector3d<T> operator-(Vector3d<T>& other) {
            return Vector3d<T>(_x-other.x(), _y-other.y(), _z-other.z());
        }

        /**
         * Multiplies this vector to another one and returns the result.
         * @param other the other vector
         * @return the result of the multiplication 
         */
        Vector3d<T> operator*(Vector3d<T>& other) {
            return Vector3d<T>(_x*other.x(), _y*other.y(), _z*other.z());
        }

        /**
         * Divides this vector to another one and returns the result.
         * @param other the other vector
         * @return the result of the division
         */
        Vector3d<T> operator/(Vector3d<T>& other) {
            return Vector3d<T>(_x/other.x(), _y/other.y(), _z/other.z());
        }

        /**
         * Adds a value to every members of this vector.
         * @param the value to add.
         * @return the result of the add.
         */
        Vector3d<T> operator+(T v) {
            return Vector3d<T>(_x+v, _y+v, _z+v);
        }

        /**
         * Substracts a value to every members of this vector.
         * @param the value to substract.
         * @return the result of the substraction.
         */
        Vector3d<T> operator-(T v) {
            return Vector3d<T>(_x-v, _y-v, _z-v);
        }

        /**
         * Divides a value to every members of this vector.
         * @param the value to divide.
         * @return the result of the division.
         */
        Vector3d<T> operator/(T v) {
            return Vector3d<T>(_x/v, _y/v, _z/v);
        }

        /**
         * Multiplies a value to every members of this vector.
         * @param the value to multiply.
         * @return the result of the multiplication.
         */
        Vector3d<T> operator*(T v) {
            return Vector3d<T>(_x*v, _y*v, _z*v);
        }

        /**
         * Computes the length of this vector.
         * @return the length of this vector.
         */
        T length() {
            return sqrt(_x*_x + _y*_y + _z*_z);
        }

        /**
         * Normalizes this vector.
         */
        Vector3d<T> normalize() {
            T len = length();
            if (len != 0) {
                _x /= len;
                _y /= len;
                _z /= len;
            }
            return *this;
        }

        /**
         * Computes the distance between this vector and another one and returns the result.
         * @param other the other vector
         * @return the distance between the two vectors
         */
        T distance(Vector3d<T>& other) {
            T dx = other.x() - _x;
            T dy = other.y() - _y;
            T dz = other.z() - _z;
            return sqrt(dx*dx + dy*dy + dz*dz);
        }

        /**
         * Computes the distance between this vector and another one and returns the squared result.
         * @param other the other vector
         * @return the squared distance between the two vectors
         */
        T squareDistance(Vector3d<T>& other) {
            T dx = other.x() - _x;
            T dy = other.y() - _y;
            T dz = other.z() - _z;
            return dx*dx + dy*dy + dz*dz;
        }

        /**
         * Dot product between this vector and another one.
         * @param other the other vector
         * @return the result of the dot product
         */
        T dot(Vector3d<T>& other) {
            return x*other.x() + y*other.y() + z*other.z();
        }

        /**
         * Apply to this vector the result of the cross product between
         * it and the other vector.
         * @param other the other vector.
         * @return this vector after the cross product.
         */
        Vector3d<T>& crossProduct(Vector3d<T>& other) {
            float x = _y*other.z() - _z*other.y();
            float y = _z*other.x() - _x*other.z();
            float z = _x*other.y() - _y*other.x();
            setXYZ(x,y,z);
            return *this;
        }

        // XXX to remove
        void print() {
            printf("[%f,%f,%f]\n",x(),y(),z());
        }
};

} // namespace meh

#endif // MEH_VECTOR3D_H
