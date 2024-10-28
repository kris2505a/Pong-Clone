#pragma once
#include "Headers/Ball.h"
#include "Headers/Paddle.h"
#include "Headers/CpuPaddle.h"
#include <SFML/Window.hpp>

class GameMode {

protected: //variables
	Paddle* paddle1{ nullptr };
	Paddle* paddle2{ nullptr };
	Ball* ball{ nullptr };
	sf::RenderWindow* window;
	int p1Score{ 0 }, p2Score{0};
	sf::Text score1, score2;
	sf::Font font;


protected: // functions
	virtual void handleInput() = 0;
	virtual void draw();
	virtual void update();
	

public:
	virtual void tick();
	void freeMemory();
	void increaseScore(float x);
	void initText();
	void updateScore();
	
};





class PvP : public GameMode {
protected:
	virtual void handleInput() override;


public:
	PvP(sf::RenderWindow* wind, sf::VideoMode* resolution);


	
};

class PvC : public GameMode {
protected:
	virtual void handleInput() override;


public:
	PvC(sf::RenderWindow* wind, sf::VideoMode* resolution);

};

