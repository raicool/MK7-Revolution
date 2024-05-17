#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/menu_types.hpp>
#include <base/settings.hpp>

#include <MenuEntryHelpers.hpp>

namespace base
{
    bool features::item::item_rapidfire_execute()
    {
        auto result = false;

        if (g_menu->m_item_rapidfire_entry->IsActivated())
        {
            auto const &item_rapidfire = g_settings.m_options.item.item_rapidfire;
            auto is_down = false;

            switch (item_rapidfire.mode)
            {
                case decltype(item_rapidfire.mode)::X: is_down = CTRPluginFramework::Controller::IsKeyDown(CTRPluginFramework::Key::X); break;
                case decltype(item_rapidfire.mode)::L: is_down = CTRPluginFramework::Controller::IsKeyDown(CTRPluginFramework::Key::L); break;
            }

            auto &count = GetArg<menu_types::item_rapidfire_data_t>(g_menu->m_item_rapidfire_entry)->count;

            if (is_down)
            {
                if (++count > item_rapidfire.delay)
                {
                    count = 0;
                    result = true;
                }
            }
            else
                count = item_rapidfire.delay;
        }

        return result;
    }
}