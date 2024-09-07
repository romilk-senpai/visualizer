#include "visualizer/Visualizer.h"
#include "algorithms/bspTrees/BSPDrawer.h"

int main()
{
    srand(time(NULL));

    BSPDrawer *drawer = new BSPDrawer();

    Visualizer visualizer(drawer);

    drawer->createTree(1);

    while (visualizer.running())
    {
        visualizer.update();
        visualizer.render();
    }

    return 0;
}