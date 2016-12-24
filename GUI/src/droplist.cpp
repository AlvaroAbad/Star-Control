#include "..\include\droplist.h"
#include "../include/dropdownlistbutton.h"
#include "../../Comportamientos/include/resourcestore.h"

DropList::DropList(String * btnId, double x, double y, double width) :Control(btnId)
{
	String id = "btnDropdown";
	SetPosition(x, y);
	SetDimensions(width, 30);
	hasFocus = false;
	dropdown = new Button(&id, ResourceStore::Instance().GetDropDownButtonImage(), ResourceStore::Instance().GetDropDownButtonPressedImage(), ResourceStore::Instance().GetDropDownButtonHooverImage());
	dropdown->SetPosition(width - 30, 0);
	dropdown->SetDimensions(30, 30);
	dropdown->setPositionType(true);
	selected = nullptr;
	AddChild(dropdown);
	dropdown->SetEventListener(this);
	deployed = false;
}
void DropList::Update()
{
	if (!selected) {
		selected = options[0];
		selected->disable();
	}
	selected->SetPosition(0, 0);
}

void DropList::Render()
{
	selected->Render();
	dropdown->Render();
	if (deployed) {
		float yOffset = 0;;
		for (size_t i = 0; i < options.Size(); i++)
		{
			if(!options[i]->isDisabled()){
			options[i]->SetPosition(0, height + yOffset);
			options[i]->Render();
			yOffset += 30;
			}
		}
	}
}

bool DropList::OnInputEvent(const GUIMessage * message)
{
	bool used = false;
	used=dropdown->OnInputEvent(message);
	if (!used && deployed) {
		uint32 i = 0;
		while (!used && i < options.Size()) {
			used = options[i]->OnInputEvent(message);
			i++;
		}
	}
	return used;
}

void DropList::Register(inputs key, inputs action)
{
}

void DropList::Unregister(inputs key, inputs action)
{
}

void DropList::AddOption(String * opt)
{
	DropDownListButton * option = new DropDownListButton(opt,opt,ResourceStore::Instance().GetDropDownListButtonImage(), ResourceStore::Instance().GetDropDownListButtonHooverImage());
	option->SetDimensions(width-30, 30);
	option->setPositionType(true);
	AddChild(option);
	options.Add(option);
}

void DropList::setSelection(DropDownListButton * selection)
{
	selected = selection;
	deployed = false;
	for (size_t i = 0; i < options.Size(); i++)
	{
		if (options[i] != selection) {
			options[i]->enable();
		}
	}
}

void DropList::OnClick(Control * sender)
{
	deployed = !deployed;
}

DropList::~DropList()
{
	delete dropdown;
	for (size_t i = 0; i < options.Size(); i++)
	{
		delete options[i];
	}
}

String * DropList::GetSelectedValue()
{
	return selected->GetValue();
}