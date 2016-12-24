#ifndef SCM_IA_CALCROTATIONTASK_H
#define SCM_IA_CALCROTATIONTASK_H

#include "tasknode.h"

class CalculateRotationTask: public ATaskNode
{
public:
	CalculateRotationTask(Entity * owner, TreeContext * context) :ATaskNode(owner, context) {};
	virtual ~CalculateRotationTask() {};
	virtual void Init();
	virtual TResult Run();
private:
	double linearSpeed;
	double lookAhead;
};
#endif // !SCM_IA_CALCROTATIONTASK_H

