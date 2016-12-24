#include "..\include\imageselector.h"
#include "../../Ugine/include/image.h"
#include "../../Ugine/include/renderer.h"
#include "../../GUI/include/message.h"
#include "../../Ugine/include/math.h"

void ImageSelector::Update()
{
}

void ImageSelector::Render()
{

	if (Background) {
		if (isPositionRelative) {
			Renderer::Instance().DrawImage(Background, father->GetPositionX() + x, father->GetPositionY() + y, 0, width, height);
		}
		else {
			Renderer::Instance().DrawImage(Background, x, y, 0, width, height);
		}
	}
	for (unsigned int i = 0; i < images.Size(); i++)
	{
		if(selectedImage>-1){
		if (static_cast<unsigned int>(selectedImage) == i) {
			Renderer::Instance().SetColor(255, 255, 255, 255);
			Renderer::Instance().DrawRect(father->GetPositionX() + x + images[i].posX , father->GetPositionY() + y + images[i].posY, imageWidth , imageHeight);
		}
		}
		Renderer::Instance().DrawImage(images[i].item, father->GetPositionX() + x + images[i].posX, father->GetPositionY() + y + images[i].posY, 0, imageWidth, imageHeight);
	}
}

bool ImageSelector::OnInputEvent(const GUIMessage * message)
{
	double trueX, trueY;
	unsigned int row, column;
	trueX = x;
	trueY = y;
	if (isPositionRelative) {
		trueX += father->GetPositionX();
		trueY += father->GetPositionY();
	}
	bool used = false;
	switch (message->GetType())
	{
	case GUIMessage::MOUSE_BUTTON_CLICK:
	{
		
		const ClickMessage * mouseClick = static_cast<const ClickMessage *>(message);
		
		double posX, posY;
		if (isPositionRelative) {
			posX = father->GetPositionX() + x;
			posY = father->GetPositionY() + y;
		}
		else {
			posX = x;
			posY = y;
		}		
		if (PointInRect(mouseClick->GetX(), mouseClick->GetY(), posX, posY, width, height)) {
			trueX = mouseClick->GetX() - father->GetPositionX() - x;
			trueY = mouseClick->GetY() - father->GetPositionY() - y;
			column = static_cast<unsigned int>(trueX / (imageWidth + 2 * margin));
			row = static_cast<unsigned int>(trueY / (imageHeight + 2 * margin));
			if (column < maxColumns && row < maxRows && row*maxColumns + column < images.Size()) {
				selectedImage = static_cast<int>(row*maxColumns + column);
				used = true;
			}
			hasFocus = true;
		}
		else {
			hasFocus = false;
		}
		
	}
	break;
	case GUIMessage::KEY_PRESS:
		if (hasFocus) {
			const KeyPressedMessage * keyPressed = static_cast<const KeyPressedMessage *>(message);
			if (keyPressed->GetKey() == GUIMessage::KEY_LEFT) {
				if(selectedImage>0){
				selectedImage--;
				}
				used = true;
			}
			else if (keyPressed->GetKey() == GUIMessage::KEY_RIGHT) {
				if(selectedImage<static_cast<int>(images.Size())-1){
				selectedImage++;
				}
				used = true;
			}
		}
	}
	return used;
}

void ImageSelector::Register(inputs key, inputs action)
{
	if (father) {
		father->Register(key, action);
	}
}

void ImageSelector::Unregister(inputs key, inputs action)
{
	if (father) {
		father->Unregister(key, action);
	}
}

void ImageSelector::AddImage(Image * item)
{
	images.Add(imageHolder());
	images.Last().item = item;
	if (images.Size() > 1) {
		if (!(images.Size() % maxColumns)) {
			images.Last().posX = margin;
			images.Last().posY = images[images.Size() - 2].posY + imageHeight + margin;
		}
		else {
			images.Last().posX = images[images.Size() - 2].posX + imageWidth + margin;
			images.Last().posY = images[images.Size() - 2].posY;
		}
	}
	else {
		images.Last().posX = margin;
		images.Last().posY = margin;
	}

}
