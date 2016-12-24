#ifndef SCM_IA_INTERCEPTTASK_H
#define SCM_IA_INTERCEPTTASK_H

#include "tasknode.h"

class InterceptTask : public ATaskNode
{
public:
	InterceptTask(Entity * owner, TreeContext * context) :ATaskNode(owner, context) {};
	virtual ~InterceptTask() {};
	virtual void Init();
	virtual TResult Run();
private:
	double linearSpeed;
	Entity * rivalLeader;
};
#endif // !SCM_IA_INTERCEPTTASK_H
