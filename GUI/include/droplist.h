#ifndef GUI_DROPLIST_H
#define GUI_DROPLIST_H

#include "control.h"
#include "../../Ugine/include/image.h"
class Button;
class DropDownListButton;
class DropList : public Control, IEventListener
{
public:
	DropList(String * btnId, double x, double y, double width);

	virtual void Update();
	virtual void Render();
	virtual bool OnInputEvent(const GUIMessage * message);
	virtual void Register(inputs key, inputs action);
	virtual void Unregister(inputs key, inputs action);
	virtual void Unregister() {}
	virtual void AddOption(String *opt);
	virtual void setSelection(DropDownListButton * selection);
	void OnClick(Control * sender);
	~DropList();
	virtual String * GetSelectedValue();

private:
	Button * dropdown;
	DropDownListButton * selected;
	Array<DropDownListButton *> options;
	bool deployed;
};
#endif //!GUI_DROPLIST_H
