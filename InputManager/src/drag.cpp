#include "../../InputManager/include/drag.h"

void ProcessDrag(Array<Event>* processingEvents)
{
	for (uint32 i = 0; i < processingEvents->Size(); i++)
	{
		if ((*processingEvents)[i].GetKey() <= inputs::MOUSE_BUTTON_LAST
			&& ((*processingEvents)[i].GetAction() == inputs::KEY_PRESS
			|| (*processingEvents)[i].GetAction() == inputs::KEY_PRESSED_DOWN)) {
			(*processingEvents)[i].SetAction(inputs::DRAG);
			(*processingEvents)[i].ReduceTimeToSettle(TIME_TO_SETTLE);
		}
	}
}

void EndDrags(inputs button, Array<Event>* processingEvents)
{
	for (uint32 i = 0; i < processingEvents->Size(); i++)
	{
		if ((*processingEvents)[i].GetKey() == button && (*processingEvents)[i].GetAction() == inputs::DRAG) {
			(*processingEvents)[i].SetAction(inputs::KEY_RELEASE);
			(*processingEvents)[i].ReduceTimeToSettle(TIME_TO_SETTLE);
			return;
		}
	}
}
