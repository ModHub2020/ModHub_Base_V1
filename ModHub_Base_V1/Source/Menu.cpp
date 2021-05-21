#pragma once
#include "stdafx.h"


bool load()
{
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~y~Welcome Ultimate Base!");
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("¦", "¦", 1, 8, "~r~CR", "~y~Mod Hub Menu Base", 1, "Best Base", 9, 0);
	UI::_DRAW_NOTIFICATION(FALSE, FALSE);

	notifyleft("~g~Press * to opem Menu Controls: Numpad 8, 2, 6, 4, 5, 0");
	return true;
}
bool MainFirstopen = true;

void main() 
{
	while (true) 
	{
		Menu::Checks::Controlls();

		// Local Options
		Local_Option_toggle_Loop();

		// Settings

		if (MainFirstopen) {
			load();
			MainFirstopen = false;
		}

		switch (Menu::Settings::currentMenu) 
		{

		case mainmenu:
		{
			Menu::Title("Base V1");
			Menu::MenuOption("Local", Local);
			Menu::MenuOption("Settings", Settings);
		}
		break;

#pragma region Local Menu
		case Local:
		{
			Menu::Title("Local");
			Menu::Toggle("Godmode", Godmode);
		}
		break;
#pragma endregion Local Menu End

#pragma region Settings Menu
		case Settings:
		{
			Menu::Title("Settings");
			Menu::MenuOption("~g~Toggle ~y~Options", ToggleOptions);
			if (Menu::Option("~r~Quit GTA??")) exit(0);
		}
		break;
#pragma endregion Settings Menu

#pragma region Settings Toogle Menu
		case ToggleOptions:
		{
			Menu::Title("On/Off Toggle");
			if (Menu::Option("~g~ON ~w~/ ~r~OFF")) { if (YesNoSwitch) { YesNoSwitch = false; } if (IconSwitch) { IconSwitch = false; } OnOffSwitch = true; notifyleft("~g~ON ~w~/ ~r~OFF ~gold~Switches ~w~: ~g~Activated"); }
			if (Menu::Option("~g~YES ~w~/ ~r~NO")) { if (OnOffSwitch) { OnOffSwitch = false; } if (IconSwitch) { IconSwitch = false; } YesNoSwitch = true; notifyleft("~g~YES ~w~/ ~r~NO ~gold~Switches ~w~: ~g~Activated"); }
			if (Menu::Option("~b~Icon ~g~ON ~w~/ ~r~OFF")) { if (OnOffSwitch) { OnOffSwitch = false; } if (YesNoSwitch) { YesNoSwitch = false; } IconSwitch = true; notifyleft("~b~ICON ~g~ON ~w~/ ~r~OFF ~gold~Switches ~w~: ~g~Activated"); }
		}
		break;
#pragma endregion Settings Menu

		}
		Menu::End();
		WAIT(0);
	}
}

void ScriptMain() {
	srand(GetTickCount());

	main();
}

bool ControlScript::IsInitialized() {
	return s_initialized;
}

void ControlScript::Initialize() {
	s_initialized = true;
}

void ControlScript::Destroy() {

}

void ControlScript::Tick() {
	Menu::Checks::Controlls();
}



bool UpdateScript::IsInitialized() {
	return s_initialized;
}

void UpdateScript::Initialize() {
	s_initialized = true;
}

void UpdateScript::Destroy() {

}

void UpdateScript::Tick() {
	Local_Option_toggle_Loop();
}



bool DisplayScript::IsInitialized() {
	return s_initialized;
}

void DisplayScript::Initialize() {
	s_initialized = true;
}

void DisplayScript::Destroy() {

}
void DisplayScript::Tick() {
	//instructionals
}
bool HotkeyScript::IsInitialized() {
	return s_initialized;
}

void HotkeyScript::Initialize() {
	s_initialized = true;
}

void HotkeyScript::Destroy() {

}

void HotkeyScript::Tick() {

}

void initToggle() {

}