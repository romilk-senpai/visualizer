#pragma once

template <typename T>

struct Vector2
{
public:
    T x;
    T y;

    Vector2(T x, T y)
        : x(x), y(y) {}
};