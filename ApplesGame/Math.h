#pragma once

namespace sf
{
	class Sprite;
}

namespace ApplesGame
{
	struct Vector2D
	{
		float x = 0;
		float y = 0;
	};


	typedef Vector2D Position2D;

	Position2D GetRandomPositionInScreen(float minX, float maxX, float minY, float maxY);



	bool isRectanglesCollide(Position2D rect1Position, Vector2D rect1Size,
		Position2D rect2Position, Vector2D rect2Size);

	bool isCirclesCollide(Position2D circle1Position, float circle1Radius,
		Position2D circle2Position, float circle2Radius);

	void SetSpriteSize(sf::Sprite& sprite, float desireWidth, float desireHeight);
	void SetSpriteRelariveOrigin(sf::Sprite& sprite, float originX, float originY);
}

