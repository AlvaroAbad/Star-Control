#include "..\include\statbar.h"
#include "../../Comportamientos/include/resourcestore.h"
#include "../../Ugine/include/renderer.h"

StatBar::StatBar(String * btnId, uint8 r, uint8 g, uint8 b, float value) :Control(btnId), r(r), g(g), b(b), value(value){
	hasFocus = false;
	capsule = ResourceStore::Instance().GetCapsuleImage();
}

void StatBar::Render()
{
	Renderer::Instance().SetBlendMode(Renderer::ALPHA);
	Renderer::Instance().SetColor(r, g, b, 255);
	if (isPositionRelative) {
		if (value > 100) {
			for (size_t i = 0; i < 10; i++)
			{
				Renderer::Instance().DrawImage(capsule, father->GetPositionX() + x, (father->GetPositionY() + y+height)-(i*capsule->GetHeight()));
			}
		}
		else {
			for (size_t i = 0; i < value/10; i++)
			{
				Renderer::Instance().DrawImage(capsule, father->GetPositionX() + x, (father->GetPositionY() + y + height) - (i*capsule->GetHeight()));
			}
		}
	}
	else {
		if (value > 100) {
			for (size_t i = 0; i < 10; i++)
			{
				Renderer::Instance().DrawImage(capsule,x, (y + height) - (i*capsule->GetHeight()));
			}
		}
		else {
			for (size_t i = 0; i < value / 10; i++)
			{
				Renderer::Instance().DrawImage(capsule, x, (y + height) - (i*capsule->GetHeight()));
			}
		}
	}
	Renderer::Instance().SetColor(255, 255, 255, 255);
}
