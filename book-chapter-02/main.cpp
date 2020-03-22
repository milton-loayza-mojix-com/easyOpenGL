#include "Chapter02.h"

using namespace EasyOpenGL;

int main() {

    Game *game = new Game("Chapter 02");
    Chapter02 *chapter02 = new Chapter02();
    game->getComponents().push_back(chapter02);

//    game->setScreenBackgroundColor(&ColorHelper::Red[0]);
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