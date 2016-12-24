#include "..\include\weaponscomponents.h"
#include "../include/component.h"

#define CASTMESSAGE(MessageType) MessageType * msg =static_cast<MessageType *>(message);

#pragma region SUBCOMPONENT_COOLDOWN
void SubComponentCooldown::Update(float elapsed)
{
	if (timeRemaing > 0) {
		timeRemaing -= elapsed;
		if (timeRemaing <= 0) {
			MessageSetWaponReady msgWReady;
			father->ReciveMessage(&msgWReady);
		}
	}
}

void SubComponentCooldown::ReciveMessage(Message * message)
{
	if (message->type == Message::MSG_FIRE) {
		timeRemaing = cooldown;
	}
}
#pragma endregion insert when the weapon has a cooldown

#pragma region SUBCOMPONENT_ENERGYCOST
void SubComponentEnergyCost::Update(float elapsed)
{
}

void SubComponentEnergyCost::ReciveMessage(Message * message)
{
	if (message->type == Message::MSG_FIRE) {
		CASTMESSAGE(MessageFire)
			if (msg->CurrentEnergy >= energyCost) {
				msg->energyConsumption = energyCost;
			}
			else {
				msg->fire = false;
			}
	}
}
#pragma endregion insert when the weapon consumes energy

#pragma region SUBCOMPONENT_RANGE
void SubComponentRange::Update(float elapsed)
{
}

void SubComponentRange::ReciveMessage(Message * message)
{
	if (message->type == Message::MSG_FIRE) {
		CASTMESSAGE(MessageFire)
			msg->range = range;
	}
}
#pragma endregion insert when the weapon has a range

void SubComponentDamage::Update(float elapsed)
{
}

void SubComponentDamage::ReciveMessage(Message * message)
{
}

void SubComponentForce::Update(float elapsed)
{
}

void SubComponentForce::ReciveMessage(Message * message)
{
}
