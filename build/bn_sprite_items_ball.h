#ifndef BN_SPRITE_ITEMS_BALL_H
#define BN_SPRITE_ITEMS_BALL_H

#include "bn_sprite_item.h"

//{{BLOCK(ball_bn_gfx)

//======================================================================
//
//	ball_bn_gfx, 32x256@4, 
//	+ palette 16 entries, not compressed
//	+ 128 tiles Metatiled by 4x4 not compressed
//	Total size: 32 + 4096 = 4128
//
//	Time-stamp: 2025-05-11, 19:36:08
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BALL_BN_GFX_H
#define GRIT_BALL_BN_GFX_H

#define ball_bn_gfxTilesLen 4096
extern const bn::tile ball_bn_gfxTiles[128];

#define ball_bn_gfxPalLen 32
extern const bn::color ball_bn_gfxPal[16];

#endif // GRIT_BALL_BN_GFX_H

//}}BLOCK(ball_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item ball(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(ball_bn_gfxTiles, 128), bpp_mode::BPP_4, compression_type::NONE, 8), 
            sprite_palette_item(span<const color>(ball_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

