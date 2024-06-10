#include <base/utils.hpp>

#include <base/pointers.hpp>

#include <Item/eItemType.hpp>
#include <Item/ItemDirector.hpp>
#include <System/RootSystem.hpp>

#include <math/seadVector.h>

namespace base::utils
{
    u32 random_u32()
    {
        return (*g_pointers->m_random)->getU32();
    }

    u32 random_u32(u32 max)
    {
        return (*g_pointers->m_random)->getU32(max);
    }
    
    f32 random_f32()
    {
        return (*g_pointers->m_random)->getF32();
    }

    f32 random_f32(f32 min, f32 max)
    {
        return (*g_pointers->m_random)->getF32Range(min, max);
    }

    void emit_item(s32 const player_id, Item::eItemType const item, sead::Vector3f const &position, sead::Vector3f const &velocity)
    {
        if (auto const item_obj_director = g_pointers->m_root_system->get_item_director()->getDirector_FromItemType(item); item_obj_director != nullptr)
            g_pointers->m_Item_ItemObjDirectorBase_emitItemImpl(item_obj_director, player_id, &position, &velocity);
    }
}