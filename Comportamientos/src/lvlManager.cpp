#include "../include/lvlManager.h"
#include "../../Ugine/include/string.h"
LevelManager * LevelManager::levelManager = NULL;
LevelManager & LevelManager::Instance()
{
	if (!levelManager)
		levelManager = new LevelManager();
	return *levelManager;
}

