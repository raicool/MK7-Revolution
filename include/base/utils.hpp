#pragma once

#include <forward.hpp>

#include <math/seadVectorFwd.h>

namespace base::utils
{
    u32 random_u32(u32 max);
    f32 random_f32();
    f32 random_f32(f32 min, f32 max);
    void emit_item(s32 const player_id, Item::eItemType const item, sead::Vector3f const &position, sead::Vector3f const &velocity);
}