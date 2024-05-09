#pragma once

#include <map>
#include <set>

#include <Item/eItemSlot.hpp>
#include <Item/eItemType.hpp>

namespace base
{
	class settings
	{
	public:
		explicit settings() = default;
		~settings() = default;

		bool load();
		bool store();
		bool reset();

		struct options
		{
			struct item
			{
				std::set<Item::eItemType> item_hang
				{
					Item::eItemType::KouraB,
					Item::eItemType::Flower
				};

				std::map<Item::eItemType, std::pair<bool, u32>> item_limiters
				{
					{ Item::eItemType::KouraB, { true, 8 } },
					{ Item::eItemType::Bomhei, { true, 32 } }
				};

				struct item_rain
				{
					std::set<Item::eItemType> items
					{
						Item::eItemType::KouraG,
						Item::eItemType::KouraR,
						Item::eItemType::Banana,
						Item::eItemType::Kinoko,
						Item::eItemType::Star
					};
					bool owned{ true };
					bool multi{ false };
					std::pair<bool, float> speed{ true, 64.f };
					u32 delay{ 15 };
					size_t shape{ 0 };
					float height{ 128.f };
					float width{ 256.f };
				}
				item_rain;

				struct item_rapidfire
				{
					size_t mode{ 1 };
					u32 delay{ 5 };
				}
				item_rapidfire;

				std::set<Item::eItemSlot> item_wheel
				{
					Item::eItemSlot::Banana,
					Item::eItemSlot::KouraG,
					Item::eItemSlot::KouraR,
					Item::eItemSlot::Kinoko,
					Item::eItemSlot::Bomhei,
					Item::eItemSlot::Gesso,
					Item::eItemSlot::KouraB,
					Item::eItemSlot::Star,
					Item::eItemSlot::Killer,
					Item::eItemSlot::Thunder,
					Item::eItemSlot::Flower,
					Item::eItemSlot::Tail,
					Item::eItemSlot::Seven,
				};
			}
			item;

			struct kart
			{
				size_t instant_miniturbo{ 1 };

				bool intangibility{ true };

				struct kart_statuses
				{
					bool blink{ true };
					bool ink{ true };
					bool press{ false };
					bool star{ false };
					bool thunder{ false };
					bool draft{ false };
				}
				kart_statuses;
			}
			kart;

			struct network
			{
				u32 event_frame_modifier{ 2 };

				struct protections
				{
					struct item
					{
						bool killer_items{ false };
						bool tail_items{ false };
					}
					item;

					struct network
					{
						bool system_info{ true };
					}
					network;
				}
				protections;
			}
			network;
		}
		m_options{};

	private:
		bool load_impl();
	};

	inline settings g_settings;
}
