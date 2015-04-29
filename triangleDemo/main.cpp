#include "EasyOpenGL.h"
#include "ColoredTriangleDemo.h"

using namespace EasyOpenGL;

int main() {

    Game* game = new Game("Triangle Demo");

    GameComponent* coloredTriangleDemo = new ColoredTriangleDemo();
    game->getComponents().push_back(coloredTriangleDemo);

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