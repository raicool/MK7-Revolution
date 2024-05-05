#include <base/entries.hpp>

#include <base/settings.hpp>

#include <array>
#include <format>

namespace base
{
	void entries::kart::instant_miniturbo_menu(CTRPluginFramework::MenuEntry *entry)
	{
		auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
		keyboard.DisplayTopScreen = true;

		auto const types = std::to_array({ "Blue", "Red" });

		auto &instant_miniturbo = g_settings.m_options.kart.instant_miniturbo;

		int choice;

		do
		{
			keyboard.Populate(std::vector<std::string>
			{
				std::format("Type: {}", types[instant_miniturbo])
			});

			choice = keyboard.Open();

			switch (choice)
			{
				case 0: if (++instant_miniturbo >= types.size()) instant_miniturbo = 0; break;
			}
		}
		while (choice >= 0);
	}
}