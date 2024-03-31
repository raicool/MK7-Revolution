#include <base/entries.hpp>

#include <base/settings.hpp>

#include <format>

namespace base
{
    void entries::network::event_frame_modifier_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
		keyboard.DisplayTopScreen = true;
        keyboard.IsHexadecimal(false);

        auto const value = g_settings.m_options["network"]["event_frame_modifier"]["value"].get<u64 *>();

        int choice;

        do
		{
            keyboard.Populate(std::vector<std::string>
			{
				std::format("Value ({})", *value)
			});

            choice = keyboard.Open();

            switch (choice)
			{
                case 0: keyboard.Open(*value, *value); break;
            }
        }
        while (choice >= 0);
    }
}