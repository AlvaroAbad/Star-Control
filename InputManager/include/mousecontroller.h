#ifndef INPUTMANAGER_MOUSECONTROLLER_H
#define INPUTMANAGER_MOUSECONTROLLER_H
#pragma warning(disable:4514)
class MouseController
{
public:
	MouseController() {};
	void Init();
	~MouseController() {}
	static void CursorPosition(int xpos, int ypos);
	static void MouseButtonEvent(int button, int action);
	static void MouseScrollEvent(int pos);
private:

};
#endif // !INPUTMANAGER_MOUSECONTROLLER_H