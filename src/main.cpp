#include "bn_core.h"

#include "title_screen.h"

#include "bn_music_items.h"
int main()
{

    bn::core::init();
    while (1)
    {
        Game::title_screen();
        bn::core::update();
    }
}
