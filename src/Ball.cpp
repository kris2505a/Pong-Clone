#include "Headers/Ball.h"
#include "Headers/Log.h"
#include "Headers/Game.h"

Ball::Ball(sf::Vector2f loc, float radius, float speedvar, sf::RenderWindow *wind) {
	this->window = wind;
	this->circle.setRadius(radius);
	this->location = loc;
	this->circle.setPosition(location);
	this->circle.setFillColor(sf::Color::Red);
	this->speed.x = speedvar;
	this->speed.y = speedvar;


	Log::messageLog("Ball Created");
	
}


void Ball::draw() {
	window->draw(circle);


}


void Ball::update() {
	this->location += (this->speed * Game::getDeltaTime());
	if (this->location.y + circle.getRadius() <= 0 || this->location.y + circle.getRadius() >= this->window->getSize().y)
		this->speed.y *= -1;
	if (location.x + circle.getRadius() <= 0 || location.x + circle.getRadius() >= this->window->getSize().x)
		this->resetBall();
	this->circle.setPosition(location);

	
	
}


void Ball::resetBall() {
	Game::getCurrentGameMode()->increaseScore(this->getLocation().x);
	this->location.x = this->window->getSize().x / 2;
	this->location.y = this->window->getSize().y / 2;
	int arr[] = { -1, 1 };
	int ind = rand() % 2;
	this->speed.x *= arr[ind];
	this->speed.y *= arr[ind];
	Log::messageLog("Ball Reset");
	//Game::getCurrentGameMode()->
	
	
}



Ball::~Ball() {
	
}

sf::CircleShape Ball::getCircle() const {
	return this->circle;
}


void Ball::bounce() {
	speed.x = -speed.x;
}


sf::Vector2f Ball::getLocation() {
	return this->location;
}





