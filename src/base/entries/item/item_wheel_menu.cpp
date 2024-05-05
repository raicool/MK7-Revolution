#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <magic_enum/magic_enum.hpp>

#include <format>

namespace base
{
    void entries::item::item_wheel_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
		keyboard.DisplayTopScreen = true;

        auto const items = std::to_array({ Item::eItemSlot::Banana, Item::eItemSlot::KouraG, Item::eItemSlot::KouraR, Item::eItemSlot::Kinoko, Item::eItemSlot::Bomhei, Item::eItemSlot::Gesso, Item::eItemSlot::KouraB, Item::eItemSlot::Kinoko3, Item::eItemSlot::Star, Item::eItemSlot::Killer, Item::eItemSlot::Thunder, Item::eItemSlot::KinokoP, Item::eItemSlot::Flower, Item::eItemSlot::Tail, Item::eItemSlot::Seven, Item::eItemSlot::Test3, Item::eItemSlot::Test4, Item::eItemSlot::Banana3, Item::eItemSlot::KouraG3, Item::eItemSlot::KouraR3, Item::eItemSlot::Empty });

		auto &item_wheel = g_settings.m_options.item.item_wheel;

        int choice;

        while (true)
        {
            auto options = std::vector<std::string>();
            std::for_each(items.begin(), items.end(), [&](auto const &i) { options.push_back(std::format("{} ({})", magic_enum::enum_name(i), menu::s_toggles[item_wheel.contains(i)])); });
            keyboard.Populate(options);

            if (choice = keyboard.Open(); choice < 0)
                break;

            if (auto const item = items.at(choice); item_wheel.contains(item))
                item_wheel.erase(item);
            else
                item_wheel.emplace(item);
        }
    }
}