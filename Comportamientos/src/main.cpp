#include "../include/appState.h"
#include "../include/appstatemainmenu.h"
#include "../include/appstatepregamemenu.h"
#include "../include/appstategame.h"
#include "../include/appstateendgame.h"
#include "../../Ugine/include/screen.h"
#include "../../Ugine/include/renderer.h"
#include "../../Ugine/include/resourcemanager.h"
#include "../../Ugine/include/audioengine.h"
#include "../../InputManager/include/keyboardcontroller.h"
#include "../../InputManager/include/mousecontroller.h"
#include "../../InputManager/include/eventmanager.h"
#include "../include/game.h"
AppState *currentState = nullptr;
enumAppStates whantedState = STATE_MAINMENU;
Game *game = nullptr;
AppState * newAppState(enumAppStates state) {
	switch (state)
	{
	case STATE_MAINMENU:
		return new AppStateMainMenu();
		break;
	case STATE_PREGAMEMENU:
		return new AppStatePreGameMenu();
		break;
	case STATE_GAME:
		return new AppStateGame();
		break;
	case STATE_ENDGAME:
		return new AppStateEndGame();
		break;
	case STATE_NULL:
	default:
		return nullptr;
		break;
	}
}
int main(int, char*) {
	Screen::Instance().Open(800, 600, false);
	AudioEngine::Instance().Init();
	MouseController mouseControler;
	mouseControler.Init();
	KeyBoardController keybordControler;
	keybordControler.Init();
	srand(NULL);
	while (whantedState) {
		if (!currentState || currentState->getState() != whantedState) {
			if (currentState) {
				currentState->deactivate();
				delete(currentState);
			}
			currentState = newAppState(whantedState);
			currentState->activate();
		}
		EventManager::Instance().DispachEvents();
		currentState->run();
		currentState->draw();
		currentState->getInputs();
		Screen::Instance().Refresh();
		Renderer::Instance().Clear(0, 0, 0);
	}
	ResourceManager::Instance().FreeResources();
}