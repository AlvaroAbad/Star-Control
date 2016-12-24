#ifndef SCM_IA_CHECKALAIGNMENTTASK_H
#define SCM_IA_CHECKALAIGNMENTTASK_H

#include "tasknode.h"

class CheckAlignmentTask :public ATaskNode
{
public:
	CheckAlignmentTask(Entity * owner, TreeContext * context) :ATaskNode(owner, context) {}
	virtual ~CheckAlignmentTask() {};
	virtual void Init();
	virtual TResult Run();
private:
	Entity * rivalLeader;
};

#endif // !SCM_IA_CHECKALAIGNMENTTASK_H
