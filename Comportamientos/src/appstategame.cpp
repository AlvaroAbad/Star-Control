#include "..\include\appstategame.h"
#include "../include/game.h"
#include "../include/externs.h"
extern Game *game;

void AppStateGame::run()
{
	game->run();
	if (game->isGameEnd()) {
		whantedState = STATE_ENDGAME;
	}
}

void AppStateGame::draw() const
{
	game->draw();
}

void AppStateGame::getInputs()
{
	game->getInput();
}

void AppStateGame::activate()
{
	if (!game) {
		game = new Game();
		game->initialize();
	}
}

void AppStateGame::deactivate()
{

}
