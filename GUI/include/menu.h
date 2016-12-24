#ifndef GUI_MENU_H
#define GUI_MENU_H
#include "control.h"
#include "../../Ugine/include/image.h"
class Menu : public Control
{
public:
	virtual void Update();
	virtual void Render();
	virtual bool OnInputEvent(const GUIMessage * message);
	virtual void Register(inputs key, inputs action);
	virtual void Unregister(inputs key, inputs action);
	virtual void Unregister() {}
	Menu(String * mId, Image * image) :Control(mId), image(image) {}
	~Menu();

private:
	Image * image;
};
#endif // !GUI_MENU_H
