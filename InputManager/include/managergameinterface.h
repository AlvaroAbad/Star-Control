#ifndef INPUTMANAGER_MANAGERGAMEINTERFACE_H
#define INPUTMANAGER_MANAGERGAMEINTERFACE_H
#include "iregistrable.h"
namespace ManagerGameInterface {
	void Register(IRegistrable *element, inputs key, inputs action);
	void Unregister(IRegistrable *element, inputs key, inputs action);
	void UnregisterAll(IRegistrable *element);
}
#endif // !INPUTMANAGER_MANAGERGAMEINTERFACE_H
