#include "..\include\menu.h"

void Menu::Update()
{
	for (unsigned int i = 0; i < childs.Size(); i++)
	{
		childs[i]->Update();
	}
}

void Menu::Render()
{
	if (image) {
		Renderer::Instance().SetBlendMode(Renderer::ALPHA);
		if (isPositionRelative) {
			Renderer::Instance().DrawImage(image, father->GetPositionX() + x, father->GetPositionY() + y, 0, width, height);
		}
		else {
			Renderer::Instance().DrawImage(image, x, y, 0, width, height);
		}
	}
	for (unsigned int i = 0; i < childs.Size(); i++)
	{
		childs[i]->Render();
	}
}

bool Menu::OnInputEvent(const GUIMessage * message)
{
	bool used = false;
	uint32 i = 0;
	while (!used && i < this->childs.Size()) {
		used = this->childs[i]->OnInputEvent(message);
		i++;
	}
	return used;
}

void Menu::Register(inputs key, inputs action)
{
	father->Register(key, action);
}

void Menu::Unregister(inputs key, inputs action)
{
	father->Unregister(key, action);
}

Menu::~Menu()
{
	for (uint32 i = 0; i < childs.Size(); i++)
	{
		delete childs[i];
	}
}
