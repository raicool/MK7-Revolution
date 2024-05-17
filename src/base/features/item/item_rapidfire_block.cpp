#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

namespace base
{
    sead::BitFlag32 features::item::item_rapidfire_block(sead::Controller *_this)
    {
        auto &hold = _this->mPadHold;

        if (g_menu->m_item_rapidfire_entry->IsActivated())
        {
            auto const &item_rapidfire = g_settings.m_options.item.item_rapidfire;

            switch (item_rapidfire.mode)
            {
                case decltype(item_rapidfire.mode)::X: hold.resetBit(sead::Controller::cPadIdx_X); break;
                case decltype(item_rapidfire.mode)::L: hold.resetBit(sead::Controller::cPadIdx_L); break;
            }
        }

        return hold;
    }
}