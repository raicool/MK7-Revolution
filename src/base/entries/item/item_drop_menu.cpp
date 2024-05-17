#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <magic_enum/magic_enum.hpp>

#include <format>

namespace base
{
    void entries::item::item_drop_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
        keyboard.DisplayTopScreen = true;

        auto &item_drop = g_settings.m_options.item.item_drop;

        int choice;

        do
		{
            keyboard.Populate(std::vector<std::string>
            {
                std::format("Mode ({})", magic_enum::enum_name(item_drop.mode))
            });

            choice = keyboard.Open();

            switch (choice)
            {
                case 0: item_drop.mode = magic_enum::enum_value<decltype(item_drop.mode)>((magic_enum::enum_underlying(item_drop.mode) + 1) % magic_enum::enum_count<decltype(item_drop.mode)>()); break;
            }
        }
        while (choice >= 0);
    }
}