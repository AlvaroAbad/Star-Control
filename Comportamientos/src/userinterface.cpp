#include "..\include\userinterface.h"
#include "../include/resourcestore.h"
#include "../include/lvlManager.h"
#include "../include/world.h"
#include "../include/entity.h"
#include "../include/componentmessages.h"

#include "../../GUI/include/window.h"
#include "../../GUI/include/menu.h"
#include "../../GUI/include/statbar.h"
#include "../../GUI/include/imageholder.h"

#include "../../Ugine/include/screen.h"



UserInterface::UserInterface(World * world) :world(world)
{
}

void UserInterface::Init()
{
	uint16 width = Screen::Instance().GetWidth();
	uint16 height = Screen::Instance().GetHeight();

	Image * player1Holder = ResourceStore::Instance().GetPlayer1Holder();
	Image * player2Holder = ResourceStore::Instance().GetPlayer2Holder();
	Image * player1SpaceShipImage,* player2SpaceShipImage;
	player1SpaceShipImage=player2SpaceShipImage=nullptr;
	switch (LevelManager::Instance().GetPLayerOneSpaceShip())
	{
	case LevelManager::SpaceShip::AVATAR:
		player1SpaceShipImage = ResourceStore::Instance().GetAvatarImage();
		break;
	case LevelManager::SpaceShip::DREADNOUGH:
		player1SpaceShipImage = ResourceStore::Instance().GetDreadnoughtImage();
		break;
	}

	switch (LevelManager::Instance().GetPLayerTwoSpaceShip())
	{
	case LevelManager::SpaceShip::AVATAR:
		player2SpaceShipImage = ResourceStore::Instance().GetAvatarImage();
		break;
	case LevelManager::SpaceShip::DREADNOUGH:
		player2SpaceShipImage = ResourceStore::Instance().GetDreadnoughtImage();
		break;
	}

	String id;
	HUD = new Window(NULL);
	HUD->SetPosition(0, 0);
	HUD->SetDimensions(width, height);

	/*Create Player 1 HUD*/
	id = "mP1";
	Menu * p1Menu = new Menu(&id, player1Holder);
	p1Menu->setPositionType(true);
	p1Menu->SetPosition(width - player1Holder->GetWidth(), 0);
	p1Menu->SetDimensions(player1Holder->GetWidth(), player1Holder->GetHeight());
	HUD->AddChild(p1Menu);

	/*Create Life and Energy Bars*/
	id = "sbLifeP1";
	lifeP1 = new StatBar(&id, 0, 255, 0,100);
	lifeP1->setPositionType(true);
	lifeP1->SetPosition(20, 50);
	lifeP1->SetDimensions(20, 100);
	p1Menu->AddChild(lifeP1);

	id = "sbEnergyP1";
	energyP1 = new StatBar(&id, 255, 0, 0,100);
	energyP1->setPositionType(true);
	energyP1->SetPosition(160, 50);
	energyP1->SetDimensions(20, 100);
	p1Menu->AddChild(energyP1);

	/*create Spaceship Image*/
	id = "imP1";
	ImageHolder * ihP1 = new ImageHolder(&id, player1SpaceShipImage, 60, 60, 80, 100);
	ihP1->setPositionType(true);
	p1Menu->AddChild(ihP1);

	/*Create Player 2 HUD*/
	id = "mP2";
	Menu * p2Menu = new Menu(&id, player2Holder);
	p2Menu->setPositionType(true);
	p2Menu->SetPosition(width - player2Holder->GetWidth(), height - player2Holder->GetHeight());
	p2Menu->SetDimensions(player2Holder->GetWidth(), player2Holder->GetHeight());
	HUD->AddChild(p2Menu);

	/*Create Life and Energy Bars*/
	id = "sbLifeP2";
	lifeP2 = new StatBar(&id, 0, 255, 0, 100);
	lifeP2->setPositionType(true);
	lifeP2->SetPosition(20, 30);
	lifeP2->SetDimensions(20, 100);
	p2Menu->AddChild(lifeP2);

	id = "sbEnergyP2";
	energyP2 = new StatBar(&id, 255, 0, 0, 100);
	energyP2->setPositionType(true);
	energyP2->SetPosition(160, 30);
	energyP2->SetDimensions(20, 100);
	p2Menu->AddChild(energyP2);

	/*create Spaceship Image*/
	id = "imP2";
	ImageHolder * ihP2 = new ImageHolder(&id, player2SpaceShipImage, 60, 40, 80, 100);
	ihP2->setPositionType(true);
	p2Menu->AddChild(ihP2);
}

void UserInterface::run()
{
	MessageGetLife msgGLife;
	MessageGetEnergy msgGEnergy;
	if(world->playerOne){
	world->playerOne->ReciveMessage(&msgGLife);
	lifeP1->SetValue(msgGLife.life);
	world->playerOne->ReciveMessage(&msgGEnergy);
	energyP1->SetValue(msgGEnergy.energy);
	}
	else {
		lifeP2->SetValue(0);
		energyP1->SetValue(0);
	}
	if (world->playerTwo) {
		world->playerTwo->ReciveMessage(&msgGLife);
		lifeP2->SetValue(msgGLife.life);
		world->playerTwo->ReciveMessage(&msgGEnergy);
		energyP2->SetValue(msgGEnergy.energy);
	} 
	else {
		lifeP2->SetValue(0);
		energyP2->SetValue(0);
	}

	HUD->Update();
}

void UserInterface::draw()
{
	HUD->Render();
}

void UserInterface::getInputs()
{
}

UserInterface::~UserInterface()
{
	delete HUD;
}
