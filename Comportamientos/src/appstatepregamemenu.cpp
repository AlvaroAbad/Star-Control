#include "..\include\appstatepregamemenu.h"
#include "../include/resourcestore.h"
#include "../../Ugine/include/screen.h"
#include "../../GUI/include/window.h"
#include "../../GUI/include/menu.h"
#include "../../GUI/include/button.h"
#include "../../GUI/include/imageselector.h"
#include "../../GUI/include/droplist.h"
#include "../include/externs.h"
#include "../include/lvlManager.h"

AppStatePreGameMenu::~AppStatePreGameMenu()
{
	delete window;
}

void AppStatePreGameMenu::run()
{
	window->Update();
}

void AppStatePreGameMenu::draw() const
{
	window->Render();
}

void AppStatePreGameMenu::getInputs()
{
	
}

void AppStatePreGameMenu::activate()
{
	uint16 width = Screen::Instance().GetWidth();
	uint16 height = Screen::Instance().GetHeight();
	Image * background = ResourceStore::Instance().GetMenuBackGround();
	Image * menuImg = ResourceStore::Instance().GetMenuImage();
	Image * buttonImg = ResourceStore::Instance().GetMenuButtonNeutralImage();
	Image * buttonPressImg = ResourceStore::Instance().GetMenuButtonPressedImage();
	Image * buttonHooverImg = ResourceStore::Instance().GetMenuButtonHooverImage();
	Image * buttonDisabledImg = ResourceStore::Instance().GetMenuButtonDisabledImage();
	Image * buttonBackImg = ResourceStore::Instance().GetMenuButtonBackImage();
	Image * buttonBackPressedImg = ResourceStore::Instance().GetMenuButtonBackPressedImage();
	Image * buttonBackHooverImg = ResourceStore::Instance().GetMenuButtonBackHooverImage();
	Image * ImageSelectorImg = ResourceStore::Instance().GetImageSelectorImage();
	Image * avatarImg = ResourceStore::Instance().GetAvatarImage();
	Image * dreadnoughtImg = ResourceStore::Instance().GetDreadnoughtImage();
	String id = "mMain";
	String Options;

	/*Create Window*/
	window = new Window(background);
	window->SetPosition(0, 0);
	window->SetDimensions(width, height);

	/*Create Menu Holder*/
	Menu * menu = new Menu(&id, menuImg);
	menu->setPositionType(true);
	menu->SetPosition(width - menuImg->GetWidth(), 0);
	menu->SetDimensions(menuImg->GetWidth(), height);
	id = "btnStart";
	/*Crete start Buttons*/
	Button * buttonStart = new Button(&id, buttonImg, buttonPressImg, buttonHooverImg, buttonDisabledImg);
	buttonStart->setPositionType(true);
	buttonStart->SetPosition(10, height - buttonImg->GetHeight() - 10);
	buttonStart->SetDimensions(menu->GetWidth() - 60, buttonImg->GetHeight());
	buttonStart->SetText("Start");
	menu->AddChild(buttonStart);

	id = "dlP1Setings";
	dlP1Settings = new DropList(&id, width - menuImg->GetWidth() + 10, 90, 100);
	dlP1Settings->setPositionType(true);
	Options = "Player";
	dlP1Settings->AddOption(&Options);
	Options = "IA";
	dlP1Settings->AddOption(&Options);
	menu->AddChild(dlP1Settings);

	id = "dlP2Setings";
	dlP2Settings = new DropList(&id, width - menuImg->GetWidth() + 10, 320, 100);
	dlP2Settings->setPositionType(true);
	Options = "Player";
	dlP2Settings->AddOption(&Options);
	Options = "IA";
	dlP2Settings->AddOption(&Options);
	menu->AddChild(dlP2Settings);

	window->AddChild(menu);

	id = "btnBack";
	Button * buttonBack = new Button(&id, buttonBackImg, buttonBackPressedImg, buttonBackHooverImg);
	buttonBack->setPositionType(true);
	buttonBack->SetPosition(10, 10);
	buttonBack->SetDimensions(buttonBackImg->GetWidth(), buttonImg->GetHeight());
	window->AddChild(buttonBack);

	id = "iselPlayer1";
	Player1ShipoSlector = new ImageSelector(&id, 50, 50, 10, ImageSelectorImg);
	Player1ShipoSlector->setPositionType(true);
	Player1ShipoSlector->SetPosition(0, buttonBackImg->GetHeight() + 47);
	Player1ShipoSlector->SetDimensions(width - menuImg->GetWidth(), (height / 2) - (buttonBackImg->GetHeight() + 47));
	Player1ShipoSlector->AddImage(avatarImg);
	Player1ShipoSlector->AddImage(dreadnoughtImg);
	window->AddChild(Player1ShipoSlector);

	id = "iselPlayer2";
	Player2ShipoSlector = new ImageSelector(&id, 50, 50, 10, ImageSelectorImg);
	Player2ShipoSlector->setPositionType(true);
	Player2ShipoSlector->SetPosition(0, height / 2 + 10);
	Player2ShipoSlector->SetDimensions(width - menuImg->GetWidth(), (height / 2) - (buttonBackImg->GetHeight() + 47));
	Player2ShipoSlector->AddImage(avatarImg);
	Player2ShipoSlector->AddImage(dreadnoughtImg);
	window->AddChild(Player2ShipoSlector);


	buttonStart->Register(inputs::MOUSE_BUTTON_LEFT, inputs::KEY_PRESS);
	buttonBack->Register(inputs::MOUSE_BUTTON_LEFT, inputs::KEY_PRESS);

	buttonStart->Register(inputs::MOUSE_BUTTON_LEFT, inputs::KEY_RELEASE);
	buttonBack->Register(inputs::MOUSE_BUTTON_LEFT, inputs::KEY_RELEASE);

	buttonStart->Register(inputs::KEY_UNKNOWN, inputs::MOUSE_MOVEMENT);
	buttonBack->Register(inputs::KEY_UNKNOWN, inputs::MOUSE_MOVEMENT);

	Player1ShipoSlector->Register(inputs::MOUSE_BUTTON_LEFT, inputs::CLICK);
	Player1ShipoSlector->Register(inputs::KEY_LEFT, inputs::KEY_PRESS);
	Player1ShipoSlector->Register(inputs::KEY_RIGHT, inputs::KEY_PRESS);

	Player2ShipoSlector->Register(inputs::MOUSE_BUTTON_LEFT, inputs::CLICK);
	Player2ShipoSlector->Register(inputs::KEY_LEFT, inputs::KEY_PRESS);
	Player2ShipoSlector->Register(inputs::KEY_RIGHT, inputs::KEY_PRESS);

	buttonBack->SetEventListener(this);
	buttonStart->SetEventListener(this);
}

