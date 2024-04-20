#include <base/hooking.hpp>
#include <base/features.hpp>

#include <Item/ItemObj/ItemObjFlower.hpp>

namespace base
{
    void hooks::Item_ItemObjFlower_stateEquipHang(Item::ItemObjFlower *_this)
    {
        if (features::item::item_hang(_this))
            return;

        g_hooking->m_Item_ItemObjKouraB_stateEquipHang_hook.call_original<void>(_this);
    }
}