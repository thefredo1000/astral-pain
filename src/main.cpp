#include "bn_core.h"
#include "bn_sprite_animate_actions.h"
#include "bn_sprite_ptr.h"
#include "bn_span.h"

#include "bn_sprite_items_ball.h"
#include "bn_music_items.h"

int main()
{
    bn::core::init();
    bn::music_items::amb.play(0.5);

    bn::sprite_ptr ball = bn::sprite_items::ball.create_sprite(0, 16);

    static const uint16_t start[] = {7, 6, 5, 4, 3, 2, 1, 0};
    bn::sprite_animate_action<16> action = bn::sprite_animate_action<16>::forever(
        ball, 8, bn::sprite_items::ball.tiles_item(), start);

    for (int i = 0; i < 64; ++i)
    {
        action.update();
        bn::core::update();
    }

    static const uint16_t ball_tiles_array[] = {0, 1, 2, 1};
    bn::span<const uint16_t> ball_tiles(ball_tiles_array);

    action = bn::sprite_animate_action<4>::forever(
        ball, 8, bn::sprite_items::ball.tiles_item(), ball_tiles);

    while (true)
    {
        action.update();
        bn::core::update();
    }
}
