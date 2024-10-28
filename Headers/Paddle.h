#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


class Paddle {
protected:
	sf::RectangleShape rectangle;
	sf::Vector2f location;
	float speed;
	float width;
	float height;
	sf::RenderWindow* window;

protected:
	void limitPaddle();

public:
	Paddle(sf::Vector2f loc, float sp, sf::RenderWindow* wind);
	void draw();
	virtual void movePaddle(int val);
	sf::RectangleShape getRect() const;
	virtual void move();

};

