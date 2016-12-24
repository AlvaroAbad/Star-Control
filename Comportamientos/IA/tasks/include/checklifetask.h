#ifndef SCM_IA_CHECKLIFETASK_H
#define SCM_IA_CHECKLIFETASK_H

#include "tasknode.h"

class CheckLifeTask :public ATaskNode
{
public:
	CheckLifeTask(Entity * owner, TreeContext * context) :ATaskNode(owner, context) {}
	virtual ~CheckLifeTask() {};
	virtual void Init();
	virtual TResult Run();
private:
	double MaxLife;
};

#endif // !SCM_IA_CHECKENERGYTASK_H#pragma once
