#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/gta/Natives.hpp"
#include "game/gta/Pools.hpp"
#include <unordered_set>

namespace YimMenu::Features
{
	class AllVehsLoudRadio : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;
		std::unordered_set<int> m_Forced;
		void OnTick() override
		{
			for (auto veh : Pools::GetVehicles())
			{
				const int handle = veh.GetHandle();
				if (!ENTITY::DOES_ENTITY_EXIST(handle))
					continue;
				if (ENTITY::IS_ENTITY_DEAD(handle, false))
					continue;
				if (!veh.RequestControl(0))
				{
					if (!m_Forced.contains(handle))
					{
						veh.ForceControl();
						m_Forced.insert(handle);
					}
					else
					{
						continue;
					}
				}
				if (!ENTITY::DOES_ENTITY_EXIST(handle))
					continue;
				AUDIO::SET_VEHICLE_RADIO_ENABLED(handle, true);
				AUDIO::SET_VEHICLE_RADIO_LOUD(handle, true);
				VEHICLE::SET_VEHICLE_ENGINE_ON(handle, true, true, false);
			}
		}

		void OnDisable() override
		{
			m_Forced.clear();
		}
	};

		static AllVehsLoudRadio _AllVehsLoudRadio{"loudsubwoffer", "Subwoofer", "Enables loud radio on vehicles, Players can hear it."};
	}
