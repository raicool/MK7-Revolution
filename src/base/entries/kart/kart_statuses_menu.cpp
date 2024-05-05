#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <format>

namespace base
{
    void entries::kart::kart_statuses_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
		keyboard.DisplayTopScreen = true;
		keyboard.IsHexadecimal(false);

        auto &kart_statuses = g_settings.m_options.kart.kart_statuses;

        int choice;

        do
		{
			keyboard.Populate(std::vector<std::string>
			{
                std::format("Blink ({})", menu::s_toggles[kart_statuses.blink]),
				std::format("Ink ({})", menu::s_toggles[kart_statuses.ink]),
				std::format("Press ({})", menu::s_toggles[kart_statuses.press]),
				std::format("Star ({})", menu::s_toggles[kart_statuses.star]),
				std::format("Thunder ({})", menu::s_toggles[kart_statuses.thunder]),
                std::format("Draft ({})", menu::s_toggles[kart_statuses.draft]),
			});

			choice = keyboard.Open();

			switch (choice)
			{
                case 0: kart_statuses.blink ^= true; break;
				case 1: kart_statuses.ink ^= true; break;
                case 2: kart_statuses.press ^= true; break;
                case 3: kart_statuses.star ^= true; break;
                case 4: kart_statuses.thunder ^= true; break;
                case 5: kart_statuses.draft ^= true; break;
            }
        }
        while (choice >= 0);
    }
}