#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/pointers.hpp>

#include <RaceSys/ModeManagerBase.hpp>
#include <RaceSys/RaceDirector.hpp>
#include <System/RootSystem.hpp>

namespace base
{
	void features::mode::drive_during_sync_after(RaceSys::ModeManagerBase *mode_manager, RaceSys::ModeManagerBase::ERaceState original)
    {
        if (g_menu->m_drive_during_sync_entry->IsActivated())
        {
            if (mode_manager == nullptr)
                mode_manager = g_pointers->m_root_system->get_race_director()->m_mode_manager;

            mode_manager->m_race_state = original;
        }
    }
}