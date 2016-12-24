#ifndef GUI_DROPDOWNLISTBUTTON_H
#define GUI_DROPDOWNLISTBUTTON_H

#include "button.h"

class DropDownListButton : public Button
{
public:
	DropDownListButton(String *btnId, String * text, Image * activeImage, Image * hooverImage = nullptr) :Button(btnId,activeImage,NULL,hooverImage){
		SetText(*text);
		disabled = false;
	}
	virtual void Render();
	virtual bool OnInputEvent(const GUIMessage * message);
	virtual bool isDisabled() { return disabled; }
	virtual void disable() { disabled = true; }
	virtual void enable() { disabled = false; }
	virtual String * GetValue() { return &text; }
	~DropDownListButton() {};

private:
	bool disabled;
};
#endif //!GUI_DROPDOWNLISTBUTTON_H
