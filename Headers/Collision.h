#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>


class Collision {
	
public:
	static bool isCollision(const sf::CircleShape& circle, const sf::RectangleShape& rect);
};

