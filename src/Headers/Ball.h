#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>



class Ball {
private: //properties
	sf::CircleShape circle;
	sf::Vector2f location;
	sf::Vector2f speed;
	sf::RenderWindow* window;

private: // private functions
	void resetBall();
	
public: //constructor / destructor
	Ball(sf::Vector2f loc, float rad, float speedvar, sf::RenderWindow* wind);
	~Ball();
	sf::CircleShape getCircle() const;

public: //public functions
	void draw();
	void update();
	void bounce();
	sf::Vector2f getLocation();
	
	

};

