#include "BSPDrawer.h"

int random(int min, int max)
{
    return (min + max) / 2;
}

Vector2<Container> BSPDrawer::randomSplit(Container c)
{
    Container c1, c2;

    int r = rand() % 2;

    if (r == 0)
    {
        c1 = Container(
            c.x, c.y,
            random(1, c.w), c.h);
        c2 = Container(
            c.x + c1.w, c.y,
            c.w - c1.w, c.h);
    }
    else
    {
        c1 = Container(
            c.x, c.y,
            c.w, random(1, c.h));
        c2 = Container(
            c.x, c.y + c1.h,
            c.w, c.h - c1.h);
    }

    return Vector2<Container>(c1, c2);
}

Tree *BSPDrawer::splitContainer(Container container, int iterations)
{
    Tree *tree = new Tree(container);

    if (iterations > 0)
    {
        Vector2<Container> containers = randomSplit(container);
        tree->lChild = splitContainer(containers.x, iterations - 1);
        tree->rChild = splitContainer(containers.y, iterations - 1);
    }

    return tree;
}

BSPDrawer::BSPDrawer(int iterations)
{
    Container mainContainer = Container(0, 0, CONTAINER_SIZE, CONTAINER_SIZE);
    this->containerTree = splitContainer(mainContainer, iterations);
}

BSPDrawer::~BSPDrawer()
{
    delete containerTree;
}

Vector2<unsigned int> BSPDrawer::windowSize() const
{
    return Vector2<unsigned int>(1280, 720);
}

void BSPDrawer::draw(sf::RenderWindow *window)
{
    std::vector<Container> *v = new std::vector<Container>();

    this->containerTree->getTree(v);

    for (int i = 0; i < v->size(); i++)
    {
        Container container = v->at(i);

        sf::RectangleShape shape = sf::RectangleShape(sf::Vector2f(container.w, container.h));
        shape.setFillColor(sf::Color::Transparent);
        shape.setOutlineColor(sf::Color::Green);
        shape.setOutlineThickness(1.0);
        shape.setPosition(sf::Vector2f(25 + container.x, 25 + container.y));
        window->draw(shape);
    }
}
