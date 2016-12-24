#ifndef WORLDDEFENDER_APP_STATES_H
#define WORLDDEFENDER_APP_STATES_H
enum enumAppStates {
	STATE_NULL,
	STATE_MAINMENU,
	STATE_PREGAMEMENU,
	//STATE_OPTIONS,
	STATE_GAME,
	//STATE_PAUSE,
	STATE_ENDGAME
};
class AppState
{
public:
	
	virtual ~AppState() {};
	 void virtual run() =0;
	 void virtual draw() const = 0;
	 void virtual getInputs() = 0;
	 void virtual activate()  = 0;
	 void virtual deactivate() = 0;
	 void setState(enumAppStates state) { this->state = state; }
	 enumAppStates getState() const { return this->state; }
private:
	enumAppStates state;
};
#endif
