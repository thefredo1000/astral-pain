#include "eye_screen.h"

#include "bn_core.h"
#include "bn_keypad.h"
#include "bn_sprite_animate_actions.h"
#include "bn_sprite_ptr.h"
#include "bn_span.h"
#include "bn_sprite_text_generator.h"
#include "bn_sprite_double_size_mode.h"

#include "bn_sprite_items_eye.h"

#include "bn_music_items.h"
#include "fixed_32x64_sprite_font.h"

#include "common_variable_8x16_sprite_font.h"

namespace Game
{
    constexpr bn::fixed text_y_limit = 72;

    enum class eye_state
    {
        IDLE,
        LEFT,
        RIGHT
    };

    void eye_screen()
    {
        bn::sprite_ptr eye = bn::sprite_items::eye.create_sprite(0, 0);

        static const uint16_t start[] = {0, 1, 2, 3, 4, 5, 6, 7};

        bn::sprite_animate_action<16> eye_action = bn::sprite_animate_action<16>::once(
            eye, 8, bn::sprite_items::eye.tiles_item(), start);

        for (int i = 0; i < 56; ++i)
        {
            eye_action.update();
            bn::core::update();
        }

        eye_state state = eye_state::IDLE;
        bool up = false;
        bool tick = 0;
        while (1)
        {

            if (bn::keypad::left_held() || bn::keypad::right_held())
            {
                if (up)
                {
                    eye.set_y(eye.y() - 1);
                }
                else
                {
                    eye.set_y(eye.y() + 1);
                }

                if (eye.y() >= 4)
                {
                    up = true;
                }
                else if (eye.y() <= -4)
                {
                    up = false;
                }
            }
            if (bn::keypad::left_held())
            {
                eye.set_x(eye.x() - 1);
                if (state != eye_state::LEFT)
                {
                    state = eye_state::LEFT;
                    eye.set_tiles(bn::sprite_items::eye.tiles_item().create_tiles(6));
                }
                else
                {
                    eye.set_tiles(bn::sprite_items::eye.tiles_item().create_tiles(8));
                }
            }
            else if (bn::keypad::right_held())
            {
                eye.set_x(eye.x() + 1);
                if (state != eye_state::RIGHT)
                {
                    state = eye_state::RIGHT;
                    eye.set_tiles(bn::sprite_items::eye.tiles_item().create_tiles(6));
                }
                else
                {
                    eye.set_tiles(bn::sprite_items::eye.tiles_item().create_tiles(7));
                }
            }
            else if (state != eye_state::IDLE)
            {
                state = eye_state::IDLE;
                eye.set_tiles(bn::sprite_items::eye.tiles_item().create_tiles(6));
            }
            bn::core::update();
        }
    }
}