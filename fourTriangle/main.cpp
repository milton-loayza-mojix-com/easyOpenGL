#include "EasyOpenGL.h"
#include "FourTriangle.h"

using namespace EasyOpenGL;

int main() {

    Game* game = new Game("Four Triangle");
    GameComponent* fourTriangle = new FourTriangle();
    game->getComponents().push_back(fourTriangle);

    try
    {
        game->run();
    }
    catch(GameException ex)
    {
        fprintf(stderr, "%s", ex.whatw());
    }
    return 0;

}