#ifndef SCM_ENTITY_H
#define SCM_ENTITY_H

#include "../../Ugine/include/array.h"

class Message;
class Component;
class Entity
{
public:
	enum Team
	{
		T_REDLEADER,
		T_BLUELEADER,
		T_RED,
		T_BLUE
	};
	enum Type
	{
		TYPE_PLAYER,
		T_DRONE,
		T_MISSILE,
		T_EXPLOSION
	};
	Entity(double x, double y, double width, double height, double rotation)
		:dead(false), x(x),y(y),width(width), height(height), rotation(rotation) {};
	~Entity();
	void Update(float elapsed);
	void ReciveMessage(Message * message);
	void AddComponent(Component * component);

	/*Properties*/
	double x, y;
	double width, height;
	double rotation;
	bool dead;
	Team team;
	Type type;
private:
	Array<Component *> components;
};
#endif // !SCM_ENTITY_H
