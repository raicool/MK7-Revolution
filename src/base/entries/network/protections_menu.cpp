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

        auto &protections = g_settings.m_options.network.protections;

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
                            std::format("Killer Items ({})", menu::s_toggles[protections.item.killer_items]),
                            std::format("Tail Items ({})", menu::s_toggles[protections.item.tail_items])
                        });

                        choice = keyboard.Open();

                        switch (choice)
                        {
                            case 0: protections.item.killer_items ^= true; break;
                            case 1: protections.item.tail_items ^= true; break;
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
                            std::format("System Info ({})", menu::s_toggles[protections.network.system_info])
                        });

                        choice = keyboard.Open();

                        switch (choice)
                        {
                            case 0: protections.network.system_info ^= true; break;
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