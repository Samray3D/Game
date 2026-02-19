#include "Apple.h"
#include "Game.h"


namespace ApplesGame
{
	void InitApple(Apple& apple, const Game& game)
	{
		//Init Apples
		apple.position = GetRandomPositionInScreen(APPLES_SIZE / 2, SCREEN_WIDTH - APPLES_SIZE / 2, APPLES_SIZE / 2, SCREEN_HEIGHT - APPLES_SIZE / 2);

		apple.sprite.setTexture(game.appleTexture);
		SetSpriteSize(apple.sprite, APPLES_SIZE, APPLES_SIZE);
		SetSpriteRelariveOrigin(apple.sprite, 0.5f, 0.5f);
	};

	void DrawApple(Apple& apple, sf::RenderWindow& window)
	{
		apple.sprite.setPosition(apple.position.x, apple.position.y);
		window.draw(apple.sprite);
	}
}
