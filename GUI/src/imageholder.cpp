#include "..\include\imageholder.h"

void ImageHolder::Update()
{
}

void ImageHolder::Render()
{
	if (isPositionRelative) {
		Renderer::Instance().DrawImage(image, father->GetPositionX() + x, father->GetPositionY() + y, 0, width, height);
	}
	else {
		Renderer::Instance().DrawImage(image, x, y, 0, width, height);
	}
}

bool ImageHolder::OnInputEvent(const GUIMessage * message)
{
	return false;
}

void ImageHolder::Register(inputs key, inputs action)
{
}

void ImageHolder::Unregister(inputs key, inputs action)
{
}
