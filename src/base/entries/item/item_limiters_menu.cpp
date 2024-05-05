#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <magic_enum/magic_enum.hpp>

#include <array>
#include <format>

namespace base
{
    void entries::item::item_limiters_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard();
        keyboard.DisplayTopScreen = true;
        keyboard.IsHexadecimal(false);

        auto const items = std::to_array({ Item::eItemType::KouraG, Item::eItemType::KouraR, Item::eItemType::Banana, Item::eItemType::Kinoko, Item::eItemType::Star, Item::eItemType::KouraB, Item::eItemType::Thunder, Item::eItemType::Bomhei, Item::eItemType::Gesso, Item::eItemType::Killer, Item::eItemType::Flower, Item::eItemType::Tail, Item::eItemType::Seven });

        auto &item_limiters = g_settings.m_options.item.item_limiters;

        int choice;

        do
		{
            keyboard.GetMessage() = entry->Name();

            auto options = std::vector<std::string>();
            std::for_each(items.begin(), items.end(), [&](auto const &i)
            {
                if (item_limiters.contains(i))
                    options.push_back(std::format("{} ({}, {})", magic_enum::enum_name(i), menu::s_toggles[item_limiters.at(i).first], item_limiters.at(i).second));
                else
                    options.push_back(std::format("{}", magic_enum::enum_name(i)));
            });
            keyboard.Populate(options);

            if (choice = keyboard.Open(); choice < 0)
                break;

            auto const &item = items.at(choice);

            if (!item_limiters.contains(item))
                item_limiters.emplace(std::make_pair(item, std::make_pair(false, 0)));

            while (true)
			{
                auto &e = item_limiters.at(item);

                keyboard.GetMessage() = std::format("{}\n{}", entry->Name(), magic_enum::enum_name(item));
                keyboard.Populate(std::vector<std::string>
                {
                    std::format("{}", menu::s_toggles[e.first]),
                    std::format("{}", e.second)
                });

                if (choice = keyboard.Open(); choice < 0)
                    break;

                switch (choice)
                {
                    case 0: e.first ^= true; break;
                    case 1: keyboard.Open(e.second, e.second); break;
                }
            }

            choice = 0;
        }
        while (choice >= 0);
    }
}