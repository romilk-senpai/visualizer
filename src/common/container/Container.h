#pragma once

#include "../vector2/Vector2.h"

struct Container
{
public:
    int x;
    int y;
    int w;
    int h;

    Container();
    Container(int x, int y, int w, int h);

    Vector2<double> getCenter() const;
};