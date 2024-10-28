#include "Headers/CpuPaddle.h"


CpuPaddle::CpuPaddle(sf::Vector2f loc, float sp, sf::RenderWindow* wind, Ball* balll) 
	:Paddle(loc, sp, wind) {
	
	this->ball = balll;
}
void CpuPaddle::movePaddle(int n) {
	this->location.y += speed * n;
	this->rectangle.setPosition(location);
	this->limitPaddle();
}


void CpuPaddle::move() {
	int movementConst{ 0 };
	if (ball->getLocation().y < this->location.y + 50)
		movementConst = -1;
	else
		movementConst = 1;
	movePaddle(movementConst);
}