#pragma once

#include "../../drawer/IDrawer.h"
#include "../../common/container/Container.h"
#include "../../common/tree/Tree.h"
#include <iostream>
#include "vector"

typedef TreeNode<Container> Tree;

class BSPDrawer : public IDrawer
{
private:
    Tree *containerTree;
    Vector2<Container> randomSplit(Container c);
    Tree *splitContainer(Container container, int iterations);

public:
    const unsigned int CONTAINER_SIZE = 500;

    BSPDrawer(int iterations);
    ~BSPDrawer();

    Vector2<unsigned int> windowSize() const override;
    void draw(sf::RenderWindow *window) override;
};