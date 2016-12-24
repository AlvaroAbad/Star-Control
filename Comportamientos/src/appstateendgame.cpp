#include "../include/appstateendgame.h"
#include "../include/resourcestore.h"
#include "../include/externs.h"
#include "../include/game.h"

#include "../../GUI/include/window.h"
#include "../../GUI/include/menu.h"
#include "../../GUI/include/button.h"
#include "../../Ugine/include/screen.h"

#include "../../InputManager/include/eventmanager.h"

extern Game *game;
AppStateEndGame::~AppStateEndGame()
{
	delete window;
}

void AppStateEndGame::run()
{
	window->Update();
}
void AppStateEndGame::draw() const
{
	window->Render();
}
void AppStateEndGame::getInputs()
{
	EventManager::Instance().DispachEvents();
}
void AppStateEndGame::activate()
{
	uint16 width = Screen::Instance().GetWidth();
	uint16 height = Screen::Instance().GetHeight();
	Image * background = ResourceStore::Instance().GetMenuBackGround();
	Image * buttonImg = ResourceStore::Instance().GetMenuButtonNeutralImage();
	Image * buttonPressImg = ResourceStore::Instance().GetMenuButtonPressedImage();
	Image * buttonHooverImg = ResourceStore::Instance().GetMenuButtonHooverImage();
	Image * buttonDisabledImg = ResourceStore::Instance().GetMenuButtonDisabledImage();
	String id = "mMain";

	window = new Window(background);
	window->SetPosition(0, 0);
	window->SetDimensions(width, height);

	id = "btnMenu";
	Button * buttonStart = new Button(&id, buttonImg, buttonPressImg, buttonHooverImg, buttonDisabledImg);
	buttonStart->setPositionType(true);
	buttonStart->SetPosition(window->GetWidth() / 4 ,window->GetHeight()/2);
	buttonStart->SetDimensions(buttonImg->GetWidth()*1.5, buttonImg->GetHeight());
	buttonStart->SetText("Manu");
	window->AddChild(buttonStart);

	id = "btnReplay";
	Button * buttonOpc = new Button(&id, buttonImg, buttonPressImg, buttonHooverImg, buttonDisabledImg);
	buttonOpc->setPositionType(true);
	buttonOpc->SetPosition(window->GetWidth() / 4 * 2,window->GetHeight() / 2);
	buttonOpc->SetDimensions(buttonImg->GetWidth()*2, buttonImg->GetHeight());
	buttonOpc->SetText("Replay");
	window->AddChild(buttonOpc);

	buttonStart->Register(inputs::MOUSE_BUTTON_LEFT, inputs::KEY_PRESS);
	buttonOpc->Register(inputs::MOUSE_BUTTON_LEFT, inputs::KEY_PRESS);

	buttonStart->Register(inputs::MOUSE_BUTTON_LEFT, inputs::KEY_RELEASE);
	buttonOpc->Register(inputs::MOUSE_BUTTON_LEFT, inputs::KEY_RELEASE);

	buttonStart->Register(inputs::KEY_UNKNOWN, inputs::MOUSE_MOVEMENT);
	buttonOpc->Register(inputs::KEY_UNKNOWN, inputs::MOUSE_MOVEMENT);

	buttonStart->SetEventListener(this);
	buttonOpc->SetEventListener(this);
	if (game) {
		delete game;
		game = nullptr;
	}
}

void AppStateEndGame::deactivate()
{
	window->Unregister();
}

void AppStateEndGame::OnClick(Control * sender)
{
	if (*(sender->GetId()) == "btnMenu") {
		whantedState = STATE_MAINMENU;
	}
	else if (*(sender->GetId()) == "btnReplay") {
		whantedState = STATE_GAME;
	}
}
