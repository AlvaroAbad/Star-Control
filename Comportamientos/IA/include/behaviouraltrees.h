#ifndef SCM_IA_DRONEBEHAVIORALTREE_H
#define SCM_IA_DRONEBEHAVIORALTREE_H
#include "treecontext.h"
#include "behaviouraltree.h"
class ITreeNode;
class Entity;
class SimpleAIBehaviouralTree: public ABehaviouralTree
{
public:
	SimpleAIBehaviouralTree(Entity * Owner);
	void Run();
};
class DroneAIBehaviouralTree: public ABehaviouralTree {
public:
	DroneAIBehaviouralTree(Entity * Owner);
	void Run();
};
#endif // !SCM_IA_DRONEBEHAVIORALTREE_H
