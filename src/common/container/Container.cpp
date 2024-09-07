#include "Container.h"

Container::Container()
    : x(0), y(0), w(0), h(0) {}

Container::Container(int x, int y, int w, int h)
    : x(x), y(y), w(w), h(h) {}

Vector2<double> Container::getCenter() const
{
    return Vector2<double>(
        this->x + (this->w / 2.0),
        this->y + (this->h / 2.0));
}
