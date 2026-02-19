#include "Game.h"
#include "MoveText.h"
#include "Score.h"
#include "GameOver.h"
#include <cassert>
#include <SFML/Audio.hpp>

namespace ApplesGame
{
	int GAME_MODE = 0;

	void RestartGame(Game& game)
	{
		//Game initialization

	//Init player
		InitPlayer(game.player, game);

		//Init apples
		for (int i = 0; i < game.numApples; ++i)
		{
			InitApple(game.apples[i], game);
		}

		//Init enemies
		for (int i = 0; i < NUM_ENEMIES; ++i)
		{
			InitEnemy(game.enemy[i], game);
		}

		game.numEatenApples = 0;
		game.isGameFinished = false;
		game.gameFinishTime = 0;
		game.Score = 0;
	};

	void InitGame(Game& game, int gameMode)
	{

		assert(game.playerTexture.loadFromFile(RESOURCES_PATH + "Player.png"));
		assert(game.enemyTexture.loadFromFile(RESOURCES_PATH + "Enemy.png"));
		assert(game.appleTexture.loadFromFile(RESOURCES_PATH + "Apple.png"));

		assert(game.eatSoundBuffer.loadFromFile(RESOURCES_PATH + "AppleEat.wav"));
		game.eatSound.setBuffer(game.eatSoundBuffer);

		assert(game.deathSoundBuffer.loadFromFile(RESOURCES_PATH + "Death.wav"));
		game.deathSound.setBuffer(game.deathSoundBuffer);

		InitScoreText(game.scoreText, game);
		

		InitMoveText(game.moveText, game);


		assert(game.gameOverTexture.loadFromFile(RESOURCES_PATH + "GameOver.png"));
		InitGameOver(game.gameOver, game);

		if (gameMode & static_cast<int>(GameSettings::TWENTY_APPLES))
		{
			game.numApples = 20;
		}
		else if (gameMode & static_cast<int>(GameSettings::FIFTY_APPLES))
		{
			game.numApples = 50;
		}
		else if (gameMode & static_cast<int>(GameSettings::ACCELERATION))
		{
			game.player.speed += ACCELERATION;
		}
		else
		{
			game.numApples = 1 + rand() % 100;
		}
		game.apples = new Apple[game.numApples];

		//Game initialization

		game.background.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
		game.background.setFillColor(sf::Color::Black);
		game.background.setPosition(0.f, 0.f);

		RestartGame(game);

	};

	void UpdateGame(Game& game, float deltaTime, int gameMode)

	{


		if (game.isGameFinished)
		{


			if (game.gameFinishTime <= PAUSE_LENGTH)
			{
				game.gameFinishTime += deltaTime;
				game.background.setFillColor(sf::Color::Red);
			}
			else
			{
				game.background.setFillColor(sf::Color::Black);
				RestartGame(game);
			}
			return;
		}
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				game.player.direction = PlayerDirection::Right;
				game.player.rotation = 0.f;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				game.player.direction = PlayerDirection::Up;
				game.player.rotation = -90.f;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				game.player.direction = PlayerDirection::Left;
				game.player.rotation = 180.f;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				game.player.direction = PlayerDirection::Down;
				game.player.rotation = 90.f;
			}

			switch (game.player.direction)
			{
			case PlayerDirection::Right:
			{
				game.player.position.x += game.player.speed * deltaTime;
				break;
			}
			case PlayerDirection::Up:
			{
				game.player.position.y -= game.player.speed * deltaTime;
				break;
			}
			case PlayerDirection::Left:
			{
				game.player.position.x -= game.player.speed * deltaTime;
				break;
			}
			case PlayerDirection::Down:
			{
				game.player.position.y += game.player.speed * deltaTime;
				break;
			}
			}

			

			//Col with apple
			for (int i = 0; i < game.numApples; ++i)
			{
				if (isCirclesCollide(game.player.position, PLAYER_SIZE / 2.f,
					game.apples[i].position, APPLES_SIZE / 2.f))
				{
					game.apples[i].position = GetRandomPositionInScreen(APPLES_SIZE / 2, SCREEN_WIDTH - APPLES_SIZE / 2, APPLES_SIZE / 2, SCREEN_HEIGHT - APPLES_SIZE / 2);
					++game.numEatenApples;
					++game.Score;
					if (gameMode & static_cast<int>(GameSettings::ACCELERATION))
					{
						game.player.speed += ACCELERATION;
					}

					game.eatSound.play();

				}
			}

			//Col with enemy
			for (int i = 0; i < NUM_ENEMIES; ++i)
			{
				if (isRectanglesCollide(game.player.position, { PLAYER_SIZE, PLAYER_SIZE },
					game.enemy[i].position, { ENEMIES_SIZE, ENEMIES_SIZE }))
				{
					game.isGameFinished = true;
					game.gameFinishTime = 0.f;

					game.deathSound.play();
				}
			}

			//Col with border
			if (game.player.position.x - PLAYER_SIZE / 2.f < 0.f || game.player.position.x + PLAYER_SIZE / 2.f > SCREEN_WIDTH ||
				game.player.position.y - PLAYER_SIZE / 2.f < 0.f || game.player.position.y + PLAYER_SIZE / 2.f > SCREEN_HEIGHT)
			{
				game.isGameFinished = true;
				game.gameFinishTime = 0.f;

				game.deathSound.play();
			}

		}
	};

	void DrawGame(Game& game, sf::RenderWindow& window)
	{
		window.draw(game.background);
		if (game.isGameFinished)
		{
			DrawGameOver(game.gameOver, window);
		}
		else {
			DrawPlayer(game.player, window);

			UpdateScoreText(game.scoreText, "Score: " + std::to_string(game.Score));
			DrawScoreText(game.scoreText, window);

			UpdateMoveText(game.moveText, "For moving use arrow keys - Up, left, right and down");

			DrawMoveText(game.moveText, window);

		

			for (int i = 0; i < game.numApples; ++i)
			{
				DrawApple(game.apples[i], window);
			}
			for (int i = 0; i < NUM_ENEMIES; ++i)
			{
				DrawEnemy(game.enemy[i], window);
			}
		}
		
	};

	void DeinitializeGame(Game& game)
	{
		delete[] game.apples;
		game.apples = nullptr;
	};

}

