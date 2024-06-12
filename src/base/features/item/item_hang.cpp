#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/pointers.hpp>
#include <base/settings.hpp>

#include <Item/ItemObj/ItemObjBase.hpp>

namespace base
{
    bool features::item::item_hang(Item::ItemObjBase *_this)
    {
        auto enabled = g_menu->m_item_hang_entry->IsActivated() && g_settings.m_options.item.item_hang.items.contains(_this->m_item_type);

        if (enabled)
            g_pointers->m_Item_ItemObjBase_stateEquipHang(_this);

        return enabled;
    }
}