#ifndef GUI_IMAGESELECTOR_H
#define GUI_IMAGESELECTOR_H

#include "control.h"

class Image;
class ImageSelector : public Control
{
public:
	ImageSelector(String* btnId, double imageWidth, double imageHeight, double margin, Image * Background = nullptr) :Control(btnId),
		imageWidth(imageWidth), imageHeight(imageHeight), margin(margin), Background(Background) {
		selectedImage = -1;
		hasFocus = false;
	}

	virtual void Update();
	virtual void Render();
	virtual bool OnInputEvent(const GUIMessage * message);
	virtual void Register(inputs key, inputs action);
	virtual void Unregister(inputs key, inputs action);
	virtual void Unregister() {}
	virtual void AddImage(Image * item);
	virtual void SetDimensions(double width, double height) {
		Control::SetDimensions(width, height);
		maxColumns = static_cast<unsigned int>(width / (imageWidth + (2 * margin)));
		maxRows = static_cast<unsigned int>(height / (imageHeight + (2 * margin)));
	}
	virtual Image * GetSelectedImage() {
		if(selectedImage>-1){
		return images[static_cast<uint32>(selectedImage)].item;
		}
		else {
			return nullptr;
		}
	}
	~ImageSelector() {};

private:
	struct imageHolder {
		double posX, posY;
		Image * item;
	};
	Image * Background;
	Array<imageHolder> images;
	double imageWidth, imageHeight, margin;
	uint32 maxRows, maxColumns;
	int32 selectedImage;
};
#endif //!GUI_IMAGESELECTOR_H