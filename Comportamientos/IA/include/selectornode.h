#ifndef SCM_IA_SELECTOR_H
#define SCM_IA_SELECTOR_H
#include "node.h"
#include <list>
class Entity;
class SelectorNode: public ITreeNode
{
public:
	SelectorNode():isInitialized(false) {};
	virtual ~SelectorNode();
	virtual void Init();
	virtual bool initialized();
	virtual TResult Run();
	virtual  ITreeNode * AddNode(ITreeNode * node);
	
private:
	std::list<ITreeNode *> nodes;
	bool isInitialized;
};

#endif // !SCM_IA_SELECTOR_H

