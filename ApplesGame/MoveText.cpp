#include "MoveText.h"
#include "Game.h"
#include <cassert>


namespace ApplesGame
{
	void InitMoveText(MoveText& moveText, const Game& game)
	{
		assert(moveText.font.loadFromFile(FONTS_PATH + "Roboto-Black.ttf"));

		moveText.text.setFont(moveText.font);
		moveText.text.setCharacterSize(20);
		moveText.text.setFillColor(sf::Color::White);
		moveText.text.setPosition(10.f, SCREEN_HEIGHT - 30.f);
		moveText.text.setString("For moving use arrow keys - Up, Down, Left, Right");
	};

	void DrawMoveText(MoveText& moveText, sf::RenderWindow& window)
	{
		window.draw(moveText.text);
	};
	
	void UpdateMoveText(MoveText& moveText, const std::string& message)
	{
		moveText.text.setString(message);
	}
}
