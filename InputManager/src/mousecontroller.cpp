#include "../../InputManager/include/mousecontroller.h"
#include "../../Ugine/include/glinclude.h"
#include "../../InputManager/include/managercontrolerInteface.h"

void MouseController::Init()
{
	glfwSetMousePosCallback(&CursorPosition);
	glfwSetMouseButtonCallback(&MouseButtonEvent);
	glfwSetMouseWheelCallback(&MouseScrollEvent);
}

void MouseController::CursorPosition(int xpos, int ypos)
{
	ManagerControlerInterface::setMousePosition(xpos, ypos);
}

void MouseController::MouseButtonEvent(int button, int action)
{
	if (action == GLFW_PRESS) {
		ManagerControlerInterface::addMouseButtonDown(button);
	}
	else {
		ManagerControlerInterface::addMouseButtonUp(button);
	}
}

void MouseController::MouseScrollEvent(int pos)
{
	ManagerControlerInterface::addMouseScrollPosition(pos);
}
