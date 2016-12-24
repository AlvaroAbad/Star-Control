#ifndef GUI_IMAGEHOLDER_H
#define GUI_IMAGEHOLDER_H

#include "control.h"
#include "../../Ugine/include/image.h"

class ImageHolder : public Control
{
public:
	ImageHolder(String * btnId, Image * image, float posX, float posY, float width, float height)
		:Control(btnId), image(image){
		hasFocus = false;
		SetPosition(posX, posY);
		SetDimensions(width, height);
	}

	virtual void Update();
	virtual void Render();
	virtual bool OnInputEvent(const GUIMessage * message);
	virtual void Register(inputs key, inputs action);
	virtual void Unregister(inputs key, inputs action);
	virtual void Unregister() {}

	~ImageHolder() {};

protected:
	Image * image;

};
#endif //!GUI_IMAGEHOLDER_H
