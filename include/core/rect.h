#ifndef MEH_RECT_H
#define MEH_RECT_H

#include "core/vector2d.h"

namespace meh {

template<typename T>
class Rect {
    private:
        Vector2d<T> tl;
        Vector2d<T> br;
    protected:
    public:
        Rect() : tl(0,0), br(0,0) { }
        Rect(T minX, T minY, T width, T height) : tl(minX,minY) {
            br.setXY(width, height);
        }
        Rect(Vector2d<T>& size, Vector2d<T>& position) {
            set(size,position);
        }

        void set(T minX, T minY, T width, T height) {
            tl.setXY(minX,minY);
            br.setXY(width,height);
        }

        void set(Vector2d<T>& size, Vector2d<T>& position) {
            tl = size;
            br = position;
        }

        void setPosition(T x, T y) {
            tl.setXY(x,y);
        }

        void setSize(T x, T y) {
            br.setXY(x,y);
        }

        Vector2d<T>& position() {
            return tl;
        }

        Vector2d<T>& size() {
            return br;
        }

        T x() {
            return tl.x();
        }

        T y() {
            return tl.y();
        }

        T width() {
            return br.x();
        }

        T height() {
            return br.y();
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
};

}

#endif // MEH_RECT_H
