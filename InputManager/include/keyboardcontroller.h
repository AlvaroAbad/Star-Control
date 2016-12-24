#ifndef INPUTMANAGER_KEYBORDCONTROLLER_H
#define INPUTMANAGER_KEYBORDCONTROLLER_H
#pragma warning(disable:4514)
class KeyBoardController
{
public:
	KeyBoardController() {};
	void Init();
	~KeyBoardController() {}
	static void KeyEvent(int button, int action);
private:

};
#endif // !INPUTMANAGER_KEYBORDCONTROLLER_H