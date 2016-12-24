#ifndef SCM_PREGAMEMENU_H
#define SCM_PREGAMEMENU_H

#include "appState.h"
#include "../../GUI/include/ieventlistener.h"
class Window;
class DropList;
class ImageSelector;
class AppStatePreGameMenu :public AppState, IEventListener
{
public:
	AppStatePreGameMenu() {
		this->setState(STATE_PREGAMEMENU);
		window = nullptr;
	};
	~AppStatePreGameMenu();
	void virtual run();
	void virtual draw() const;
	void virtual getInputs();
	void virtual activate();
	void virtual deactivate();
	void OnClick(Control * sender);
private:
	Window * window;
	DropList * dlP1Settings, *dlP2Settings;
	ImageSelector * Player1ShipoSlector, *Player2ShipoSlector;
};

#endif // !SCM_PREGAMEMENU_H
