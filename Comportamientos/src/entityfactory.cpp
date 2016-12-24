#include "../include/entityfactory.h"
#include "../include/resourcestore.h"
#include "../include/lvlManager.h"
#include "../include/rapidjson/document.h"
#include "../include/entitycomponents.h"
#include "../include/componentmessages.h"
#include "../include/world.h"

#include "../../Ugine/include/image.h"
#include "../../Ugine/include/math.h"

#include "../IA/include/behaviouraltrees.h"

using namespace rapidjson;

EntityFactory::~EntityFactory()
{
	for (uint32 i = 0; i < entityStore.Size(); i++)
	{
		delete entityStore[i];
	}
}

Entity * EntityFactory::CreatePlayerOne(World * world)
{
	Entity * entity;
	Image * ship = nullptr;
	Document document;
	String string;
	const char * json;
	float life, energy, eneryRegeneration;

	/*Retive spaceshipdata*/
	switch (LevelManager::Instance().GetPLayerOneSpaceShip())
	{

	case LevelManager::AVATAR:
		string = String::Read("../data/spaceships/avatar/data.cfg");
		json = string.ToCString();
		document.Parse(json);
		ship = ResourceStore::Instance().GetAvatarImage();
		break;
	case  LevelManager::DREADNOUGH:
		string = String::Read("../data/spaceships/dreadnought/data.cfg");
		json = string.ToCString();
		document.Parse(json);
		ship = ResourceStore::Instance().GetDreadnoughtImage();
		break;
	}
	entity = new Entity(0, 0, ship->GetWidth(), ship->GetHeight(), 0);//create entity
	/*Set spaceship control*/
	switch (LevelManager::Instance().GetPLayerOneType())
	{
		float linearVel, angularVel;
	case LevelManager::HUMAN:
	{
		string = String::Read("../data/config/keybindings.cfg");
		json = string.ToCString();

		Document keybindings;
		keybindings.Parse(json);

		assert(keybindings.HasMember("Player1"));
		assert(keybindings["Player1"].IsObject());

		assert(document.HasMember("LinearVelocity"));
		assert(document["LinearVelocity"].IsNumber());
		assert(document["LinearVelocity"].IsFloat());
		linearVel = document["LinearVelocity"].GetFloat();

		assert(document.HasMember("AngularVelocity"));
		assert(document["AngularVelocity"].IsNumber());
		assert(document["AngularVelocity"].IsFloat());
		angularVel = document["AngularVelocity"].GetFloat();

		ComponentPlayerController * playerController = new ComponentPlayerController(linearVel, angularVel);
		playerController->BinKeys(
			static_cast<inputs>(keybindings["Player1"]["UP"].GetInt()),
			static_cast<inputs>(keybindings["Player1"]["DOWN"].GetInt()),
			static_cast<inputs>(keybindings["Player1"]["RLEFT"].GetInt()),
			static_cast<inputs>(keybindings["Player1"]["RRIGHT"].GetInt()),
			static_cast<inputs>(keybindings["Player1"]["FIREMAIN"].GetInt()),
			static_cast<inputs>(keybindings["Player1"]["FIRESECONDARY"].GetInt())
		);
		entity->AddComponent(playerController);
	}
	break;
	case  LevelManager::EASY:
		ComponentIAController *iaController = new ComponentIAController(document["LinearVelocity"].GetFloat(), document["AngularVelocity"].GetFloat());
		entity->AddComponent(iaController);
		ComponentSensor *sensor = new ComponentSensor(world, document["LookAhead"].GetFloat());
		entity->AddComponent(sensor);
		ComponentBehaviour *EasyIA = new ComponentBehaviour(new SimpleAIBehaviouralTree(entity));
		entity->AddComponent(EasyIA);
		break;
	}

	life = document["Life"].GetFloat();

	energy = document["Energy"].GetFloat();

	eneryRegeneration = document["EnergyRegeneration"].GetFloat();

	ComponentStats * stats = new ComponentStats(life, energy, eneryRegeneration);
	entity->AddComponent(stats);

	ComponentRenderer * renderer = new ComponentRenderer(ship);
	entity->AddComponent(renderer);

	ComponentCircleCollision * collider = new ComponentCircleCollision(1000, false);
	entity->AddComponent(collider);

	ComponentShipExplosion * explosion = new ComponentShipExplosion(this, "../data/explosions/bigexplosion.wav");
	entity->AddComponent(explosion);

	assert(document.HasMember("PrimaryWeapon"));
	assert(document["PrimaryWeapon"].IsObject());
	assert(document["PrimaryWeapon"].HasMember("Type"));
	assert(document["PrimaryWeapon"]["Type"].IsString());

	string = document["PrimaryWeapon"]["Type"].GetString();
	if (string == String("LASER")) {
		ComponentLaserWeapon * weapon = new ComponentLaserWeapon(world, WT_MAIN,
			document["PrimaryWeapon"]["Cooldown"].GetDouble(), document["PrimaryWeapon"]["Damage"].GetDouble(),
			document["PrimaryWeapon"]["EnergyConsumption"].GetDouble(), document["PrimaryWeapon"]["Range"].GetDouble(), document["PrimaryWeapon"]["AudioFile"].GetString());
		entity->AddComponent(weapon);
	}
	else if (string == String("MISSILE")) {
		ComponentBalisticWeapon * weapon = new ComponentBalisticWeapon(world, this, WT_MAIN,
			document["PrimaryWeapon"]["Cooldown"].GetDouble(), document["PrimaryWeapon"]["Damage"].GetDouble(),
			document["PrimaryWeapon"]["EnergyConsumption"].GetDouble(), document["PrimaryWeapon"]["Speed"].GetDouble(), document["PrimaryWeapon"]["AudioFile"].GetString());
		entity->AddComponent(weapon);
	}
	string = document["SecondaryWeapon"]["Type"].GetString();
	if (string == String("DRONE")) {
		ComponentDroneEjector * weapon = new ComponentDroneEjector(world, this, WT_SECONDARY,
			document["SecondaryWeapon"]["MaxNumber"].GetDouble(), document["SecondaryWeapon"]["LinearVelocity"].GetDouble(),
			document["SecondaryWeapon"]["AngularVelocity"].GetDouble(), document["SecondaryWeapon"]["Damage"].GetDouble(), document["SecondaryWeapon"]["RateOfFire"].GetDouble(),
			document["SecondaryWeapon"]["Range"].GetDouble(), document["SecondaryWeapon"]["Range"].GetDouble(), document["SecondaryWeapon"]["AudioFile"].GetString());
		entity->AddComponent(weapon);
	}
	entity->type = Entity::Type::TYPE_PLAYER;
	entityStore.Add(entity);
	return entity;
}

