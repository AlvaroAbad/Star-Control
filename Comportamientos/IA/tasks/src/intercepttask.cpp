#include "..\include\intercepttask.h"

#include "../../../include/componentmessages.h"
#include "../../../include/entity.h"

#include "../../../../Ugine/include/math.h"
void InterceptTask::Init()
{
	MessagGetEnemyLeader msgGEnemyLeader;
	msgGEnemyLeader.o_enemy = nullptr;
	owner->ReciveMessage(&msgGEnemyLeader);
	rivalLeader = msgGEnemyLeader.o_enemy;
	MessageGetLinearSpeed msgGLinearSpeed;
	owner->ReciveMessage(&msgGLinearSpeed);
	linearSpeed = msgGLinearSpeed.o_speed;
	isInitialized = true;
}

ITreeNode::TResult InterceptTask::Run()
{
	Vec2D target, Direction;
	float myRadius, threatRadius;
	MessageSetMovement msgMovement;
	target.x = rivalLeader->x - owner->x;
	target.y = rivalLeader->y - owner->y;

	myRadius = (owner->width > owner->height ? owner->width / 2 : owner->height / 2);
	threatRadius = (rivalLeader->width > rivalLeader->height ? rivalLeader->width / 2 : rivalLeader->height / 2);
	msgMovement.linear = 0;
	if (target.length() > threatRadius + myRadius+10) {
		msgMovement.linear = -1;
	} else {
		msgMovement.linear = 0;
	}

	Direction.x = -DegCos(owner->rotation - 90);
	Direction.y = DegSin(owner->rotation - 90);



	Direction.normalize();
	target.normalize();

	msgMovement.rotation = 0;
	if (Direction.Cross(target) > 0) {
		msgMovement.rotation = 1;
	}
	else if(Direction.Cross(target) < 0) {
		msgMovement.rotation = -1;
	}
	owner->ReciveMessage(&msgMovement);
	return E_SUCCESS;
}
