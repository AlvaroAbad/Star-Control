#ifndef SCM_MAINMENU_H
#define SCM_MAINMENU_H

#include "appState.h"
#include "../../GUI/include/ieventlistener.h"
class Window;
class AppStateMainMenu:public AppState, IEventListener
{
public:
	AppStateMainMenu() {
		this->setState(STATE_MAINMENU);
		window = nullptr;
	};
	~AppStateMainMenu();
	void virtual run();
	void virtual draw() const;
	void virtual getInputs();
	void virtual activate();
	void virtual deactivate();
	void OnClick(Control * sender);
private:
	Window * window;
};

#endif // !SCM_MAINMENU_H

