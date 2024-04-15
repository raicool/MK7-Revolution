#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    s32 hooks::Item_GetExtraItemNum(Item::eItemType item_type)
    {
        return features::item::item_limiters_extra_num(item_type).value_or(g_hooking->m_Item_GetExtraItemNum_hook.call_original<s32>(item_type));
    }
}