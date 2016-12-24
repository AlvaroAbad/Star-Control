#include "../../InputManager/include/eventmanager.h"
#include "../../Ugine/include/math.h"
#include "../../InputManager/include/drag.h"
#include "../../InputManager/include/doubleclic.h"
#include "../../InputManager/include/clic.h"
#include "../../Ugine/include/screen.h"
EventManager* EventManager::manager = nullptr;
EventManager & EventManager::Instance()
{
	if (!manager) {
		manager = new EventManager();
	}
	return *manager;
}

void EventManager::SetMousePosition(int x, int y)
{
	this->mousePosX = x;
	this->mousePosY = y;
	Event * newEvent= new Event(inputs::KEY_UNKNOWN, inputs::MOUSE_MOVEMENT, mousePosX, mousePosY, mouseScrollPosition);
	newEvent->ReduceTimeToSettle(TIME_TO_SETTLE);
	ProcessDrag(&processingEvents);
	processingEvents.Add(*newEvent);
}

void EventManager::addButtonPressed(int button)
{
	keyPressed.Add(button);
	Event * newEvent = new Event((inputs)button, inputs::KEY_PRESS, mousePosX, mousePosY, mouseScrollPosition);
	ProcessDoubleClic((inputs)button, inputs::KEY_PRESS, &processingEvents);
	processingEvents.Add(*newEvent);
}

void EventManager::addButtonReleased(int button)
{
	keyDown.Remove(button);
	KeyReleassed.Add(button);
	EndDrags((inputs)button, &processingEvents);
	ProcessDoubleClic((inputs)button, inputs::KEY_RELEASE, &processingEvents);
	ProcessClic((inputs)button, &processingEvents);
	for (uint32 i = 0; i < processingEvents.Size(); i++)
	{
		if (processingEvents[i].GetKey() == button && processingEvents[i].GetAction() == inputs::KEY_PRESSED_DOWN) {
			processingEvents[i].SetAction(inputs::KEY_RELEASE);
			processingEvents[i].ReduceTimeToSettle(TIME_TO_SETTLE);
			return;
		}
	}
	Event * newEvent = new Event((inputs)button, inputs::KEY_RELEASE, mousePosX, mousePosY, mouseScrollPosition);
	processingEvents.Add(*newEvent);
}

void EventManager::SetMouseScrollPosition(int position)
{
	Event * newEvent = new Event(inputs::KEY_UNKNOWN, inputs::MOUSE_MOVEMENT, mousePosX, mousePosY, position);
	if (this->mouseScrollPosition < position) {
		newEvent->SetAction(inputs::SCROLL_UP);
	}
	else {
		newEvent->SetAction(inputs::SCROLL_DOWN);
	}
	processingEvents.Add(*newEvent);
	this->mouseScrollPosition = position;
}

void EventManager::Register(IRegistrable *element, inputs key, inputs action)
{
	Observator newObesrvator;
	newObesrvator.element = element;
	newObesrvator.observedKey = key;
	newObesrvator.observedAction = action;
	Observators.Add(newObesrvator);

}

void EventManager::Unregister(IRegistrable * element, inputs key, inputs action)
{
	Observator newObesrvator;
	newObesrvator.element = element;
	newObesrvator.observedKey = key;
	newObesrvator.observedAction = action;
	Observators.Remove(newObesrvator);
}

void EventManager::UnregisterAll(IRegistrable * element)
{
	Array<Observator> unregisteringObservators;
	for (size_t i = 0; i < Observators.Size(); i++)
	{
		if (Observators[i].element == element) {
			unregisteringObservators.Add(Observators[i]);
		}
	}
	for (size_t i = 0; i < unregisteringObservators.Size(); i++)
	{
		Observators.Remove(unregisteringObservators[i]);
	}
}


void EventManager::DispachEvents()
{
	Array<Event> processedEvents;

	for (uint32 i = 0; i < processingEvents.Size(); i++)
	{
		if (!processingEvents[i].IsSettled()) {
			if (processingEvents[i].GetAction() == inputs::KEY_PRESS && processingEvents[i].IsNew()) {
				processedEvents.Add(processingEvents[i]);
				processingEvents.Add(processingEvents[i]);
				processingEvents.Last().ReduceTimeToSettle(Screen::Instance().ElapsedTime());
			}
			else {
				processingEvents[i].ReduceTimeToSettle(Screen::Instance().ElapsedTime());
			}
			
		}
		else {
			if(processingEvents[i].GetAction()==inputs::KEY_PRESS || processingEvents[i].GetAction() == inputs::KEY_PRESSED_DOWN){
			processingEvents.Add(processingEvents[i]);
			processingEvents.Last().SetAction(inputs::KEY_PRESSED_DOWN);
			processingEvents.Last().ReduceTimeToSettle(-Screen::Instance().ElapsedTime());
			}
			else if (processingEvents[i].GetAction() == inputs::DRAG) {
				processingEvents.Add(processingEvents[i]);
				processingEvents.Last().ReduceTimeToSettle(-Screen::Instance().ElapsedTime());
				processingEvents.Last().SetMousePos(mousePosX, mousePosY);
				processedEvents.Add(processingEvents[i]);
				processedEvents.Last().SetAction(inputs::KEY_PRESSED_DOWN);

			}
			processedEvents.Add(processingEvents[i]);
		}
	}

	for (uint32 j = 0; j < processedEvents.Size(); j++)
	{
		for (uint32 i = 0; i < Observators.Size(); i++)
		{
			if (processedEvents[j].GetAction() == inputs::SCROLL_DOWN || processedEvents[j].GetAction() == inputs::SCROLL_UP || processedEvents[j].GetAction() == inputs::MOUSE_MOVEMENT) {
				if (processedEvents[j].GetAction() == Observators[i].observedAction) {
					Observators[i].element->OnEvent(&processedEvents[j]);
				}
			}else if (processedEvents[j].GetKey() == Observators[i].observedKey && processedEvents[j].GetAction() == Observators[i].observedAction) {
				Observators[i].element->OnEvent(&processedEvents[j]);
			}
		}
		processingEvents.Remove(processedEvents[j]);
	}

}

EventManager::EventManager()
{
	mousePosX = Screen::Instance().GetMouseX();
	mousePosY = Screen::Instance().GetMouseY();
}

