#include "title_screen.h"

#include "bn_core.h"
#include "bn_keypad.h"
#include "bn_sprite_animate_actions.h"
#include "bn_sprite_ptr.h"
#include "bn_span.h"
#include "bn_sprite_text_generator.h"
#include "bn_sprite_double_size_mode.h"

#include "bn_sprite_items_ball.h"

#include "bn_music_items.h"
#include "fixed_32x64_sprite_font.h"

#include "common_variable_8x16_sprite_font.h"

namespace Game
{
    constexpr bn::fixed text_y_limit = 72;

    void title_screen()
    {

        // Start scene (grow)
        bn::music_items::amb.play(0.5);

        bn::sprite_ptr ball = bn::sprite_items::ball.create_sprite(0, 0);

        ball.set_double_size_mode(bn::sprite_double_size_mode::ENABLED);

        static const uint16_t start[] = {7, 6, 5, 4, 3, 2, 1, 0};
        bn::sprite_animate_action<16> action = bn::sprite_animate_action<16>::forever(
            ball, 8, bn::sprite_items::ball.tiles_item(), start);

        for (int i = 0; i < 64; ++i)
        {
            action.update();
            bn::core::update();
        }

        // Pulse
        static const uint16_t ball_tiles_array[] = {0, 1, 2, 1};
        bn::span<const uint16_t> ball_tiles(ball_tiles_array);

        action = bn::sprite_animate_action<4>::forever(
            ball, 8, bn::sprite_items::ball.tiles_item(), ball_tiles);

        for (int i = 0; i < 700; ++i)
        {
            action.update();
            bn::core::update();
        }

        // Make text appear
        bn::vector<bn::sprite_ptr, 32> text_sprites;
        bn::sprite_text_generator huge_text_generator(fixed_32x64_sprite_font);
        huge_text_generator.set_center_alignment();

        huge_text_generator.generate(-16, -40, "Astral", text_sprites);
        huge_text_generator.generate(32, 40, "Pain", text_sprites);

        for (int i = 0; i < 240; ++i)
        {
            action.update();
            bn::core::update();
        }

        bn::sprite_text_generator text_generator(common::variable_8x16_sprite_font);
        text_generator.set_center_alignment();

        bn::vector<bn::sprite_ptr, 32> text_sprites_new;
        text_generator.generate(0, text_y_limit - 8, "a game by:", text_sprites_new);
        text_generator.generate(0, text_y_limit, "Rodrigo Casale", text_sprites_new);

        while (!bn::keypad::any_pressed())
        {
            action.update();
            bn::core::update();
        }

        bn::fixed scale = 1.0;

        // static const uint16_t end[] = {0, 1, 2, 3, 4, 5, 6, 7};
        // action = bn::sprite_animate_action<16>::once(
        //     ball, 16, bn::sprite_items::ball.tiles_item(), end);
        while (1)
        {
            scale -= 0.01;
            if (scale > 0)
            {
                for (int i = 0; i < 10; ++i)
                {
                    text_sprites[i].set_scale(scale);
                }
                for (int i = 0; i < 6; ++i)
                {
                    text_sprites_new[i].set_scale(scale);
                }
            }
            else
            {
                for (int i = 0; i < 10; ++i)
                {
                    text_sprites[i].set_visible(false);
                }
                for (int i = 0; i < 6; ++i)
                {
                    text_sprites_new[i].set_visible(false);
                }
            }
            if (!action.done())
            {
                action.update();
            }
            bn::core::update();
        }
    }
}