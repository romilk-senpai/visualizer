#pragma once

#include <iostream>
#include <math.h>
#include <vector>
#include "../../drawer/IDrawer.h"
#include "../../common/container/Container.h"
#include "../../common/tree/Tree.h"
#include "../../common/room/Room.h"

typedef TreeNode<Container> Tree;

class BSPDrawer : public IDrawer
{
private:
    const unsigned int CONTAINER_SIZE = 500;
    const bool DISCARD_BY_RATIO = true;
    const double H_RATIO = 0.45;
    const double W_RATIO = 0.45;

    Tree *containerTree;
    std::vector<Room> *rooms;

    Vector2<Container> randomSplit(Container c);
    Tree *splitContainer(Container container, int iterations);
    void addIteration(Tree *tree);
    void draw(sf::RenderWindow *window, Tree *tree);

public:
    BSPDrawer();
    ~BSPDrawer();

    void createTree(int iterations);
    void addIteration();
    void next();

    Vector2<unsigned int> windowSize() const override;
    void draw(sf::RenderWindow *window) override;
};