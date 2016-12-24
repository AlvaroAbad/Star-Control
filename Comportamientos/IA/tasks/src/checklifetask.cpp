#include "..\include\checklifetask.h"

#include "../../../include/componentmessages.h"
#include "../../../include/entity.h"
void CheckLifeTask::Init()
{
	MessageGetMaxLife msgGMLife;
	owner->ReciveMessage(&msgGMLife);
	MaxLife = msgGMLife.o_MaxLife;
	isInitialized = true;
}

ITreeNode::TResult CheckLifeTask::Run()
{
	TResult ret = E_FAIL;
	MessageGetLife msgGMLife;
	owner->ReciveMessage(&msgGMLife);
	if (msgGMLife.life / MaxLife > 0.25) {
		ret = E_SUCCESS;
	}
	return ret;
}
