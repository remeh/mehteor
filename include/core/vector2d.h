#ifndef MEH_VECTOR2D_H
#define MEH_VECTOR2D_H

#include <cmath>

namespace meh {

template<typename T>
class Vector2d {
    private:
        T _x;
        T _y;
    protected:
    public:
        /**
         * Default consturctor.
         */
        Vector2d() : _x(0), _y(0) {}

        /**
         * Default constructor with values.
         */
        Vector2d(T x, T y) : _x(x), _y(y) { 
        }

        T x() const { return _x; }
        T y() const { return _y; }

        /**
         * Sets the value of x.
         * @param x the new value
         */
        void setX(T x) {
            _x = x;
        }

        /**
         * Sets the value of y.
         * @param y the new value
         */
        void setY(T y) {
            _y = y;
        }

        /**
         * Sets the value of x and y.
         * @param x the new value for x
         * @param y the new value for y
         */
        void setXY(T x, T y) {
            _x = x;
            _y = y;
        }

        /**
         * Adds this vector to another one and returns the result.
         * @param other the other vector
         * @return the result of the addition
         */
        Vector2d<T> operator+(Vector2d<T>& other) {
            return Vector2d<T>(_x+other.x(), _y+other.y());
        }

        /**
         * Substracts this vector to another one and returns the result.
         * @param other the other vector
         * @return the result of the substraction 
         */
        Vector2d<T> operator-(Vector2d<T>& other) {
            return Vector2d<T>(_x-other.x(), _y-other.y());
        }

        /**
         * Multiplies this vector to another one and returns the result.
         * @param other the other vector
         * @return the result of the multiplication 
         */
        Vector2d<T> operator*(Vector2d<T>& other) {
            return Vector2d<T>(_x*other.x(), _y*other.y());
        }

        /**
         * Divides this vector to another one and returns the result.
         * @param other the other vector
         * @return the result of the division
         */
        Vector2d<T> operator/(Vector2d<T>& other) {
            return Vector2d<T>(_x/other.x(), _y/other.y());
        }

        /**
         * Computes the length of this vector.
         * @return the length of this vector.
         */
        T length() {
            return sqrt(_x*_x + _y*_y);
        }

        /**
         * Normalizes this vector.
         */
        void normalize() {
            T len = length();
            if (len != 0) {
                _x /= len;
                _y /= len;
            }
        }

        /**
         * Computes the distance between this vector and another one and returns the result.
         * @param other the other vector
         * @return the distance between the two vectors
         */
        T distance(Vector2d<T>& other) {
            T dx = other.x() - _x;
            T dy = other.y() - _y;
            return sqrt(dx*dx + dy*dy);
        }

        /**
         * Computes the distance between this vector and another one and returns the squared result.
         * @param other the other vector
         * @return the squared distance between the two vectors
         */
        T squareDistance(Vector2d<T>& other) {
            T dx = other.x() - _x;
            T dy = other.y() - _y;
            return dx*dx + dy*dy;
        }

        /**
         * Dot product between this vector and another one.
         * @param other the other vector
         * @return the result of the dot product
         */
        T dot(Vector2d<T>& other) {
            return x*other.x() + y+other.y();
        }
};

} // namespace meh

#endif // MEH_VECTOR2D_H
