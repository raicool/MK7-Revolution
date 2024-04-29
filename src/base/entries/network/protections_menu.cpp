#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <format>

namespace base
{
    void entries::network::protections_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard();
        keyboard.DisplayTopScreen = true;

        auto &settings = g_settings.m_options["network"]["protections"];
        auto &item = settings["item"];
        auto item_killer_items = item["killer_items"].get<bool *>();
        auto item_tail_items = item["tail_items"].get<bool *>();
        auto &network = settings["network"];
        auto network_system_info = network["system_info"].get<bool *>();

        int choice;

        do
        {
            auto const categories = std::vector<std::string>{ "Item", "Network" };

            keyboard.GetMessage() = entry->Name();
            keyboard.Populate(categories);

            if (choice = keyboard.Open(); choice < 0)
                break;

            keyboard.GetMessage() = std::format("{}\n{}", entry->Name(), categories.at(choice));

            switch (choice)
            {
                // Item
                case 0:
                {
                    do
                    {
                        keyboard.Populate(std::vector<std::string>
                        {
                            std::format("Killer Items ({})", menu::s_toggles[*item_killer_items]),
                            std::format("Tail Items ({})", menu::s_toggles[*item_tail_items])
                        });

                        choice = keyboard.Open();

                        switch (choice)
                        {
                            case 0: *item_killer_items ^= true; break;
                            case 1: *item_tail_items ^= true; break;
                        }
                    }
                    while (choice >= 0);

                    choice = 0;
                    break;
                }

                // Net
                case 1:
                {
                    do
                    {
                        keyboard.Populate(std::vector<std::string>
                        {
                            std::format("System Info ({})", menu::s_toggles[*network_system_info])
                        });

                        choice = keyboard.Open();

                        switch (choice)
                        {
                            case 0: *network_system_info ^= true; break;
                        }
                    }
                    while (choice >= 0);

                    choice = 0;
                    break;
                }
            }
        }
        while (choice >= 0);
    }
}