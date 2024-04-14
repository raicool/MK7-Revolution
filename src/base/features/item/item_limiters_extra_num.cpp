#include <base/features.hpp>

#include <base/menu.hpp>

namespace base
{
    s32 features::item::item_limiters_extra_num(Item::eItemType item_type)
    {
        if (g_menu->m_item_limiters_entry->IsActivated())
            return 0;

        return -1;
    }
}