void AppStatePreGameMenu::deactivate()
{
	window->Unregister();
}

void AppStatePreGameMenu::OnClick(Control * sender)
{

	if (*(sender->GetId()) == "btnBack") {
		whantedState = STATE_MAINMENU;
	}
	else if (*(sender->GetId()) == "btnStart") {
		whantedState = STATE_GAME;
		if (*dlP1Settings->GetSelectedValue() == String("Player")) {
			LevelManager::Instance().SetPlayerOneType(LevelManager::HUMAN);
		}
		else {
			LevelManager::Instance().SetPlayerOneType(LevelManager::EASY);
		}

		if (*dlP2Settings->GetSelectedValue() == String("Player")) {
			LevelManager::Instance().SetPlayerTwoType(LevelManager::HUMAN);
		}
		else {
			LevelManager::Instance().SetPlayerTwoType(LevelManager::EASY);
		}
		Array<String> split = Player1ShipoSlector->GetSelectedImage()->GetFilename().ExtractDir().Split("/");
		if (split.Last() == String("avatar")) {
			LevelManager::Instance().SetPlayerOneSpceShip(LevelManager::AVATAR);
		}
		else {
			LevelManager::Instance().SetPlayerOneSpceShip(LevelManager::DREADNOUGH);
		}
		split = Player2ShipoSlector->GetSelectedImage()->GetFilename().ExtractDir().Split("/");
		if (split.Last() == String("avatar")) {
			LevelManager::Instance().SetPlayerTwoSpceShip(LevelManager::AVATAR);
		}
		else {
			LevelManager::Instance().SetPlayerTwoSpceShip(LevelManager::DREADNOUGH);
		}
	}
}
