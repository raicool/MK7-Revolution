#include <base/entries.hpp>

#include <base/settings.hpp>

#include <magic_enum/magic_enum.hpp>

#include <format>

namespace base
{
    void entries::item::item_rapidfire_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
		keyboard.DisplayTopScreen = true;
		keyboard.IsHexadecimal(false);

        auto const modes = std::to_array({ "X", "L" });

        auto &item_rapidfire = g_settings.m_options.item.item_rapidfire;

        int choice;

		do
		{
            keyboard.Populate(std::vector<std::string>
            {
                std::format("Mode ({})", magic_enum::enum_name(item_rapidfire.mode)),
                std::format("Delay ({})", item_rapidfire.delay),
            });

            choice = keyboard.Open();

            switch (choice)
            {
                case 0: item_rapidfire.mode = magic_enum::enum_value<decltype(item_rapidfire.mode)>((magic_enum::enum_underlying(item_rapidfire.mode) + 1) % magic_enum::enum_count<decltype(item_rapidfire.mode)>()); break;
                case 1: keyboard.Open(item_rapidfire.delay, item_rapidfire.delay); break;
            }
        }
        while (choice >= 0);
    }
}