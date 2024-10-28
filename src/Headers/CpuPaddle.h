#pragma once
#include "Headers/Paddle.h"
#include "Headers/Ball.h"


class CpuPaddle : public Paddle {
	
private:
	class Ball* ball;

public:
	CpuPaddle(sf::Vector2f loc, float sp, sf::RenderWindow* wind, Ball* balll);
	virtual void movePaddle(int n) override;
	virtual void move() override;
};