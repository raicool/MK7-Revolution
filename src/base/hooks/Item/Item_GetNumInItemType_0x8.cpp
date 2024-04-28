#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Item_GetNumInItemType_0x8()
    {
        asm volatile
        (
            "push {r1, r2, r4, lr}\n"
            "mov r4, r0\n"
            "bl __item_limiters_num\n"
            "cmn r0, #1\n" // no need to run original
            "moveq r3, r4\n"
            "mvnne r3, #0\n"
            "pop {r1, r2, r4, pc}\n"
        );
    }

    extern "C" auto __item_limiters_num(Item::eItemType item)
    {
        return features::item::item_limiters_num(item);
    }
}