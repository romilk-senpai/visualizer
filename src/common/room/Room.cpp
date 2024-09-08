#include "Room.h"

Room::Room()
    : x(0), y(0), w(0), h(0) {}

Room::Room(int x, int y, int w, int h)
    : x(x), y(y), w(w), h(h) {}

Room::Room(Container container)
{
    this->x = container.x + random(0, container.w / 3);
    this->y = container.y + random(0, container.h / 3);
    this->w = container.w - (this->x - container.x);
    this->h = container.h - (this->y - container.y);
    this->w -= random(0, this->w / 3);
    this->h -= random(0, this->h / 3);
}
