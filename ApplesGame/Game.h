#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"
#include "Constants.h"
#include "Enemy.h"
#include "Apple.h"
#include "Player.h"
#include <SFML/Audio.hpp>
#include "MoveText.h"
#include "GameOver.h"
#include "Score.h"
#include "LeaderBoard.h"


namespace ApplesGame
{
	struct Game
	{
		Player player;
		Apple* apples;
		int numApples;
		Enemy enemy[NUM_ENEMIES];

		//Global game data
		int numEatenApples = 0;
		bool isGameFinished = false;
		float gameFinishTime = 0;
		int Score = 0;
		sf::RectangleShape background;

		sf::Texture playerTexture;
		sf::Texture enemyTexture;
		sf::Texture appleTexture;
		sf::Texture gameOverTexture;
		GameOver gameOver;

		sf::SoundBuffer eatSoundBuffer;
		sf::Sound eatSound;

		sf::SoundBuffer deathSoundBuffer;
		sf::Sound deathSound;

		sf::Font scoreFont;
		ScoreText scoreText;

		MoveText moveText;

		std::string currentPlayerName;
		int playerNumber = 1;

		std::vector<Record> leaderboard;
		
	};


	void RestartGame(Game& game);
	void InitGame(Game& game, int gameMode);
	void UpdateGame(Game& game, float deltaTime, int gameMode);
	void DrawGame(Game& game, sf::RenderWindow& window);
	void DeinitializeGame(Game& game);
	
}