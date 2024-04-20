#pragma once

#include <nlohmann/json.hpp>

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
		
		nlohmann::json m_options;

	private:
		bool load_impl();

		static void emplace_traverse(nlohmann::json &, nlohmann::json const &, std::vector<std::tuple<nlohmann::json *, std::string, nlohmann::json>> &);
		static void erase_traverse(nlohmann::json &, nlohmann::json const &, std::vector<std::pair<nlohmann::json *, std::string>> &);

		nlohmann::json const m_default_options =
		R"({
			"item":
			{
				"item_hang":
				[
					5, 13
				],
				"item_limiters":
				[
					[ 5, [true, 8] ],
					[ 9, [true, 32] ]
				],
				"item_rain":
				{
					"items": [0, 1, 2, 3, 4],
					"owned": true,
					"multi": false,
					"speed": { "status": true, "value": 64.0 },
					"delay": 15,
					"type": 0,
					"height": 128.0,
					"width": 256.0
				},
				"item_wheel":
				{
					"items": [0, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 13, 14]
				}
			},
			"kart":
			{
				"instant_miniturbo":
				{
					"type": 1
				},
				"intangibility":
				{
					"invert": true
				},
				"kart_statuses":
				{
					"blink": true,
					"ink": true,
					"press": false,
					"star": false,
					"thunder": false,
					"draft": false
				}
			},
			"network":
			{
				"event_frame_modifier":
				{
					"value": 2
				},
				"protections":
				{
					"network": true
				}
			}
		})"_json;
	};

	inline settings g_settings;
}
