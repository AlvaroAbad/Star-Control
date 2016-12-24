#include "../include/calcrotationtask.h"
#include "../../include\treecontext.h"

#include "../../../include/componentmessages.h"
#include "../../../include/entity.h"

#include "../../../../Ugine/include/math.h"


void CalculateRotationTask::Init()
{
	MessageGetLinearSpeed msgGLinearSpeed;
	owner->ReciveMessage(&msgGLinearSpeed);
	linearSpeed = msgGLinearSpeed.o_speed;
	MessageGetLookAhead msgGLookAhead;
	owner->ReciveMessage(&msgGLookAhead);
	lookAhead = msgGLookAhead.o_lookAhead;
	isInitialized = true;
}

ITreeNode::TResult CalculateRotationTask::Run()
{
	TResult ret = E_SUCCESS;
	Entity * enemy;
	context->GetValueEntity(TreeContext::KEY_THREAT, &enemy);
	Vec2D direction, threat, closestPoint;
	float projection, distance, myRadius, threatRadius;

	myRadius = (owner->width > owner->height ? owner->width / 2 : owner->height / 2);
	threatRadius = (enemy->width > enemy->height ? enemy->width / 2 : enemy->height / 2);


	direction.x = DegCos(enemy->rotation - 90);
	direction.y = DegSin(enemy->rotation - 90);
	threat.x = owner->x - enemy->x;
	threat.y = owner->y - enemy->y;

	projection = threat.Dot(direction);


	closestPoint.x = enemy->x + direction.x*projection;
	closestPoint.y = enemy->y + direction.x*projection;

	distance = Distance(closestPoint.x, closestPoint.y, owner->x, owner->y);
	if (distance < lookAhead + threatRadius) {
		direction.x = DegCos(owner->rotation - 90)*linearSpeed;
		direction.y = DegSin(owner->rotation - 90)*-linearSpeed;
		direction.normalize();
		projection = threat.Dot(direction);
		MessageSetMovement msgMovement;
		if (projection > 0 && projection < linearSpeed) {
			threat.normalize();
			if (threat.Cross(direction) > 0) {
				msgMovement.linear = -1;
				msgMovement.rotation = 1;
			}
			else {
				msgMovement.linear = -1;
				msgMovement.rotation = -1;
			}
		}
		else {
			msgMovement.linear = -1;
			msgMovement.rotation = 0;
			context->SetValueDouble(TreeContext::KEY_ROTATION, 0);
		}
		owner->ReciveMessage(&msgMovement);
		ret = E_SUCCESS;
	}
	return ret;
}
