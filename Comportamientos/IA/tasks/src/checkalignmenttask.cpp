#include "..\include\checkalignmenttask.h"

#include "../../../include/componentmessages.h"
#include "../../../include/entity.h"

#include "../../../../Ugine/include/math.h"

#include "../../../../Ugine/include/renderer.h"
void CheckAlignmentTask::Init()
{
	MessagGetEnemyLeader msgGEnemyLeader;
	msgGEnemyLeader.o_enemy = nullptr;
	owner->ReciveMessage(&msgGEnemyLeader);
	rivalLeader = msgGEnemyLeader.o_enemy;
	isInitialized = true;
}

ITreeNode::TResult CheckAlignmentTask::Run()
{
	TResult ret = E_FAIL;
	Vec2D target, direction;
	target.x = rivalLeader->x - owner->x;
	target.y = rivalLeader->y - owner->y;

	direction.x = -DegCos(owner->rotation - 90);
	direction.y = DegSin(owner->rotation - 90);

	if (abs(static_cast<int>(direction.Angle(target))) < 10) {
		ret = E_SUCCESS;
	}

	return ret;
}
