#include "visualizer/Visualizer.h"
#include "algorithms/bspTrees/BSPDrawer.h"

int main()
{
    srand(time(NULL));

    IDrawer *drawer = new BSPDrawer(4);

    Visualizer visualizer(drawer);

    while (visualizer.running())
    {
        visualizer.update();
        visualizer.render();
    }

    return 0;
}