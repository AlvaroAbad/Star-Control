#ifndef SCM_IA_TASKNODE_H
#define SCM_IA_TASKNODE_H

#include "../../include/node.h"
class Entity;
class TreeContext;
class ATaskNode: public ITreeNode
{
public:
	ATaskNode(Entity * owner, TreeContext * context) :owner(owner), context(context), isInitialized(false){}
	virtual ~ATaskNode() {}
	virtual bool initialized() { return isInitialized; }
	virtual  ITreeNode * AddNode(ITreeNode * node) { return nullptr; }
protected:
	Entity * owner;
	TreeContext * context;
	bool isInitialized;
};


#endif // !SCM_IA_TASKNODE_H

