#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"
#include "Constants.h"


namespace ApplesGame
{
	enum class PlayerDirection
	{
		Up = 0,
		Right,
		Left,
		Down
	};

	struct Player
	{
		Position2D position;
		float speed = INITIAL_SPEED;
		PlayerDirection direction = PlayerDirection::Up;
		sf::Sprite sprite;
		float rotation = 0.f;

		};

	struct Game;

	void InitPlayer(Player& player, const Game& game);
	void DrawPlayer(Player& player, sf::RenderWindow& window);
}
