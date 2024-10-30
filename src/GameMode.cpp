#include "Headers/GameMode.h"
#include "Headers/Collision.h"
#include "Headers/Log.h"


void GameMode::draw() {
	this->ball->draw();
	this->paddle1->draw();
	this->paddle2->draw();
	this->window->draw(score1);
	this->window->draw(score2);
}


void GameMode::freeMemory() {
	delete this->ball;
	delete this->paddle1;
	delete this->paddle2;
	Log::messageLog("Ball Destroyed");
	Log::messageLog("Paddle1 Destroyed");
	Log::messageLog("Paddle2 Destroyed");
}



void GameMode::tick() {
	this->handleInput();
	this->update();
	this->draw();
	

}



void GameMode::update() {
	this->ball->update();
	if (Collision::isCollision(ball->getCircle(), paddle1->getRect()) ||
		Collision::isCollision(ball->getCircle(), paddle2->getRect()))
		this->ball->bounce();
	this->updateScore();

	
}

void GameMode::initText() {

	if (!this->font.loadFromFile("Textures/dungeon.TTF"))
		Log::errorLog("Failed To Load Texture");
	this->score1.setPosition((window->getSize().x / 4) - 50, 100);
	this->score2.setPosition((window->getSize().x / 4) * 3 - 50, 100);
	this->score1.setString("Player 1 : " + std::to_string(p1Score));
	this->score2.setString("Player 2 : " + std::to_string(p2Score));
	this->score1.setFont(font);
	this->score2.setFont(font);
	this->score1.setFillColor(sf::Color::Black);
	this->score2.setFillColor(sf::Color::Black);
	Log::messageLog("Font Loaded");
}


void GameMode::increaseScore(float x) {
	//Log::messageLog("increase score called");
	if (x <= 0)
		p2Score++;
	if (x >= window->getSize().x - 10)
		p1Score++;
}


void GameMode::updateScore() {
	score1.setString("Player 1 : " + std::to_string(p1Score));
	score2.setString("Player 2 : " + std::to_string(p2Score));
}

//Player vs Player 
//From line 37 to 54

PvP::PvP(sf::RenderWindow* wind, sf::VideoMode* resolution) {
	this->window = wind;
	this->ball = new Ball(sf::Vector2f(resolution->width / 2, resolution->height / 2), 15.0f, 1200.0f, window);
	this->paddle1 = new Paddle(sf::Vector2f(20, resolution->height / 2), 2000.0f, window);
	this->paddle2 = new Paddle(sf::Vector2f(resolution->width - 20, resolution->height / 2), 2000.0f, window);
	Log::messageLog("Paddle1 Created");
	Log::messageLog("Paddle2 Created");
	this->initText();
}


void PvP::handleInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		paddle2->movePaddle(-1);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		paddle2->movePaddle(1);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		paddle1->movePaddle(-1);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		paddle1->movePaddle(1);
}



//Player vs CPU
//From line 59 to x

PvC::PvC(sf::RenderWindow* wind, sf::VideoMode* resolution) {
	this->window = wind;
	this->ball = new Ball(sf::Vector2f(resolution->width / 2, resolution->height / 2), 15.0f, 1200.0f, window);
	this->paddle1 = new Paddle(sf::Vector2f(20, resolution->height / 2), 2000.0f, window);
	this->paddle2 = new CpuPaddle(sf::Vector2f(resolution->width - 20, resolution->height / 2), 1000.0f, window, ball);
	Log::messageLog("Paddle1 Created");
	Log::messageLog("Paddle2 Created");
	this->initText();
}

void PvC::handleInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		paddle1->movePaddle(-1);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		paddle1->movePaddle(1);
	paddle2->move();
}
