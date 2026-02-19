#include "GameOver.h"
#include "Game.h"

namespace ApplesGame
{
	void InitGameOver(GameOver& gameOver, const Game& game)
	{
		//Init enemies
		gameOver.sprite.setTexture(game.gameOverTexture);
		gameOver.position = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
		gameOver.sprite.setPosition(gameOver.position.x, gameOver.position.y);

		sf::FloatRect bounds = gameOver.sprite.getLocalBounds();
		gameOver.sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);

	};

	void DrawGameOver(GameOver& gameOver, sf::RenderWindow& window)
	{
		gameOver.sprite.setPosition(gameOver.position.x, gameOver.position.y);
		window.draw(gameOver.sprite);
	}
}

