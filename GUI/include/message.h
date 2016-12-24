#ifndef GUI_MESSAGE_H
#define GUI_MESSAGE_H

#pragma warning(disable:4514)

class GUIMessage
{
public:
	enum MessageType {
		MOUSE_BUTTON_RELEASE,
		MOUSE_BUTTON_PRESS,
		KEY_RELEASE,
		KEY_PRESS,
		MOUSE_BUTTON_CLICK,
		MOUSE_BUTTON_DOUBLECLICK,
		DRAG,
		SCROLL,
		MOUSE_MOVE
	};
	enum KeyCode {
		KEY_SPECIAL = 256,
		KEY_UP = (KEY_SPECIAL + 27),
		KEY_DOWN = (KEY_SPECIAL + 28),
		KEY_LEFT = (KEY_SPECIAL + 29),
		KEY_RIGHT = (KEY_SPECIAL + 30),
	};
	GUIMessage() {};
	virtual ~GUIMessage() {};
	void SetType(MessageType type) { this->type = type; }
	MessageType GetType() const  { return type; }
private:
	MessageType type;
};

class ClickMessage : public GUIMessage
{
public:
	ClickMessage(double x, double y) : x(x), y(y) { SetType(MOUSE_BUTTON_CLICK); }
	~ClickMessage() {};
	double GetX() const { return x; }
	double GetY() const { return y; }
private:
	double  x, y;
};

class MouseButtonPressedMessage : public GUIMessage
{
public:
	MouseButtonPressedMessage(double x, double y) : x(x), y(y) { SetType(MOUSE_BUTTON_PRESS); }
	~MouseButtonPressedMessage() {};
	double GetX()const { return x; }
	double GetY()const { return y; }
private:
	double x, y;
};

class MouseButtonReleassedMessage : public GUIMessage
{
public:
	MouseButtonReleassedMessage(double x, double y) : x(x), y(y) { SetType(MOUSE_BUTTON_RELEASE); }
	~MouseButtonReleassedMessage() {};
	double GetX()const { return x; }
	double GetY()const { return y; }
private:
	double x, y;
};

class MouseMovementMessage : public GUIMessage
{
public:
	MouseMovementMessage(double x, double y) : x(x), y(y) { SetType(MOUSE_MOVE); }
	~MouseMovementMessage() {};
	double GetX() const { return x; }
	double GetY()const { return y; }
private:
	double x, y;
};

class DragMessage : public GUIMessage
{
public:
	DragMessage(double x, double y) : x(x), y(y) { SetType(DRAG); }
	~DragMessage() {};
	double GetX()const { return x; }
	double GetY()const { return y; }
private:
	double x, y;
};

class KeyPressedMessage : public GUIMessage
{
public:
	KeyPressedMessage(KeyCode key) : key(key){ SetType(KEY_PRESS); }
	~KeyPressedMessage() {};
	int32 GetKey()const { return static_cast<int32>(key); }
private:
	KeyCode key;
};
#endif // !GUI_MESSAGE_H
