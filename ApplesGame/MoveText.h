#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"


namespace ApplesGame
{
	struct MoveText
	{
		sf::Font font;
		sf::Text text;
	};

	struct Game;

	void InitMoveText(MoveText& moveText, const Game& game);
	void DrawMoveText(MoveText& moveText, sf::RenderWindow& window);
	void UpdateMoveText(MoveText& moveText, const std::string& message);
}