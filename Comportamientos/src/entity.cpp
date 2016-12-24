#include "..\include\entity.h"
#include "../include/component.h"
#include "../include/componentmessages.h"

#pragma warning(disable:4061)

Entity::~Entity()
{
	for (size_t i = 0; i < components.Size(); i++)
	{
		delete components[i];
	}
}

void Entity::Update(float elapsed)
{
	for (size_t i = 0; i < components.Size(); i++)
	{
		components[i]->Update(elapsed);
	}
}

void Entity::ReciveMessage(Message * message)
{
	switch (message->type)
	{
	case Message::MSG_GRENDERING:
	{
		MessageGetRendering * msgGRendering = static_cast<MessageGetRendering *>(message);
		msgGRendering->x = static_cast<int>(x);
		msgGRendering->y = static_cast<int>(y);
		msgGRendering->width = static_cast<int>(width);
		msgGRendering->height = static_cast<int>(height);
		msgGRendering->rotion = rotation;
	}
	break;
	case Message::MSG_FIRE:
	{
		MessageFire * msgFire = static_cast<MessageFire *>(message);
		msgFire->x = x;
		msgFire->y = y;
		msgFire->width = width;
		msgFire->height = height;
		msgFire->rotation = rotation;
	}
	break;
	}
	for (size_t i = 0; i < components.Size(); i++)
	{
		components[i]->ReciveMessage(message);
	}
}

void Entity::AddComponent(Component * component)
{
	component->SetFather(this);
	components.Add(component);
}
