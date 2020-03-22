#include "Square.h"

using namespace EasyOpenGL;

int main() {

    Game *game = new Game("Examples 2D");
    GameComponent* square = new Square();
    game->getComponents().push_back(square);

    try
    {
        game->run();
    }
    catch (GameException ex)
    {
        fprintf(stderr, "%s", ex.whatw());
    }
    return 0;
}

