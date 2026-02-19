#include "Player.h"
#include "Game.h"

namespace ApplesGame 
{
	void InitPlayer(Player& player, const Game& game)
	{
		//Init player
		player.position = { SCREEN_WIDTH / 2.f , SCREEN_HEIGHT / 2.f };
		player.speed = INITIAL_SPEED;
		player.direction = PlayerDirection::Up;
		player.rotation = -90.f;

		//Init player sprite
		player.sprite.setTexture(game.playerTexture);
		SetSpriteSize(player.sprite, PLAYER_SIZE, PLAYER_SIZE);
		SetSpriteRelariveOrigin(player.sprite, 0.5f, 0.5f);
	}

	void DrawPlayer(Player& player, sf::RenderWindow& window)
	{
		player.sprite.setPosition(player.position.x, player.position.y);
		player.sprite.setRotation(player.rotation);
		window.draw(player.sprite);
	}
}

