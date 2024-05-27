#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <magic_enum/magic_enum.hpp>

#include <format>

namespace base
{
    void entries::network::friend_info_modifier_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
		keyboard.DisplayTopScreen = true;
        keyboard.IsHexadecimal(true);

        auto const categories = std::vector<std::string>({ "Principal ID" });

        auto &friend_info_modifier = g_settings.m_options.network.friend_info_modifier;

        int choice;

        do
		{
            keyboard.GetMessage() = entry->Name();

            keyboard.Populate(categories);

            if (choice = keyboard.Open(); choice < 0)
                break;

            auto const &category = categories.at(choice);

            switch (choice)
            {
                case 0:
                {
                    do
		            {
                        keyboard.GetMessage() = std::format("{}\n{}", entry->Name(), category);

                        auto options = std::vector<std::string>
                        {
                            std::format("Enabled ({})", menu::s_toggles[friend_info_modifier.principal_id.enabled]),
                            std::format("Notify ({})", menu::s_toggles[friend_info_modifier.principal_id.notify]),
                            std::format("Mode ({})", magic_enum::enum_name(friend_info_modifier.principal_id.mode))
                        };
                        if (friend_info_modifier.principal_id.mode == decltype(friend_info_modifier.principal_id.mode)::Value)
                            options.push_back(std::format("Value ({:X})", friend_info_modifier.principal_id.value));
                        keyboard.Populate(options);

                        if (choice = keyboard.Open(); choice < 0)
                            break;

                        switch (choice)
                        {
                            case 0: friend_info_modifier.principal_id.enabled ^= true; break;
                            case 1: friend_info_modifier.principal_id.notify ^= true; break;
                            case 2: friend_info_modifier.principal_id.mode = magic_enum::enum_value<decltype(friend_info_modifier.principal_id.mode)>((magic_enum::enum_underlying(friend_info_modifier.principal_id.mode) + 1) % magic_enum::enum_count<decltype(friend_info_modifier.principal_id.mode)>()); break;
                            case 3: keyboard.Open(friend_info_modifier.principal_id.value, friend_info_modifier.principal_id.value); break;
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