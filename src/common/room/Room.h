#pragma once

#include "../container/Container.h"
#include "../random/Random.h"

struct Room
{
public:
    int x;
    int y;
    int w;
    int h;

    Room();
    Room(int x, int y, int w, int h);
    Room(Container c);
};