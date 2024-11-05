#include "Headers/Game.h"
#include "Headers/Collision.h"
#include "Headers/Log.h"
#include <fstream>


GameMode* Game::gameMode = nullptr;
float Game::deltaTime = 0;

Game::Game() {
	this->initWindow();
		
}


void Game::initWindow() {
	std::ifstream windowConfig("config/window.ini");
	if (!windowConfig.is_open()) {
		Log::errorLog("Unable to read from config file.");
		std::exit(0);
	}
	
	std::getline(windowConfig, title);
	windowConfig >> this->resolution.width >> this->resolution.height;
	windowConfig >> this->fps;
	this->window = new sf::RenderWindow(this->resolution, title, sf::Style::Titlebar | sf::Style::Close | sf::Style::Fullscreen);
	Log::messageLog("Window created");
	this->window->setFramerateLimit(this->fps);
	Log::messageLog("Frame limit: 120");
	this->menu = new MainMenu(this->window);
	this->board.loadFromFile("Textures/mainmenu.png");
	sprite.setTexture(board);
	windowConfig.close();
}


Game::~Game() {
	delete this->window;
	gameMode->freeMemory();
	delete gameMode;
	delete menu;
	Log::messageLog("Main Menu Destroyed");
	Log::messageLog("GameMode Destroyed");
	Log::messageLog("Window Destroyed");
}


void Game::startGame() {
	
	
	Log::messageLog("GameLoop Started");
	
	while (window->isOpen()) {
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window->close();
		}
		deltaTime = clock.restart().asSeconds();
		window->clear(sf::Color::Transparent);
		tick();	
		window->display();
	}
	
	Log::messageLog("GameLoop Stopped");
}

GameMode* Game::getCurrentGameMode() {
	return gameMode;
}




void Game::tick() {
	window->draw(sprite);
	this->update();
	if (this->isRunning == 1 || this->isRunning == 2)
		this->gameMode->tick();
	else
		this->menu->tick();
	
}




void Game::update() {
	if (this->isRunning == -1) {
		this->isRunning = menu->getGameMode();

		if (this->isRunning == 1) {
			this->gameMode = new PvP(this->window, &this->resolution);
			board.loadFromFile("Textures/board.png");
			sprite.setTexture(board);
		}
		else if (this->isRunning == 2) {
			this->gameMode = new PvC(this->window, &this->resolution);
			board.loadFromFile("Textures/board.png");
			sprite.setTexture(board);
		}
		
	}

}


float Game::getDeltaTime() {
	return deltaTime;
}




