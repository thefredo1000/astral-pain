#ifndef BN_SPRITE_ITEMS_EYE_H
#define BN_SPRITE_ITEMS_EYE_H

#include "bn_sprite_item.h"

//{{BLOCK(eye_bn_gfx)

//======================================================================
//
//	eye_bn_gfx, 32x320@4, 
//	+ palette 16 entries, not compressed
//	+ 160 tiles Metatiled by 4x4 not compressed
//	Total size: 32 + 5120 = 5152
//
//	Time-stamp: 2025-05-12, 20:26:39
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_EYE_BN_GFX_H
#define GRIT_EYE_BN_GFX_H

#define eye_bn_gfxTilesLen 5120
extern const bn::tile eye_bn_gfxTiles[160];

#define eye_bn_gfxPalLen 32
extern const bn::color eye_bn_gfxPal[16];

#endif // GRIT_EYE_BN_GFX_H

//}}BLOCK(eye_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item eye(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(eye_bn_gfxTiles, 160), bpp_mode::BPP_4, compression_type::NONE, 10), 
            sprite_palette_item(span<const color>(eye_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

