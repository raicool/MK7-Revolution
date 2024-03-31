#include <base/features.hpp>

#include <base/menu.hpp>

#include <Kart/NetData.hpp>

#include <limits>

#define MAX std::numeric_limits<s16>::max()

namespace base
{
    void features::network::invisibility(Kart::NetData *_this)
    {
        if (g_menu->m_invisibility_entry->IsActivated())
        {
            _this->position = sead::Vector3<s16>(MAX, MAX, MAX);
            _this->velocity = _this->angular_velocity = sead::Vector3<s16>(0, 0, 0);
            _this->turning_speed = _this->forward_speed = _this->drift_steering = _this->directional_speed = 0;
        }
    }
}