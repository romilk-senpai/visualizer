#pragma once

#include <SFML/Graphics.hpp>
#include "../common/vector2/Vector2.h"

class IDrawer
{
public:
    virtual Vector2<unsigned int> windowSize() const = 0;
    virtual void draw(sf::RenderWindow *window) = 0;

    virtual ~IDrawer() {};
};