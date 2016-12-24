#ifndef GUI_IEVENTLISTENER_H
#define GUI_IEVENTLISTENER_H

class Control;
class IEventListener
{
public:
	virtual void OnClick(Control* sender);
	virtual void OnGotFocus(Control* sender);
	virtual void OnLostFocus(Control* sender);
	virtual void OnKeyDown(Control* sender);
	virtual void OnKeyUp(Control* sender);

	IEventListener();
	virtual ~IEventListener();
};

#endif // !GUI_IEVENTLISTENER_H
