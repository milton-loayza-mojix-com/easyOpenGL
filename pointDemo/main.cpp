#include "EasyOpenGL.h"
#include "PointDemo.h"

using namespace EasyOpenGL;

int main() {

    Game* game = new Game("Point Demo");

    PointDemo* pointDemo = new PointDemo();
    game->getComponents().push_back(pointDemo);

    try
    {
        game->run();
    }
    catch (GameException &ex)
    {
        fprintf(stderr,"%s", ex.whatw());
    }

    return 0;
}