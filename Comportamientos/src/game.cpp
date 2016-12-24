#include "../include/game.h"
#include "../include/userinterface.h"
#include "../include/world.h"
#include "../include/userinterface.h"
Game::~Game()
{
	delete world;
	delete ui;
}
void Game::initialize()
{
	world = new World();
	world->Init();
	ui = new UserInterface(world);
	ui->Init();
}
void Game::run()
{
	world->run();
	ui->run();
}
void Game::draw() const
{
	world->draw();
	ui->draw();
}
void Game::getInput()
{
	ui->getInputs();
}

bool Game::isGameEnd()
{
	return world->isGameEnd();
}
