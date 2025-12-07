#include "core/commands/BoolCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/gta/Natives.hpp"
#include "game/gta/Pools.hpp"

namespace YimMenu::Features
{
	class SPWP : public BoolCommand
	{
		using BoolCommand::BoolCommand;
		virtual void OnEnable() override
		{
			DLC::ON_ENTER_MP();
		}

		virtual void OnDisable() override
		{
			DLC::ON_ENTER_SP();
		}
	};

	static SPWP _SPWP{"spwp", "Activate Online Map & Story Map", "Activate Online Map or Deactivate to activate Story Map"};
}
