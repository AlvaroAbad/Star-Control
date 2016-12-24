#ifndef GUI_WINDOW_H
#define GUI_WINDOW_H
#include "control.h"
#include "../../Ugine/include/image.h"
class Window: public Control
{
public:
	virtual void Update();
	virtual void Render();
	virtual bool OnInputEvent(const GUIMessage * message);
	virtual void Register(inputs key, inputs action);
	virtual void Unregister(inputs key, inputs action);
	virtual void Unregister();
	Window(Image * image):image(image) {}
	~Window();

private:
	struct RegisteredEvents {
		inputs key, action;
		inline bool operator!=(const RegisteredEvents& other) {
			return this->key != other.key
				|| this->action != other.action;
		}
		inline bool operator==(const RegisteredEvents& other) {
			return this->key == other.key
				&& this->action == other.action;
		}
	};
	Image * image;
	Array<RegisteredEvents> registeredEvents;
};
#endif // !GUI_WINDOW_H

