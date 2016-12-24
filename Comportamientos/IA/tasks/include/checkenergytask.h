#ifndef SCM_IA_CHECKENERGYTASK_H
#define SCM_IA_CHECKENERGYTASK_H

#include "tasknode.h"

class CheckEnergyTask :public ATaskNode
{
public:
	CheckEnergyTask(Entity * owner, TreeContext * context) :ATaskNode(owner, context) {}
	virtual ~CheckEnergyTask() {};
	virtual void Init();
	virtual TResult Run();
private:

};

#endif // !SCM_IA_CHECKENERGYTASK_H
