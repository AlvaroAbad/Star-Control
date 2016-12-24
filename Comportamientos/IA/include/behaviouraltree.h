#ifndef SCM_IA_BEHAVIORALTREE_H
#define SCM_IA_BEHAVIORALTREE_H
#include "treecontext.h"
class ITreeNode;
class Entity;
class ABehaviouralTree
{
public:
	ABehaviouralTree() {};
	virtual ~ABehaviouralTree() { delete root; };
	virtual void Run()=0;
protected:
	TreeContext context;
	ITreeNode * root;
};
#endif // !SCM_IA_DRONEBEHAVIORALTREE_H