Entity * EntityFactory::CreatePlayerTwo(World * world)
{
	Entity * entity;
	Image * ship = nullptr;
	Document document;
	String string;
	const char * json;
	float life, energy, eneryRegeneration;

	switch (LevelManager::Instance().GetPLayerTwoSpaceShip())
	{

	case LevelManager::AVATAR:
		string = String::Read("../data/spaceships/avatar/data.cfg");
		json = string.ToCString();
		document.Parse(json);
		ship = ResourceStore::Instance().GetAvatarImage();
		break;
	case  LevelManager::DREADNOUGH:
		string = String::Read("../data/spaceships/dreadnought/data.cfg");
		json = string.ToCString();
		document.Parse(json);
		ship = ResourceStore::Instance().GetDreadnoughtImage();
		break;
	}
	entity = new Entity(0, 0, ship->GetWidth(), ship->GetHeight(), 0);
	switch (LevelManager::Instance().GetPLayerTwoType())
	{
		float linearVel, angularVel;
	case LevelManager::HUMAN:
	{
		string = String::Read("../data/config/keybindings.cfg");
		json = string.ToCString();

		Document keybindings;

		keybindings.Parse(json);
		linearVel = document["LinearVelocity"].GetFloat();
		angularVel = document["AngularVelocity"].GetFloat();

		ComponentPlayerController * playerController = new ComponentPlayerController(linearVel, angularVel);
		playerController->BinKeys(
			static_cast<inputs>(keybindings["Player2"]["UP"].GetInt()),
			static_cast<inputs>(keybindings["Player2"]["DOWN"].GetInt()),
			static_cast<inputs>(keybindings["Player2"]["RLEFT"].GetInt()),
			static_cast<inputs>(keybindings["Player2"]["RRIGHT"].GetInt()),
			static_cast<inputs>(keybindings["Player2"]["FIREMAIN"].GetInt()),
			static_cast<inputs>(keybindings["Player2"]["FIRESECONDARY"].GetInt())
		);
		entity->AddComponent(playerController);

	}
	break;
	case  LevelManager::EASY:
		ComponentIAController *iaController = new ComponentIAController(document["LinearVelocity"].GetFloat(), document["AngularVelocity"].GetFloat());
		entity->AddComponent(iaController);
		ComponentSensor *sensor = new ComponentSensor(world, document["LookAhead"].GetFloat());
		entity->AddComponent(sensor);
		ComponentBehaviour *EasyIA = new ComponentBehaviour(new SimpleAIBehaviouralTree(entity));
		entity->AddComponent(EasyIA);
		break;
	}

	life = document["Life"].GetFloat();

	energy = document["Energy"].GetFloat();

	eneryRegeneration = document["EnergyRegeneration"].GetFloat();

	ComponentStats * stats = new ComponentStats(life, energy, eneryRegeneration);
	entity->AddComponent(stats);

	ComponentRenderer * renderer = new ComponentRenderer(ship);
	entity->AddComponent(renderer);

	ComponentCircleCollision * collider = new ComponentCircleCollision(1000, false);
	entity->AddComponent(collider);

	ComponentShipExplosion * explosion = new ComponentShipExplosion(this, "../data/explosions/bigexplosion.wav");
	entity->AddComponent(explosion);

	string = document["PrimaryWeapon"]["Type"].GetString();
	if (string == String("LASER")) {
		ComponentLaserWeapon * weapon = new ComponentLaserWeapon(world, WT_MAIN,
			document["PrimaryWeapon"]["Cooldown"].GetDouble(), document["PrimaryWeapon"]["Damage"].GetDouble(),
			document["PrimaryWeapon"]["EnergyConsumption"].GetDouble(), document["PrimaryWeapon"]["Range"].GetDouble(), document["PrimaryWeapon"]["AudioFile"].GetString());
		entity->AddComponent(weapon);
	}
	else if (string == String("MISSILE")) {
		ComponentBalisticWeapon * weapon = new ComponentBalisticWeapon(world, this, WT_MAIN,
			document["PrimaryWeapon"]["Cooldown"].GetDouble(), document["PrimaryWeapon"]["Damage"].GetDouble(),
			document["PrimaryWeapon"]["EnergyConsumption"].GetDouble(), document["PrimaryWeapon"]["Speed"].GetDouble(), document["PrimaryWeapon"]["AudioFile"].GetString());
		entity->AddComponent(weapon);
	}
	string = document["SecondaryWeapon"]["Type"].GetString();
	if (string == String("DRONE")) {
		ComponentDroneEjector * weapon = new ComponentDroneEjector(world,this, WT_MAIN,
			document["SecondaryWeapon"]["MaxNumber"].GetDouble(), document["SecondaryWeapon"]["LinearVelocity"].GetDouble(),
			document["SecondaryWeapon"]["AngularVelocity"].GetDouble(), document["SecondaryWeapon"]["Damage"].GetDouble(), document["SecondaryWeapon"]["RateOfFire"].GetDouble(),
			document["SecondaryWeapon"]["Range"].GetDouble(), document["SecondaryWeapon"]["Range"].GetDouble(), document["SecondaryWeapon"]["AudioFile"].GetString());
		entity->AddComponent(weapon);
	}
	entity->type = Entity::Type::TYPE_PLAYER;
	entityStore.Add(entity);
	return entity;
}
Entity * EntityFactory::CreateDrone(World * world,double x, double y, double rotation, double linearVelocity, double angularVelocity, double damage, double rateOfFire, double range, double life)
{
	Entity * entity = nullptr;
	//uint32 index = 0;
	//while (!entity && index < entityStore.Size()) {
	//	if (entityStore[index]->type == Entity::Type::T_DRONE && entityStore[index]->dead) {
	//		entity = entityStore[index];
	//		entity->dead = false;
	//		MessageRestart msgRes;
	//		entity->ReciveMessage(&msgRes);
	//	}
	//	index++;
	//}
	if (!entity) {
		Image * drone = nullptr;
		drone = ResourceStore::Instance().GetDroneImage(63, 1);
		entity = new Entity(x, y, drone->GetWidth(), drone->GetHeight(), rotation);
		ComponentRenderer * renderer = new ComponentRenderer(drone, 0, 63, 30);
		entity->type = Entity::Type::T_DRONE;
		entity->AddComponent(renderer);

		ComponentStats * stats = new ComponentStats(life, 100, 100);
		entity->AddComponent(stats);

		ComponentCircleCollision * collider = new ComponentCircleCollision(damage, false);
		entity->AddComponent(collider);

		ComponentSmallExplosion * explosion = new ComponentSmallExplosion(this, "../data/explosions/smallexplosion.wav");
		entity->AddComponent(explosion);

		ComponentLaserWeapon * weapon = new ComponentLaserWeapon(world, WT_MAIN,
			2, damage,0, range, "../data/spaceships/dreadnought/torpedosound.wav");
		entity->AddComponent(weapon);

		ComponentIAController *iaController = new ComponentIAController(linearVelocity, angularVelocity);
		entity->AddComponent(iaController);
		ComponentSensor *sensor = new ComponentSensor(world, 0);
		entity->AddComponent(sensor);
		ComponentBehaviour *EasyIA = new ComponentBehaviour(new DroneAIBehaviouralTree(entity));
		entity->AddComponent(EasyIA);
		entityStore.Add(entity);
		world->addEntity(entity);
	}
	return entity;
}
Entity * EntityFactory::CreateShipExplosion(double x, double y)
{
	Entity * entity;
	Image * explosion = nullptr;
	explosion = ResourceStore::Instance().GetShipExplosionImage(20, 1, rand() % 2);
	entity = new Entity(x, y, explosion->GetWidth(), explosion->GetHeight(), 0);
	ComponentRenderer * renderer = new ComponentRenderer(explosion, 0, 20, 30, false);
	entity->AddComponent(renderer);
	entityStore.Add(entity);
	return entity;
}

