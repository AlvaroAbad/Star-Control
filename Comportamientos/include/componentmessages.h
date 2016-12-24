#ifndef SCM_MESSAGES_H
#define SCM_MESSAGES_H

#pragma warning(disable:4820)

#include "../include/world.h"

class Image;
class Collision;
class Entity;

struct Message {
	enum MessageType {
		MSG_GRENDERING,
		MSG_REDUCELIFE,
		MSG_REDUCEENERGY,
		MSG_GLIFE,
		MSG_GMAXLIFE,
		MSG_GENERGY,
		MSG_CHECKCOLLISION,
		MSG_CHECKLASERCOLLISION,
		MSG_GCOLLIDER,
		MSG_ALERTCOLLISION,
		MSG_EXPLODE,
		MSG_WEAPONREADY,
		MSG_FIRE,
		MSG_GETCLOSESTENEMY,
		MSG_GETANGULARSPEED,
		MSG_GETLINEARSPEED,
		MSG_SETMOVEMENT,
		MSG_GETLOOKAHEAD,
		MSG_GETWEAPONREADY,
		MSG_GETENEMYLEADER,
		MSG_GETAPPROPRIATEWEAPON,
		MSG_RESTART
	};
	MessageType type;
};

struct MessageRestart: public Message{
	MessageRestart() {
		type = MSG_RESTART;
	}
};
struct MessageGetRendering : public Message {
	MessageGetRendering() { 
		type = MSG_GRENDERING; 
	}
	Image* render;
	int frame;
	int x, y;
	int width, height;
	double rotion;
};

struct MessageReduceLife : public Message {
	MessageReduceLife() {
		type = MSG_REDUCELIFE;
	}
	float damage;
};

struct MessageReduceEnergy : public Message {
	MessageReduceEnergy() {
		type = MSG_REDUCEENERGY;
	}
	float consumption;
};

struct MessageGetLife : public Message {
	MessageGetLife() {
		type = MSG_GLIFE;
	}
	float life;
};
struct MessageGetMaxLife : public Message {
	MessageGetMaxLife() {
		type = MSG_GMAXLIFE;
	}
	int32 o_MaxLife;
};
struct MessageGetEnergy : public Message {
	MessageGetEnergy() {
		type = MSG_GENERGY;
	}
	float energy;
};

struct MessageCheckCollision : public Message {
	MessageCheckCollision() {
		type = MSG_CHECKCOLLISION;
	}
	Entity * entity;
};
struct MessageCheckLaserCollision : public Message {
	MessageCheckLaserCollision() {
		type = MSG_CHECKLASERCOLLISION;
	}
	World::Laser * laser;
	bool hit;
	double hitX, hitY;
};
struct MessageGetCollider : public Message {
	MessageGetCollider() {
		type = MSG_GCOLLIDER;
	}
	Collision * collider;
};
struct MessageAllertCollision : public Message {
	MessageAllertCollision() {
		type = MSG_ALERTCOLLISION;
	}
	Entity * entity;
};
struct MessageExplode : public Message {
	MessageExplode() {
		type = MSG_EXPLODE;
	}
	Entity * entity;
};
struct MessageSetWaponReady : public Message {
	MessageSetWaponReady() {
		type = MSG_WEAPONREADY;
	}
};
struct MessageFire : public Message {
	enum Weapon {
		W_MAIN,
		W_SECODARY
	};
	MessageFire() {
		type = MSG_FIRE;
	}
	bool fire;
	Weapon weapon;
	double CurrentEnergy,energyConsumption, range, x, y, width, height, rotation;
	Entity * o_shot;
	
};
struct MessagGetColsestEnemy : public Message {
	MessagGetColsestEnemy(){
		type = MSG_GETCLOSESTENEMY;
	}
	Entity * o_enemy;
};
struct MessagGetEnemyLeader : public Message {
	MessagGetEnemyLeader() {
		type = MSG_GETENEMYLEADER;
	}
	Entity * o_enemy;
};

struct MessageGetAngularSpeed : public Message {
	MessageGetAngularSpeed(){
		type = MSG_GETANGULARSPEED;
	}
	double o_speed;
};
struct MessageGetLinearSpeed : public Message {
	MessageGetLinearSpeed() {
		type = MSG_GETLINEARSPEED;
	}
	double o_speed;
};
struct MessageSetMovement : public Message {
	MessageSetMovement() {
		type = MSG_SETMOVEMENT;
	}
	int32 linear, rotation;
};
struct MessageGetLookAhead : public Message {
	MessageGetLookAhead() {
		type = MSG_GETLOOKAHEAD;
	}
	int32 o_lookAhead;
};
struct MessageGetWeaponReady : public Message {
	MessageGetWeaponReady() {
		type = MSG_GETWEAPONREADY;
	}
	float availableEnergy;
	bool o_ready;
};
struct MessageGetAppropriateWeapon : public Message {
	enum Weapon {
		W_MAIN,
		W_SECODARY,
		W_NONE
	};
	MessageGetAppropriateWeapon() {
		type = MSG_GETAPPROPRIATEWEAPON;
	}
	float availableEnergy;
	float maxRange;
	Weapon o_weapon;
};
#endif // !SCM_MESSAGES_H

