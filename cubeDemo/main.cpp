#include "EasyOpenGL.h"
#include "CubeDemo.h"

using namespace EasyOpenGL;

int main() {

    Game* game = new Game("Cube Demo");

    GameComponent* cubeDemo = new CubeDemo();
    game->getComponents().push_back(cubeDemo);

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