#include "core/commands/Command.hpp"
#include "game/gta/Natives.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/gta/Stats.hpp"

namespace YimMenu::Features
{
	class OscarGflies : public Command
	{
		using Command::Command;
		virtual void OnCall() override
		{
			if (*Pointers.IsSessionStarted)
			{
				Stats::SetInt("MPX_HACKER24_INST_BS", 31);
				STATS::STAT_SAVE(0, 0, 3, 0);
			}
			else
			{
				Notifications::Show("YimMenuV2", "You Must be Online", NotificationType::Error);
			}
		}
	};
	static OscarGflies _OscarGflies{
	    "SkipOscargunzmanflies",
	    "Skip Oscar gunzman flies again",
	    "Skip Oscar gunzman flies again"};
}
