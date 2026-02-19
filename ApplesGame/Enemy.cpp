#include "Enemy.h"
#include "Game.h"

namespace ApplesGame
{
	void InitEnemy(Enemy& enemy, const Game& game)
	{
		//Init enemies

		enemy.position = GetRandomPositionInScreen(ENEMIES_SIZE / 2, SCREEN_WIDTH - ENEMIES_SIZE / 2, ENEMIES_SIZE / 2, SCREEN_HEIGHT - ENEMIES_SIZE / 2);

		enemy.sprite.setTexture(game.enemyTexture);
		SetSpriteSize(enemy.sprite, ENEMIES_SIZE, ENEMIES_SIZE);
		SetSpriteRelariveOrigin(enemy.sprite, 0.5f, 0.5f);
	};

	void DrawEnemy(Enemy& enemy, sf::RenderWindow& window)
	{
		enemy.sprite.setPosition(enemy.position.x, enemy.position.y);
		window.draw(enemy.sprite);
	}
}

