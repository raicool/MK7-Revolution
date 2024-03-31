#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Item_ItemObjKouraG_stateInitSelfMoveImpl(Item::ItemObjKouraG *_this)
    {
        g_hooking->m_Item_ItemObjKouraG_stateInitSelfMoveImpl_hook.call_original<void>(_this);

        features::item::zero_gravity_shells(_this);
    }
}