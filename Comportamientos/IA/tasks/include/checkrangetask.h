#ifndef SCM_IA_CHECKRANGETASK_H
#define SCM_IA_CHECKRANGETASK_H

#include "tasknode.h"

class CheckRangeTask :public ATaskNode
{
public:
	CheckRangeTask(Entity * owner, TreeContext * context) :ATaskNode(owner, context) {}
	virtual ~CheckRangeTask() {};
	virtual void Init();
	virtual TResult Run();
private:
	Entity * rivalLeader;
};

#endif // !SCM_IA_CHECKALAIGNMENTTASK_H
