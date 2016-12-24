#ifndef SCM_IA_CHECKTHREATTASK_H
#define SCM_IA_CHECKTHREATTASK_H

#include "tasknode.h"

class CheckThreatTask :public ATaskNode
{
public:
	CheckThreatTask(Entity * owner, TreeContext * context) :ATaskNode(owner,context) {}
	virtual ~CheckThreatTask() {};
	virtual void Init();
	virtual TResult Run();
private:

};

#endif // !SCM_IA_CHECKTHREATTASK_H

