#include "../../GUI/include/window.h"
#include "../../Ugine/include/renderer.h"
#include "../../InputManager/include/managergameinterface.h"
void Window::Update()
{
	for (unsigned int i = 0; i < childs.Size(); i++)
	{
		childs[i]->Update();
	}
}

void Window::Render()
{
	if (image) {
		Renderer::Instance().SetBlendMode(Renderer::SOLID);
		Renderer::Instance().DrawImage(image, x, y, 0, width, height);
	}
	for (unsigned int i = 0; i < childs.Size(); i++)
	{
		childs[i]->Render();
	}
}

bool Window::OnInputEvent(const GUIMessage * message)
{
	bool used = false;
	uint32 i = 0;
	while (!used && i < this->childs.Size()) {
		used = this->childs[i]->OnInputEvent(message);
		i++;
	}
	return used;
}

void Window::Register(inputs key, inputs action)
{
	RegisteredEvents registerEvent;
	registerEvent.key = key;
	registerEvent.action = action;
	uint32 i=0;
	while (i<registeredEvents.Size() && registeredEvents[i] != registerEvent) {
		i++;
	}
	if (i == registeredEvents.Size()) {
		ManagerGameInterface::Register(this, key, action);
		registeredEvents.Add(registerEvent);
	}
	
}

void Window::Unregister(inputs key, inputs action)
{
	RegisteredEvents unregisterEvent;
	unregisterEvent.key = key;
	unregisterEvent.action = action;
	registeredEvents.Remove(unregisterEvent);
	ManagerGameInterface::Unregister(this, key, action);
}

void Window::Unregister()
{
	registeredEvents.Clear();
	ManagerGameInterface::UnregisterAll(this);
}

Window::~Window()
{
	for (uint32 i = 0; i < childs.Size(); i++)
	{
		delete childs[i];
	}
}
