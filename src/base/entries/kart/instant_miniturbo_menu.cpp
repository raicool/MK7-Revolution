#include <base/entries.hpp>

#include <base/settings.hpp>

#include <magic_enum/magic_enum.hpp>

#include <format>

namespace base
{
	void entries::kart::instant_miniturbo_menu(CTRPluginFramework::MenuEntry *entry)
	{
		auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
		keyboard.DisplayTopScreen = true;

		auto &instant_miniturbo = g_settings.m_options.kart.instant_miniturbo;

		int choice;

		do
		{
			keyboard.Populate(std::vector<std::string>
			{
				std::format("Type: {}", magic_enum::enum_name(instant_miniturbo.type))
			});

			choice = keyboard.Open();

			switch (choice)
			{
				case 0: instant_miniturbo.type = magic_enum::enum_value<decltype(instant_miniturbo.type)>((magic_enum::enum_underlying(instant_miniturbo.type) + 1) % magic_enum::enum_count<decltype(instant_miniturbo.type)>()); break;
			}
		}
		while (choice >= 0);
	}
}