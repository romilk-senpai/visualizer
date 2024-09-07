#include "BSPDrawer.h"

int random(int min, int max)
{
    int r = floor(((double)rand() / RAND_MAX) * (max - min + 1) + min);
    return r;
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

        if (DISCARD_BY_RATIO)
        {
            double r1WRatio = (double)c1.w / c1.h;
            double c2WRatio = (double)c2.w / c2.h;

            if (r1WRatio < W_RATIO || c2WRatio < W_RATIO)
            {
                return randomSplit(c);
            }
        }
    }
    else
    {
        c1 = Container(
            c.x, c.y,
            c.w, random(1, c.h));
        c2 = Container(
            c.x, c.y + c1.h,
            c.w, c.h - c1.h);

        if (DISCARD_BY_RATIO)
        {
            double r1HRatio = (double)c1.h / c1.w;
            double c2HRatio = (double)c2.h / c2.w;

            if (r1HRatio < H_RATIO || c2HRatio < H_RATIO)
            {
                return randomSplit(c);
            }
        }
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

void BSPDrawer::addIteration(Tree *tree)
{
    if (tree->rChild == nullptr && tree->rChild == nullptr)
    {
        Vector2<Container> containers = this->randomSplit(tree->leaf);
        tree->lChild = splitContainer(containers.x, 0);
        tree->rChild = splitContainer(containers.y, 0);
    }
    else
    {
        addIteration(tree->lChild);
        addIteration(tree->rChild);
    }
}

BSPDrawer::BSPDrawer()
{
}

BSPDrawer::~BSPDrawer()
{
    delete containerTree;
}

void BSPDrawer::createTree(int iterations)
{
    if (containerTree != nullptr)
    {
        delete containerTree;
    }

    Container mainContainer = Container(0, 0, CONTAINER_SIZE, CONTAINER_SIZE);
    this->containerTree = splitContainer(mainContainer, iterations);
}

void BSPDrawer::addIteration()
{
    if (containerTree != nullptr)
    {
        this->addIteration(containerTree);
    }
}

void BSPDrawer::next()
{
    addIteration();
}

Vector2<unsigned int> BSPDrawer::windowSize() const
{
    return Vector2<unsigned int>(50 + CONTAINER_SIZE, 50 + CONTAINER_SIZE);
}

void BSPDrawer::draw(sf::RenderWindow *window, Tree *tree)
{
    auto container = tree->leaf;

    sf::RectangleShape shape = sf::RectangleShape(sf::Vector2f(container.w, container.h));
    shape.setFillColor(sf::Color::Transparent);
    shape.setOutlineColor(sf::Color::Green);
    shape.setOutlineThickness(1.0);
    shape.setPosition(sf::Vector2f(25 + container.x, 25 + container.y));
    window->draw(shape);

    if (tree->lChild != nullptr) {
        draw(window, tree->lChild);
    }

    if (tree->rChild != nullptr) {
        draw(window, tree->rChild);
    }
}

void BSPDrawer::draw(sf::RenderWindow *window)
{
    if (containerTree == nullptr)
    {
        return;
    }

    this->draw(window, containerTree);
}
