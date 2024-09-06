#pragma once

#include <SFML/Graphics.hpp>
#include "../drawer/IDrawer.h"

class Visualizer
{
private:
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event event;
    IDrawer* drawer;

    void init();
    void createWindow();
    void pollEvents();
public:
    Visualizer(IDrawer* drawer);
    ~Visualizer();

    const bool running() const;
    
    void update();
    void render();
};