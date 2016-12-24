#include "../../InputManager/include/clic.h"

void ProcessClic(const inputs key, Array<Event>* processingEvents)
{
	for (uint32 i = 0; i < (*processingEvents).Size(); i++)
	{
		if ((*processingEvents)[i].GetKey() == key && (*processingEvents)[i].GetAction() == inputs::KEY_PRESS) {
			(*processingEvents)[i].SetAction(inputs::CLICK);
			(*processingEvents)[i].resetTimer();
			return;
		}
	}
}
