#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class MainMenu {
private:
	int option;
	sf::RenderWindow* window;
	
	sf::Text start;
	sf::Text exit;
	sf::Font font;
	

public:
	MainMenu(sf::RenderWindow* wind);
	void draw();
	void handleInput();
	void tick();

	sf::Vector2f startLocation;
	sf::Vector2f exitLocation;
	sf::RectangleShape rectangle;
	int getGameMode();
};


