#ifndef INPUTMANAGER_EVENT_H
#define INPUTMANAGER_EVENT_H
#define TIME_TO_SETTLE 0.1f
#include "eventmanagerinputdefinitions.h"
#pragma warning(disable:4820)
#pragma warning(disable:4514)
class Event {
public:
	Event() {};
	Event(const inputs key, const inputs action, const double mousePosX,
		const double mousePosY, const double mouseScrollPosition)
		:key(key), action(action), mousePosX(mousePosX),
		mousePosY(mousePosY), mouseScrollPosition(mouseScrollPosition),
		TimeToSettle(TIME_TO_SETTLE){};
	~Event() {};
	void SetAction(const inputs action) { this->action = action; }
	void SetMousePos(const double mousePosX, const double mousePosY) {
		this->mousePosX = mousePosX;
		this->mousePosY = mousePosY;
	}
	void ReduceTimeToSettle(const double reduction) { TimeToSettle -= reduction;}
	void resetTimer() { TimeToSettle = TIME_TO_SETTLE; }
	inputs GetKey() const { return key; }
	inputs GetAction() const { return action; }
	double GetMousePosX() const { return mousePosX; }
	double GetMousePosY() const { return mousePosY; }
	double GetMouseScrollPosition() const { return mouseScrollPosition; }
	bool IsSettled() const { return TimeToSettle <= 0; }
	bool IsNew() const { return TimeToSettle == TIME_TO_SETTLE; }
	inline bool operator==(const Event& other) {
		return this->key == other.key && this->action == other.action;
	}
private:
	inputs key;
	inputs action;
	double mousePosX, mousePosY, mouseScrollPosition;
	double TimeToSettle;
};
#endif //!INPUTMANAGER_EVENT_H
