#ifndef SCM_WORLD_H
#define SCM_WORLD_H

#include "../../Ugine/include/array.h"
#include "entityfactory.h"
#include "userinterface.h"

class Scene;
class Entity;
class EntityFactory;
class World
{
	friend void UserInterface::run();
public:
	struct Laser {
		Laser() {}
		Laser(double oX, double oY, double dX, double dY, double damage, Entity * shooter) 
			:oX(oX), oY(oY), dX(dX), dY(dY), damage(damage), shooter(shooter){}
		double oX, oY, dX, dY, damage;
		Entity * shooter;
	};
	World();
	void Init();// create selected entities
	void run();
	void draw();
	~World();
	bool isGameEnd() { return endGame; }
	void addEntity(Entity *entity) {entities.Add(entity);}
	void addLaserRender(Laser laser) { lasers.Add(laser);}
	Array<Entity *>& Getentities() { return entities; }
private:
	EntityFactory factory;
	Array<Entity *> entities;
	Array<Laser> lasers;
	Entity * playerOne, *playerTwo;
	bool endGame;
};
#endif // !SCM_WORLD_H