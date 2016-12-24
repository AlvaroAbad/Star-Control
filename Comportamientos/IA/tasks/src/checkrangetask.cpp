#include "..\include\checkrangetask.h"

#include "../../../include/componentmessages.h"
#include "../../../include/entity.h"

#include "../../../../Ugine/include/math.h"
void CheckRangeTask::Init()
{
	MessagGetEnemyLeader msgGEnemyLeader;
	msgGEnemyLeader.o_enemy = nullptr;
	owner->ReciveMessage(&msgGEnemyLeader);
	rivalLeader = msgGEnemyLeader.o_enemy;
	isInitialized = true;
}

ITreeNode::TResult CheckRangeTask::Run()
{
	TResult ret = E_FAIL;
	double maxRange = Distance(owner->x, owner->y, rivalLeader->x, rivalLeader->y);
	MessageGetEnergy msgGEnergy;
	msgGEnergy.energy = 0;
	owner->ReciveMessage(&msgGEnergy);
	MessageGetAppropriateWeapon msgGApropieteWeapon;
	msgGApropieteWeapon.availableEnergy = msgGEnergy.energy;
	msgGApropieteWeapon.maxRange = maxRange;
	msgGApropieteWeapon.o_weapon = MessageGetAppropriateWeapon::Weapon::W_NONE;
	owner->ReciveMessage(&msgGApropieteWeapon);
	if (msgGApropieteWeapon.o_weapon != MessageGetAppropriateWeapon::Weapon::W_NONE) {
		MessageFire msgFire;
		msgFire.weapon = static_cast<MessageFire::Weapon>(msgGApropieteWeapon.o_weapon);
		owner->ReciveMessage(&msgFire);
		ret = E_SUCCESS;
	}
	return ret;
}
