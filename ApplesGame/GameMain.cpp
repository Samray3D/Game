// ©2023, XYZ School. All rights reserved.
// Authored by Aleksandr Rybalka (polterageist@gmail.com)

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Math.h"
#include "Constants.h"
#include "Game.h"
#include <ctime>
#include <cstdlib>
#include <iostream>


int main()
{
	

	sf::sleep(sf::milliseconds(16));
		using namespace ApplesGame;
		int seed = (int)time(nullptr);
		srand(seed);
		

		int choise = 0;

		std::cout << "Choose one of the three mods: " << std::endl;
		std::cout << "1 = 20 apples with acceleration" << std::endl;
		std::cout << "2 = 20 apples without acceleration" << std::endl;
		std::cout << "3 = 50 apples with acceleration" << std::endl;
		std::cin >> choise;

		if (choise == 1)
		{
			GAME_MODE = static_cast<int>(GameSettings::ACCELERATION) | static_cast<int>(GameSettings::TWENTY_APPLES);
		}
		else if (choise == 2)
		{
			GAME_MODE = static_cast<int>(GameSettings::TWENTY_APPLES);
		}
		else if (choise == 3)
		{
			GAME_MODE = static_cast<int>(GameSettings::ACCELERATION) | static_cast<int>(GameSettings::FIFTY_APPLES);
		}


		//Init window
		sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Apples game!");

		//GameInitialization
		Game game;
		InitGame(game, GAME_MODE);

		//Init game clocks
		sf::Clock gameClock;
		float lastTime = gameClock.getElapsedTime().asSeconds();

		//Read events
		while (window.isOpen())
		{
			float currentTime = gameClock.getElapsedTime().asSeconds();
			float deltaTime = currentTime - lastTime;
			lastTime = currentTime;

			//Read events
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
					break;
				}
				if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				{
					window.close();
					break;
				}
			}

			UpdateGame(game, deltaTime, GAME_MODE);

			window.clear();
			DrawGame(game, window);

			window.display();
		}

		//Deinitialization
		DeinitializeGame(game);

	return 0;
}