Entity * EntityFactory::CreateSmallExplosion(double x, double y)
{
	Entity * entity = nullptr;
	uint32 index = 0;
	while (!entity && index < entityStore.Size()) {
		if (entityStore[index]->type == Entity::Type::T_EXPLOSION && entityStore[index]->dead) {
			entity = entityStore[index];
			entity->x =x;
			entity->y=y;
			entity->dead = false;
			MessageRestart msgRes;
			entity->ReciveMessage(&msgRes);
		}
		index++;
	}
	if (!entity) {
		Image * explosion = nullptr;
		explosion = ResourceStore::Instance().GetSmallExplosionImage();
		entity = new Entity(x, y, explosion->GetWidth(), explosion->GetHeight(), 0);
		ComponentRenderer * renderer = new ComponentRenderer(explosion, (rand() % 4) * 10, 10, 30, false);
		entity->type = Entity::Type::T_EXPLOSION;
		entity->AddComponent(renderer);
		entityStore.Add(entity);
	}
	return entity;
}

Entity * EntityFactory::createMissile(double damage, double x, double y, double rotation, double linearSpeed, Entity::Team spawnerTeam)
{
	double trueX, trueY;
	Image * missile = nullptr;
	missile = ResourceStore::Instance().GetMissileImage();
	trueX = x + DegCos(rotation - 90) * missile->GetWidth()/2;
	x += x - trueX;
	trueY = y - DegSin(rotation - 90) * missile->GetHeight()/2;
	y += y - trueY;
	Entity * entity = nullptr;
	uint32 index = 0;
	while (!entity && index < entityStore.Size()) {
		if (entityStore[index]->type == Entity::Type::T_MISSILE && entityStore[index]->dead) {
			entity = entityStore[index];
			entity->dead = false;
			entity->x = x;
			entity->y = y;
			entity->width = missile->GetWidth();
			entity->height = missile->GetHeight();
			entity->rotation = rotation;
			entity->team = (spawnerTeam==Entity::Team::T_BLUELEADER? Entity::Team::T_BLUE: Entity::Team::T_RED);
			MessageRestart msgRes;
			entity->ReciveMessage(&msgRes);
		}
		index++;
	}
	if (!entity) {
		entity = new Entity(x, y, missile->GetWidth(), missile->GetHeight(), rotation);
		entity->team = (spawnerTeam == Entity::Team::T_BLUELEADER ? Entity::Team::T_BLUE : Entity::Team::T_RED);
		ComponentRenderer * renderer = new ComponentRenderer(missile, 1, 1, false);
		entity->AddComponent(renderer);
		ComponentLinearMovement * linearMovement = new ComponentLinearMovement(linearSpeed);
		entity->AddComponent(linearMovement);
		ComponentSmallExplosion * SmallExplosion = new ComponentSmallExplosion(this, "../data/explosions/smallexplosion.wav");
		entity->AddComponent(SmallExplosion);
		ComponentCircleCollision * collision = new ComponentCircleCollision(damage, true);
		entity->type = Entity::Type::T_MISSILE;
		entity->AddComponent(collision);
		entityStore.Add(entity);
	}
	return entity;
}
