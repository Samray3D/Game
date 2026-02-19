#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"
#include "Constants.h"

namespace ApplesGame
{
	struct Enemy
	{
		Position2D position;
		sf::Sprite sprite;
	};

	struct Game;

	void InitEnemy(Enemy& enemy, const Game& game);
	void DrawEnemy(Enemy& enemy, sf::RenderWindow& window);
}