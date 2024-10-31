#include "Headers/MainMenu.h"
#include "Headers/Log.h"

MainMenu::MainMenu(sf::RenderWindow* wind) {
	this->window = wind;
	this->start.setString("PLAYER VS PLAYER");
	this->exit.setString("PLAYER VS COMPUTER");
	if (!font.loadFromFile("Textures/dungeon.TTF"))
		Log::errorLog("Failed To Load Font");
	this->start.setPosition((window->getSize().x / 2 - 180), (window->getSize().y / 2) - 100);
	this->exit.setPosition((window->getSize().x / 2 - 180), (window->getSize().y / 2) + 100);
	this->start.setFont(font);
	this->exit.setFont(font);
	Log::messageLog("Menu Created");
	rectangle.setFillColor(sf::Color::Transparent);
	rectangle.setOutlineColor(sf::Color::Red);
	rectangle.setSize(sf::Vector2f(400, 100));
	rectangle.setOutlineThickness(5);
	rectangle.setPosition((window->getSize().x / 2 - 200), (window->getSize().y / 2) - 130);
	this->startLocation = sf::Vector2f((window->getSize().x / 2 - 200), (window->getSize().y / 2) - 130);
	this->exitLocation = sf::Vector2f((window->getSize().x / 2 - 200), (window->getSize().y / 2) + 70);
}


void MainMenu::draw() {
	this->window->draw(this->start);
	this->window->draw(this->exit);
	this->window->draw(this->rectangle);
}


void MainMenu::handleInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		rectangle.setPosition(startLocation);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		rectangle.setPosition(exitLocation);
}


void MainMenu::tick() {
	this->draw();
	this->handleInput();
}



int MainMenu::getGameMode() {
	if (rectangle.getPosition() == startLocation && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		return (int)1;
	else if (rectangle.getPosition() == exitLocation && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		return (int)2;
	else return (int)-1;
	//return 1;

}

