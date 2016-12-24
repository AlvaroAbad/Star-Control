#include "../../InputManager/include/keyboardcontroller.h"
#include "../../Ugine/include/glinclude.h"
#include "../../InputManager/include/managercontrolerInteface.h"

void KeyBoardController::Init()
{
	glfwSetKeyCallback(&KeyEvent);
}

void KeyBoardController::KeyEvent(int button, int action)
{
	if(action==GLFW_PRESS){
		ManagerControlerInterface::addKeyPressed(button);
	}
	else {
		ManagerControlerInterface::addKeyReleased(button);
	}
}
