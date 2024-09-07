#include "Visualizer.h"

void Visualizer::init()
{
}

void Visualizer::createWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(drawer->windowSize().x, drawer->windowSize().y), "Visualizer");
    this->window->setFramerateLimit(24);
}

Visualizer::Visualizer(IDrawer *drawer)
    : drawer(drawer)
{
    this->init();
    this->createWindow();
}

Visualizer::~Visualizer()
{
    delete this->drawer;
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
