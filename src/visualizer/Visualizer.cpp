#include "Visualizer.h"

void Visualizer::init()
{
}

void Visualizer::createWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1280, 720), "roguelike");
    this->videoMode.width = drawer->windowSize().x;
    this->videoMode.height = drawer->windowSize().y;
    this->window->setFramerateLimit(24);
}

Visualizer::Visualizer(IDrawer* drawer)
{
    this->drawer = drawer;
    this->init();
    this->createWindow();
}

Visualizer::~Visualizer()
{
    delete this->window;
}

const bool Visualizer::running() const
{
    return this->window->isOpen();
}

void Visualizer::pollEvents()
{
    while (this->window->pollEvent(this->event))
    {
        switch (this->event.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
                this->window->close();
        default:
            break;
        }
    }
}

void Visualizer::update()
{
    this->pollEvents();
}

void Visualizer::render()
{
    this->window->clear();

    drawer->draw(this->window);

    this->window->display();
}
