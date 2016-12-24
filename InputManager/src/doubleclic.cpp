#include "../../InputManager/include/doubleclic.h"

void ProcessDoubleClic(const inputs key, inputs trigger, Array<Event>* processingEvents)
{
	for (uint32 i = 0; i < (*processingEvents).Size(); i++)
	{
		if ((*processingEvents)[i].GetKey() == key && (*processingEvents)[i].GetAction() == inputs::CLICK) {
			if ((*processingEvents)[i].GetAction() == inputs::CLICK && trigger ==inputs::KEY_PRESS) {
				(*processingEvents)[i].SetAction(inputs::DOUBLE_CLICK);
				(*processingEvents)[i].resetTimer();
			}
			else if ((*processingEvents)[i].GetAction() == inputs::DOUBLE_CLICK && trigger == inputs::KEY_RELEASE) {
				(*processingEvents)[i].ReduceTimeToSettle(TIME_TO_SETTLE);
			}
			return;
		}
	}
}
