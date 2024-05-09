#include <base/entries.hpp>

#include <base/settings.hpp>

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
                std::format("Mode ({})", modes.at(item_rapidfire.mode)),
                std::format("Delay ({})", item_rapidfire.delay),
            });

            choice = keyboard.Open();

            switch (choice)
            {
                case 0: if (++item_rapidfire.mode >= modes.size()) item_rapidfire.mode = 0; break;
                case 1: keyboard.Open(item_rapidfire.delay, item_rapidfire.delay); break;
            }
        }
        while (choice >= 0);
    }
}