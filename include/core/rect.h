#ifndef MEH_RECT_H
#define MEH_RECT_H

#include "core/vector2d.h"

namespace meh {

template<typename T>
class Rect {
    private:
        Vector2d<T> pos;
        Vector2d<T> sze;

    protected:
    public:
        Rect() : pos(0,0), sze(0,0) { }

        Rect(T x, T y, T width, T height) : pos(x,y), sze(width, height) {
        }

        Rect(Vector2d<T>& position, Vector2d<T>& size) {
            set(position, size);
        }

        void set(T x, T y, T width, T height) {
            pos.setXY(x,y);
            sze.setXY(width,height);
        }

        void set(Vector2d<T>& position, Vector2d<T>& size) {
            pos = position;
            sze = size;
        }

        void set(Rect<T>& rect)
        {
            pos = rect.position();
            sze = rect.size();
        }

        void setPosition(T x, T y) {
            pos.setXY(x,y);
        }

        void setSize(T width, T height) {
            sze.setXY(width, height);
        }

        Vector2d<T>& position() {
            return pos;
        }

        Vector2d<T>& size() {
            return sze;
        }

        T x() {
            return pos.x();
        }

        T y() {
            return pos.y();
        }

        T width() {
            return sze.x();
        }

        T height() {
            return sze.y();
        }

        bool intersects(Rect& r) {
            if (position().x() > r.size().x()+r.position().x() ||
                size().x()+position().x() < r.position().x() ||
                position().y() > r.size().y()+r.position().y() ||
                size().y()+position().y() < r.position().y()) {
                return false;
            } else {
                return true;
            }
        }

        bool touches(Vector2d<T>& v) {
            if (position().x() > v.x() ||
                size().x()+position().x() < v.x() ||
                position().y() > v.y() ||
                size().y()+position().y() < v.y()) {
                return false;
            } else {
                return true;
            }
        }
};

}

#endif // MEH_RECT_H
