#ifndef SCM_APPGAME_H
#define SCM_APPGAME_H

#include "appState.h"
class Window;
class AppStateGame :public AppState
{
public:
	AppStateGame() {
		this->setState(STATE_GAME);
	}

	void virtual run();
	void virtual draw() const;
	void virtual getInputs();
	void virtual activate();
	void virtual deactivate();

	~AppStateGame() { }
};

#endif // !SCM_APPGAME_H

