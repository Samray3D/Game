#include "Math.h"
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <cmath>


namespace ApplesGame
{
	Position2D GetRandomPositionInScreen(float minX , float maxX, float minY, float maxY)
	{
		Position2D result;
		result.x = minX + rand() / (float)RAND_MAX * (maxX - minX);
		result.y = minY + rand() / (float)RAND_MAX * (maxY - minY);
		return result;
	}

	bool isRectanglesCollide(Position2D rect1Position, Vector2D rect1Size,
		Position2D rect2Position, Vector2D rect2Size)
	{
		float dx = (float)fabs(rect1Position.x - rect2Position.x);
		float dy = (float)fabs(rect1Position.y - rect2Position.y);
		return(dx <= (rect1Size.x + rect2Size.x) / 2.f &&
			dy <= (rect1Size.y + rect2Size.y) / 2.f);
	}

	bool isCirclesCollide(Position2D circle1Position, float circle1Radius,
		Position2D circle2Position, float circle2Radius)
	{
		float squareDistance = ((circle1Position.x - circle2Position.x) * (circle1Position.x - circle2Position.x) +
			(circle1Position.y - circle2Position.y) * (circle1Position.y - circle2Position.y));
		float squareRadiusSum = (circle1Radius + circle2Radius) * (circle1Radius + circle2Radius);
		return(squareDistance <= squareRadiusSum);
	}

	void SetSpriteSize(sf::Sprite& sprite, float desireWidth, float desireHeight)
	{
		sf::FloatRect spriteRect = sprite.getLocalBounds();
		sf::Vector2f scale = { desireWidth / spriteRect.width, desireHeight / spriteRect.height };
		sprite.setScale(scale);
	}

	void SetSpriteRelariveOrigin(sf::Sprite& sprite, float originX, float originY)
	{
		sf::FloatRect spriteRect = sprite.getLocalBounds();
		sprite.setOrigin(originX * spriteRect.width, originY * spriteRect.height);
	}
}
