#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Item_ItemDirector_calcKeyInputEachPlayer_0xE8()
    {
        asm volatile
        (
            "push {lr}\n"
            "bl __item_rapidfire_execute\n"
            "mov r8, r0\n"
            "pop {pc}\n"
        );
    }

    extern "C" auto __item_rapidfire_execute()
    {
        return features::item::item_rapidfire_execute();
    }
}