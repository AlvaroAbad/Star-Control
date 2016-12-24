#ifndef GUI_CONTROL_H
#define GUI_CONTROL_H

#include "../../InputManager/include/event.h"
#include "../../Ugine/include/array.h"
#include "ieventlistener.h"
#include "../../InputManager/include/iregistrable.h"
#include "message.h"
#include "../../Ugine/include/string.h"

#pragma warning(disable:4062)
#pragma warning(disable:4514)
#pragma warning(disable:4820)
#pragma warning(disable:4100)

class Control: public IRegistrable
{
public:

	virtual void OnEvent(const Event * action);
	void InjectMessage(const GUIMessage * message);
	virtual void Update()=0;
	virtual void Render()=0;
	virtual bool OnInputEvent(const GUIMessage * message)=0;
	void SetEventListener(IEventListener* eventListener) { this->eventListener = eventListener; }
	void AddChild(Control * child);
	void SetFocus() { hasFocus = true; }
	void RemoveFocus() { hasFocus = false; }
	bool HasFocus() { return hasFocus; }
	void setPositionType(bool relative) { isPositionRelative = relative; }
	virtual void SetPosition(double x, double y) {
		this->x = x;
		this->y = y;
	}
	virtual double GetPositionX() { return x; }
	virtual double GetPositionY() { return y; }
	virtual void SetDimensions(double width, double height) {
		this->width = width;
		this->height = height;
	}
	virtual double GetWidth() { return width; }
	virtual double GetHeight() { return height; }
	String * GetId() { return &id; }
	Control(String *id) :id(*id) {}
	Control() :id("") {}
	virtual ~Control();

protected:
	Control * father;
	Array<Control *> childs;
	IEventListener* eventListener;
	bool isPositionRelative;
	bool hasFocus;
	double x, y;
	double width, height;
	String id;
};
#endif // !GUI_CONROL_H

