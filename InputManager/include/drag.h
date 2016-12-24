#ifndef INPUTMANAGER_DRAG_H
#define INPUTMANAGER_DRAG_H
#include "event.h"
#include "../../Ugine/include/array.h"
void ProcessDrag(Array<Event> * processingEvents);
void EndDrags(inputs button, Array<Event> * processingEvents);
#endif //!INPUTMANAGER_DRAG_H
