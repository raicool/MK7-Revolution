#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <magic_enum/magic_enum.hpp>

#include <format>

namespace base
{
	void entries::item::item_rain_menu(CTRPluginFramework::MenuEntry *entry)
	{
		auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
		keyboard.DisplayTopScreen = true;
		keyboard.IsHexadecimal(false);

		auto const items = std::to_array({ Item::eItemType::KouraG, Item::eItemType::KouraR, Item::eItemType::Banana, Item::eItemType::Kinoko, Item::eItemType::Star, Item::eItemType::KouraB, Item::eItemType::Bomhei, Item::eItemType::Gesso, Item::eItemType::Flower });

		auto &item_rain = g_settings.m_options.item.item_rain;

		int choice;

		do
		{
			keyboard.Populate(std::vector<std::string>
			{
				std::format("Items ({})", item_rain.items.size()),
				std::format("Owned ({})", menu::s_toggles[item_rain.owned]),
				std::format("Multi ({})", menu::s_toggles[item_rain.multi]),
				std::format("Speed ({}, {})", menu::s_toggles[item_rain.speed.enabled], item_rain.speed.value),
                std::format("Delay ({})", item_rain.delay),
				std::format("Shape ({})", magic_enum::enum_name(item_rain.shape)),
				std::format("Height ({})", item_rain.height),
				std::format("Width ({})", item_rain.width)
			});

			choice = keyboard.Open();

			switch (choice)
			{
				case 0:
				{
					while (true)
					{
						auto options = std::vector<std::string>();
						std::for_each(items.begin(), items.end(), [&](auto const &i) { options.push_back(std::format("{} ({})", magic_enum::enum_name(i), menu::s_toggles[item_rain.items.contains(i)])); });
						keyboard.Populate(options);

						if (choice = keyboard.Open(); choice < 0)
							break;

						auto const item = items.at(choice);

						if (item_rain.items.contains(item))
							item_rain.items.erase(item);
						else
							item_rain.items.emplace(item);
					}

					choice = 0;
					break;
				}
				case 1: item_rain.owned ^= true; break;
				case 2: item_rain.multi ^= true; break;
				case 3:
				{
					while (true)
					{
						keyboard.Populate(std::vector<std::string>
						{
							std::format("Status ({})", menu::s_toggles[item_rain.speed.enabled]),
							std::format("Value ({})", item_rain.speed.value)
						});

						choice = keyboard.Open();

						if (choice < 0)
							break;

						switch (choice)
						{
							case 0: item_rain.speed.enabled ^= true; break;
							case 1: keyboard.Open(item_rain.speed.value, item_rain.speed.value); break;
						}
					}

					choice = 0;
					break;
				}
                case 4: keyboard.Open(item_rain.delay, item_rain.delay); break;
				case 5: item_rain.shape = magic_enum::enum_value<decltype(item_rain.shape)>((magic_enum::enum_underlying(item_rain.shape) + 1) % magic_enum::enum_count<decltype(item_rain.shape)>()); break;
			    case 6: keyboard.Open(item_rain.height, item_rain.height); break;
				case 7: keyboard.Open(item_rain.width, item_rain.width); break;
			}
		}
		while (choice >= 0);
	}
}