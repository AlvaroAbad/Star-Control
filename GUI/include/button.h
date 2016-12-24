#ifndef GUI_BUTTON_H
#define GUI_BUTTON_H

#include "control.h"
#include "../../Ugine/include/image.h"

class Button : public Control
{
public:
	Button(String * btnId, Image * activeImage, Image * pressedImage = nullptr, Image * hooverImage = nullptr, Image * disabledImage = nullptr) :Control(btnId),
		currentImage(activeImage), activeImage(activeImage), pressedImage(pressedImage), disabledImage(disabledImage), hooverImage(hooverImage) {
		hasFocus = false;
	}

	virtual void Update();
	virtual void Render();
	virtual bool OnInputEvent(const GUIMessage * message);
	virtual void Register(inputs key, inputs action);
	virtual void Unregister(inputs key, inputs action);
	virtual void Unregister() {}
	virtual void SetText(String text) {
		this->text = text;
	}
	
	~Button() {};

protected:
	Image * currentImage;
	Image * activeImage;
	Image * pressedImage;
	Image * disabledImage;
	Image * hooverImage;
	String text;
};
#endif //!GUI_BUTTON_H
