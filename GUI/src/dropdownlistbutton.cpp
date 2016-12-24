#include "..\include\dropdownlistbutton.h"
#include "../../Ugine/include/math.h"
#include "../../Comportamientos/include/resourcestore.h"
#include "../../Ugine/include/ttffont.h"
#include "../../GUI/include/droplist.h"

void DropDownListButton::Render()
{
		Renderer::Instance().DrawImage(currentImage, father->GetPositionX() + x, father->GetPositionY() + y, 0, width, height);
		Renderer::Instance().SetColor(0, 255, 0, 255);
		ResourceStore::Instance().GetDropDownFont()->Render(text, father->GetPositionX() + x + 10, father->GetPositionY() + y + 10);
		Renderer::Instance().SetColor(255, 255, 255, 255);
	
}

bool DropDownListButton::OnInputEvent(const GUIMessage * message)
{
	double trueX, trueY;
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
		const ClickMessage * mouseMovement = static_cast<const ClickMessage *>(message);
		if (PointInRect(mouseMovement->GetX(), mouseMovement->GetY(), trueX, trueY, width, height)) {
			static_cast<DropList *>(father)->setSelection(this);
			disabled = true;
			used = true;
		}
		
	}
		break;
	case GUIMessage::MOUSE_MOVE:
	{
		const MouseMovementMessage * mouseMovement = static_cast<const MouseMovementMessage *>(message);
		if (PointInRect(mouseMovement->GetX(), mouseMovement->GetY(), trueX, trueY, width, height)) {
			currentImage = hooverImage;
			used = true;
		}
		else {
			currentImage = activeImage;
		}
	}
		break;
	}
	return used;
}
