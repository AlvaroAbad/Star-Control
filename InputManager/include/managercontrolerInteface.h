#ifndef INPUTMANAGER_MANAGERCONTROLLERINTERFACE_H
#define INPUTMANAGER_MANAGERCONTROLLERINTERFACE_H
namespace ManagerControlerInterface{
	void setMousePosition(int x, int y);
	void addMouseButtonDown(int button);
	void addMouseButtonUp(int button);
	void addMouseScrollPosition(int pos);
	void addKeyPressed(int button);
	void addKeyReleased(int button);
}
#endif //!INPUTMANAGER_MANAGERCONTROLLERINTERFACE_H