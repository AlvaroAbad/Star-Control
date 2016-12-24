#ifndef INPUTMANAGER_EVENTMANAGER_H
#define INPUTMANAGER_EVENTMANAGER_H
#include "../../Ugine/include/array.h"
#include "iregistrable.h"
#include "eventmanagerinputdefinitions.h"
#include "event.h"
#include "keyboardcontroller.h"
#include "mousecontroller.h"
static class EventManager
{
public:
	static EventManager& Instance();
	void SetMousePosition(const int x, const int y);
	int GetMouseX() { return this->mousePosX; }
	int GetMouseY() { return this->mousePosY; }
	void addButtonPressed(int button);
	void addButtonReleased(int button);
	void SetMouseScrollPosition(int position);
	int GetMouseScrollPosition() {
		return this->mouseScrollPosition;
	}
	void Register(IRegistrable* element, inputs key, inputs action);
	void Unregister(IRegistrable* element, inputs key, inputs action);
	void UnregisterAll(IRegistrable* element);
	void DispachEvents();
protected:
	EventManager();
	~EventManager() {};
	
private:
	struct Observator {
		IRegistrable *element;
		inputs observedKey;
		inputs observedAction;
		inline bool operator==(const Observator& other) {
			return this->observedKey == other.observedKey 
				&& this->observedAction == other.observedAction
				&& this->element == other.element;
		}
	};
	/*Properties*/
	static EventManager* manager;
	int mousePosX, mousePosY, mouseScrollPosition;
	bool mousePosChanged, mouseScrollChanged;
	Array<int> keyPressed;
	Array<int> keyDown;
	Array<int> KeyReleassed;
	Array<Observator> Observators;
	Array<Event> processingEvents;
};
#endif // !INPUTMANAGER_EVENTMANAGER_H