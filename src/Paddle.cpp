#include "Headers/Paddle.h"
#include "Headers/Game.h"



Paddle::Paddle(sf::Vector2f loc, float sp, sf::RenderWindow* wind) {
	this->window = wind;
	this->location = loc;
	this->speed = sp;
	this->width = 20;
	this->height = 125;
	this->rectangle.setSize(sf::Vector2f(width, height));
	this->rectangle.setFillColor(sf::Color::Yellow);
	rectangle.setPosition(location);
}


void Paddle::draw() {
	window->draw(rectangle);
}

void Paddle::movePaddle(int n) {
	this->location.y += this->speed * n * Game::getDeltaTime();
	rectangle.setPosition(location);
	this->limitPaddle();
}

sf::RectangleShape Paddle::getRect() const {
	return this->rectangle;
}


void Paddle::limitPaddle() {
	if ((this->location.y) < 0)
		this->location.y = 0;
	if ((this->location.y) > (this->window->getSize().y - height))
		this->location.y = this->window->getSize().y - height;
	rectangle.setPosition(location);
}

void Paddle::move() {
	//testing to get rid of virtual function error.
}

