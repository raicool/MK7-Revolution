#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <magic_enum/magic_enum.hpp>

#include <Item/eItemType.hpp>

#include <array>
#include <format>

namespace base
{
    void entries::item::item_limiters_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard();
        keyboard.DisplayTopScreen = true;
        keyboard.IsHexadecimal(false);

        auto data = g_settings.m_options["item"]["item_limiters"].get<std::map<Item::eItemType, std::pair<bool, u64>>>();

        int choice;

        do
		{
            auto const allowed = std::to_array({ Item::eItemType::KouraG, Item::eItemType::KouraR, Item::eItemType::Banana, Item::eItemType::Kinoko, Item::eItemType::Star, Item::eItemType::KouraB, Item::eItemType::Thunder, Item::eItemType::Bomhei, Item::eItemType::Gesso, Item::eItemType::Killer, Item::eItemType::Flower, Item::eItemType::Tail, Item::eItemType::Seven });

            keyboard.GetMessage() = entry->Name();

            auto options = std::vector<std::string>();

            for (auto const &i : allowed)
                if (data.contains(i))
                    options.push_back(std::format("{} ({}, {})", magic_enum::enum_name(i), menu::s_toggles[data.at(i).first], data.at(i).second));
                else
                    options.push_back(std::format("{}", magic_enum::enum_name(i)));

            keyboard.Populate(options);

            if (choice = keyboard.Open(); choice < 0)
                break;

            auto const &item = allowed.at(choice);

            if (!data.contains(item))
                data.emplace(std::make_pair(item, std::make_pair(false, 0)));

            while (true)
			{
                auto &e = data.at(item);

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
            g_settings.m_options["item"]["item_limiters"] = data;
        }
        while (choice >= 0);
    }
}