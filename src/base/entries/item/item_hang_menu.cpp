#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <magic_enum/magic_enum.hpp>

#include <Item/eItemType.hpp>

#include <format>
#include <set>

namespace base
{
    void entries::item::item_hang_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
        keyboard.DisplayTopScreen = true;

        auto settings = g_settings.m_options["item"]["item_hang"].get<std::set<Item::eItemType>>();

        int choice;

        do
		{
            auto const allowed = std::to_array({ Item::eItemType::KouraB, Item::eItemType::Flower });

            auto options = std::vector<std::string>();
            std::for_each(allowed.begin(), allowed.end(), [&](auto const &i) { options.push_back(std::format("{} ({})", magic_enum::enum_name(i), menu::s_toggles[settings.contains(i)])); });
            keyboard.Populate(options);

            if (choice = keyboard.Open(); choice < 0)
                break;

            if (auto const &item = allowed.at(choice); settings.contains(item))
                settings.erase(item);
            else
                settings.emplace(item);

            g_settings.m_options["item"]["item_hang"] = settings;
        }
        while (choice >= 0);
    }
}