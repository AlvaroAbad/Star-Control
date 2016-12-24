#ifndef SCM_ENTITYFACTORY_H
#define SCM_ENTITYFACTORY_H

#include "../../Ugine/include/array.h"
#include "../include/entity.h"
class World;
class EntityFactory
{
public:
	EntityFactory() {};
	~EntityFactory();
	Entity * CreatePlayerOne(World * world);
	Entity * CreatePlayerTwo(World * world);
	Entity * CreateDrone(World * world,double x, double y, double rotation, double linearVelocity, double angularVelocity, double damage, double rateOfFire, double range, double life);
	Entity * CreateShipExplosion(double x, double y);
	Entity * CreateSmallExplosion(double x, double y);
	Entity * createMissile(double damage, double x, double y, double rotation, double linearSpeed , Entity::Team spawnerTeam);

private:
	Array<Entity *> entityStore;
};
#endif // !SCM_ENTITYFACTORY_H

