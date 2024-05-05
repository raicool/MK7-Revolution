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

        auto &event_frame_modifier = g_settings.m_options.network.event_frame_modifier;

        int choice;

        do
		{
            keyboard.Populate(std::vector<std::string>
			{
				std::format("Value ({})", event_frame_modifier)
			});

            choice = keyboard.Open();

            switch (choice)
			{
                case 0: keyboard.Open(event_frame_modifier, event_frame_modifier); break;
            }
        }
        while (choice >= 0);
    }
}