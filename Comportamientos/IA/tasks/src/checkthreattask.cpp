#include "../include/checkthreattask.h"
#include "../../include\treecontext.h"

#include "../../../include/componentmessages.h"
#include "../../../include/entity.h"
void CheckThreatTask::Init()
{
	isInitialized = true;
}

ITreeNode::TResult CheckThreatTask::Run()
{
	TResult ret = E_FAIL;
	MessagGetColsestEnemy msgGCEnemy;
	msgGCEnemy.o_enemy = nullptr;
	owner->ReciveMessage(&msgGCEnemy);
	if (msgGCEnemy.o_enemy) {
		context->SetValueEntity(TreeContext::KEY_THREAT, msgGCEnemy.o_enemy);
		ret = E_SUCCESS;
	}
	return ret;
}
