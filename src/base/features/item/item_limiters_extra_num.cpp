#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

namespace base
{
    s32 features::item::item_limiters_extra_num(Item::eItemType type)
    {
        // Sets "extra" (single item modes) amounts to 0
        if (g_menu->m_item_limiters_entry->IsActivated())
            if (auto const &item_limiters = g_settings.m_options.item.item_limiters; item_limiters.contains(type) && item_limiters.at(type).first)
                return 0;

        return -1;
    }
}