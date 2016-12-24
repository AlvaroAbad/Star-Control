#include "..\include\world.h"
#include "../include/entity.h"
#include "../include/componentmessages.h"

#include "../../Ugine/include/scene.h"
#include "../../Ugine/include/renderer.h"
#include "../../Ugine/include/screen.h"
#include "../../Ugine/include/image.h"
#include "../../Ugine/include/math.h"
#include "../../Ugine/include/listener.h"

World::World()
{
}

void World::Init()
{
	playerOne = factory.CreatePlayerOne(this);
	playerOne->x = 750;
	playerOne->y = 550;
	entities.Add(playerOne);
	playerOne->team = Entity::Team::T_BLUELEADER;
	playerTwo = factory.CreatePlayerTwo(this);
	playerTwo->x = 50;
	playerTwo->y = 50;
	entities.Add(playerTwo);
	playerTwo->team = Entity::Team::T_REDLEADER;
	endGame = false;
	Listener::Instance().SetPosition(Screen::Instance().GetWidth() / 2, Screen::Instance().GetHeight() / 2, 0);
}

void World::run()
{
	Array<Entity *> dead;
	/*Update Entities*/
	MessageCheckCollision msgCCollision;
	MessageCheckLaserCollision msgCLCollision;
	for (size_t i = 0; i < entities.Size(); i++)
	{
		entities[i]->Update(Screen::Instance().ElapsedTime());
		if (entities[i]->dead) {
			dead.Add(entities[i]);
		}
		if (entities[i]->type != Entity::Type::T_MISSILE) {
			entities[i]->x = WrapValue(entities[i]->x, Screen::Instance().GetWidth());
			entities[i]->y = WrapValue(entities[i]->y, Screen::Instance().GetHeight());
		}
		else {
			if (entities[i]->x > Screen::Instance().GetWidth() || entities[i]->x<0 || entities[i]->y>Screen::Instance().GetHeight() || entities[i]->y < 0) {
				entities[i]->dead = true;
				dead.Add(entities[i]);
			}
		};
	}


	/*remove dead entities and generate Explosions*/
	MessageExplode msgExplode;
	for (size_t i = 0; i < dead.Size(); i++)
	{
		msgExplode.entity = nullptr;
		entities.Remove(dead[i]);
		dead[i]->ReciveMessage(&msgExplode);
		if (msgExplode.entity) {
			entities.Add(msgExplode.entity);
			if (dead[i] == playerOne) {
				playerOne = msgExplode.entity;
			}
			else if (dead[i] == playerTwo) {
				playerTwo = msgExplode.entity;
			}
		}
	}
	if (playerOne && playerOne->dead) {
		endGame = true;
		playerOne = nullptr;
	}
	if (playerTwo && playerTwo->dead) {
		endGame = true;
		playerTwo = nullptr;
	}

	/*Check collision between entities*/
	for (size_t i = 0; i < entities.Size() - 1; i++)
	{
		for (size_t j = i + 1; j < entities.Size(); j++)
		{
			msgCCollision.entity = entities[j];
			entities[i]->ReciveMessage(&msgCCollision);
		}
	}
	/*check collision between lasers and entities*/
	for (size_t i = 0; i < lasers.Size(); i++)
	{
		msgCLCollision.laser = &(lasers[i]);
		for (size_t j = 0; j < entities.Size(); j++)
		{
			msgCLCollision.hit = false;
			entities[j]->ReciveMessage(&msgCLCollision);
			if (msgCLCollision.hit) {
				entities.Add(factory.CreateSmallExplosion(msgCLCollision.hitX, msgCLCollision.hitY));
				MessageReduceLife msgRLife;
				msgRLife.damage = lasers[i].damage;
				entities[j]->ReciveMessage(&msgRLife);
			}
		}
	}
}

void World::draw()
{
	MessageGetRendering msgRendering;
	Renderer::Instance().SetBlendMode(Renderer::ALPHA);
	Renderer::Instance().SetColor(255, 255, 0, 255);
	for (size_t i = 0; i < lasers.Size(); i++)
	{
		Renderer::Instance().DrawLine(lasers[i].oX, lasers[i].oY, lasers[i].dX, lasers[i].dY);
	}
	lasers.Clear();
	Renderer::Instance().SetColor(255, 255, 255, 255);
	for (size_t i = 0; i < entities.Size(); i++)
	{
		entities[i]->ReciveMessage(&msgRendering);
		if (msgRendering.render) {
			msgRendering.render->SetMidHandle();
			Renderer::Instance().DrawImage(msgRendering.render, msgRendering.x, msgRendering.y, msgRendering.frame, msgRendering.width, msgRendering.height, msgRendering.rotion);
			msgRendering.render->SetHandle(0, 0);
		}
		msgRendering.render = nullptr;
	}
}

World::~World()
{

}
