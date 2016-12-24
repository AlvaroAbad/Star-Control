#include "..\include\checkenergytask.h"
#include "../../include\treecontext.h"

#include "../../../include/componentmessages.h"
#include "../../../include/entity.h"
void CheckEnergyTask::Init()
{
	isInitialized = true;
}

ITreeNode::TResult CheckEnergyTask::Run()
{
	TResult ret = E_FAIL;
	MessageGetEnergy msgGEnergy;
	msgGEnergy.energy = 0;
	owner->ReciveMessage(&msgGEnergy);
	MessageGetWeaponReady msgGWReady;
	msgGWReady.availableEnergy = msgGEnergy.energy;
	msgGWReady.o_ready =false;
	owner->ReciveMessage(&msgGWReady);
	if (msgGWReady.o_ready) {
		ret = E_SUCCESS;
	}
	return ret;
}
