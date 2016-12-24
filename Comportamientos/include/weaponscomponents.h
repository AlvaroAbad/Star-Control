#ifndef SCM_WEAPONCOMPONENTS_H
#define SCM_WEAPONCOMPONENTS_H

#include "subcomponent.h"
#include "componentmessages.h"

#pragma region SUBCOMPONENT_COOLDOWN
class SubComponentCooldown : public SubComponent {
public:
	SubComponentCooldown(float cooldown) :cooldown(cooldown), timeRemaing(cooldown){};
	virtual ~SubComponentCooldown() {};
	virtual void Update(float elapsed);
	virtual void ReciveMessage(Message * message);
private:
	float cooldown, timeRemaing;
};
#pragma endregion insert when the weapon has a cooldown

#pragma region SUBCOMPONENT_COST
class SubComponentEnergyCost : public SubComponent {
public:
	SubComponentEnergyCost(float energyCost) :energyCost(energyCost) {};
	virtual ~SubComponentEnergyCost() {};
	virtual void Update(float elapsed);
	virtual void ReciveMessage(Message * message);
private:
	float energyCost;
};
#pragma endregion insert when the weapon has a cooldown
#pragma region SUBCOMPONENT_RANGE
class SubComponentRange : public SubComponent {
public:
	SubComponentRange(float range) :range(range) {};
	virtual ~SubComponentRange() {};
	virtual void Update(float elapsed);
	virtual void ReciveMessage(Message * message);
private:
	float range;
};
#pragma endregion insert when the weapon has a range

#pragma region SUBCOMPONENT_DAMAGE
class SubComponentDamage : public SubComponent {
public:
	SubComponentDamage(float damage) :damage(damage) {};
	virtual ~SubComponentDamage() {};
	virtual void Update(float elapsed);
	virtual void ReciveMessage(Message * message);
private:
	float damage;
};
#pragma endregion insert when the weapon inflicts damage

#pragma region SUBCOMPONENT_FORCE
class SubComponentForce : public SubComponent {
public:
	SubComponentForce(float force) :force(force) {};
	virtual ~SubComponentForce() {};
	virtual void Update(float elapsed);
	virtual void ReciveMessage(Message * message);
private:
	float force;
};
#pragma endregion insert when the weapon Applies a force to the objective
#endif // !SCM_WEAPONCOMPONENTS_H

