#ifndef MEH_VECTOR4D_H
#define MEH_VECTOR4D_H

#include <cstdio> // printf
#include <cmath>

namespace meh {

template<typename T>
class Vector4d {
    private:
        T _x;
        T _y;
        T _z;
        T _i;

    protected:
    public:
        /**
         * Default consturctor.
         */
        Vector4d() : _x(0), _y(0), _z(0), _i(1) {}

        /**
         * Default constructor with values.
         */
        Vector4d(T x, T y, T z, T i) : _x(x), _y(y), _z(z), _i(i) {
        }

        T x() const { return _x; }
        T y() const { return _y; }
        T z() const { return _z; }
        T i() const { return _i; }

        /**
         * Sets the value of x.
         * @param x the new value
         */
        Vector4d<T>& setX(T x) {
            _x = x;
            return *this;
        }

        /**
         * Sets the value of y.
         * @param y the new value
         */
        Vector4d<T>& setY(T y) {
            _y = y;
            return *this;
        }

        /**
         * Sets the value of z.
         * @param z the new value
         */
        Vector4d<T>& setZ(T z) {
            _z = z;
            return *this;
        }

        /**
         * Sets the value of i.
         * @param i the new value
         */
        Vector4d<T>& setI(T i) {
            _i = i;
            return *this;
        }

        /**
         * Sets the value of x, y and z.
         * @param x the new value for x
         * @param y the new value for y
         * @param z the new value for z
         * @param i the new value for i
         */
        Vector4d<T>& setXYZI(T x, T y, T z, T i) {
            _x = x;
            _y = y;
            _z = z;
            _i = i;
            return *this;
        }

        Vector4d<T>& set(Vector4d<T> tint)
        {
            _x = tint.x();
            _y = tint.y();
            _z = tint.z();
            _i = tint.i();
            return *this;
        }

        // XXX to remove
        void print() {
            printf("[%f,%f,%f,%f]\n",x(),y(),z(),i());
        }
};

} // namespace meh

#endif // MEH_VECTOR4D_H

