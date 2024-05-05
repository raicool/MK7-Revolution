#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <magic_enum/magic_enum.hpp>

#include <format>

namespace base
{
    void entries::item::item_hang_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
        keyboard.DisplayTopScreen = true;

        auto const items = std::to_array({ Item::eItemType::KouraB, Item::eItemType::Flower });
        
        auto &item_hang = g_settings.m_options.item.item_hang;

        int choice;

        do
		{
            auto options = std::vector<std::string>();
            std::for_each(items.begin(), items.end(), [&](auto const &i) { options.push_back(std::format("{} ({})", magic_enum::enum_name(i), menu::s_toggles[item_hang.contains(i)])); });
            keyboard.Populate(options);

            if (choice = keyboard.Open(); choice < 0)
                break;

            if (auto const &item = items.at(choice); item_hang.contains(item))
                item_hang.erase(item);
            else
                item_hang.emplace(item);
        }
        while (choice >= 0);
    }
}