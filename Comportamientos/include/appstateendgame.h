#ifndef SCM_APPENDGAME_H
#define SCM_APPENDGAME_H

#include "appState.h"
#include "../../GUI/include/ieventlistener.h"
class Window;
class AppStateEndGame :public AppState, IEventListener
{
public:
	AppStateEndGame() {
		this->setState(STATE_ENDGAME);
	}

	void virtual run();
	void virtual draw() const;
	void virtual getInputs();
	void virtual activate();
	void virtual deactivate();
	void OnClick(Control * sender);

	~AppStateEndGame();
private:
	Window * window;
};

#endif // !SCM_APPENDGAME_H
