#ifndef SCM_IA_SEQUENCE_H
#define SCM_IA_SEQUENCE_H
#include "node.h"
#include <list>
class SequenceNode : public ITreeNode
{
public:
	SequenceNode():isInitialized(false) {};
	virtual ~SequenceNode();
	virtual void Init();
	virtual bool initialized();
	virtual TResult Run();
	virtual  ITreeNode * AddNode(ITreeNode * node);
private:
	std::list<ITreeNode *> nodes;
	bool isInitialized;
};

#endif // !SCM_IA_SEQUENCE_H

