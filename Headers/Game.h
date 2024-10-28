	#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Headers/GameMode.h"
#include "Headers/MainMenu.h"



class Game {
private:
	sf::RenderWindow* window{ nullptr };
	sf::VideoMode resolution{ 0, 0 };
	sf::Event event;
	static GameMode* gameMode;
	MainMenu* menu;
	int fps{ 120 };
	//bool isRunning { false };
	int isRunning{ -1 };
	sf::Texture board;
	sf::Sprite sprite;

private:

	void tick();
	void update();
	void initWindow();



public:
	void startGame();
	static GameMode* getCurrentGameMode();
	Game();
	~Game();


	
};

