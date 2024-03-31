#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Net_NetworkEventModule_calc_0xB4()
    {
        asm volatile
        (
            "push {r0-r3, lr}\n"
            "bl __event_frame_modifier\n"
            "mov r4, r0\n"
            "pop {r0-r3, pc}\n"
        );
    }

    extern "C" auto __event_frame_modifier(Net::NetworkEventModule::Slot *_this)
    {
        return base::features::network::event_frame_modifier(_this);
    }
}