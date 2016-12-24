#include "../../InputManager/include/managercontrolerInteface.h"
#include "../../InputManager/include/eventmanager.h"
void ManagerControlerInterface::setMousePosition(int x, int y)
{
	EventManager::Instance().SetMousePosition(x,y);
}

void ManagerControlerInterface::addMouseButtonDown(int button)
{
	EventManager::Instance().addButtonPressed(button);
}

void ManagerControlerInterface::addMouseButtonUp(int button)
{
	EventManager::Instance().addButtonReleased(button);
}

void ManagerControlerInterface::addMouseScrollPosition(int pos)
{
	EventManager::Instance().SetMouseScrollPosition(pos);
}

void ManagerControlerInterface::addKeyPressed(int button)
{
	EventManager::Instance().addButtonPressed(button);
}

void ManagerControlerInterface::addKeyReleased(int button)
{
	EventManager::Instance().addButtonReleased(button);
}
