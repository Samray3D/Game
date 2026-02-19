#pragma once
#include <string>


namespace ApplesGame
{
	const std::string RESOURCES_PATH = "Resources/";
	const std::string FONTS_PATH = RESOURCES_PATH + "\\Fonts\\";
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;
	const float INITIAL_SPEED = 100.f;
	const float PLAYER_SIZE = 20.f;
	const float ACCELERATION = 20.f;
	const int NUM_APPLES = 20;
	const float APPLES_SIZE = 20.f;
	const int NUM_ENEMIES = 10;
	const float ENEMIES_SIZE = 20.f;
	const float PAUSE_LENGTH = 2.f;
	extern int GAME_MODE;

	enum class GameSettings
	{
		ACCELERATION = 1 << 0,
		TWENTY_APPLES = 1 << 1,
		FIFTY_APPLES = 1 << 2,
	};
}
