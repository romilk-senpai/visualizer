#pragma once

#include <SFML/Graphics.hpp>
#include "../common/vector2Int/Vector2Int.h"

class IDrawer
{
public:
    virtual Vector2Int windowSize() = 0;
    virtual void draw(sf::RenderWindow *window) = 0;
 
    virtual ~IDrawer() {};
};