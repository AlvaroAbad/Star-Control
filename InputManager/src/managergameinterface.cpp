#include "../../InputManager/include/managergameinterface.h"
#include "../../InputManager/include/eventmanager.h"
void ManagerGameInterface::Register(IRegistrable *element, inputs key, inputs action)
{
	EventManager::Instance().Register(element,key, action);
}

void ManagerGameInterface::Unregister(IRegistrable * element, inputs key, inputs action)
{
	EventManager::Instance().Unregister(element, key, action);
}

void ManagerGameInterface::UnregisterAll(IRegistrable * element)
{
	EventManager::Instance().UnregisterAll(element);
}

