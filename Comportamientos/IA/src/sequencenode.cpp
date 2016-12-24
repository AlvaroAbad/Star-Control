#include "..\include\sequencenode.h"

SequenceNode::~SequenceNode()
{
	for (std::list<ITreeNode*>::iterator it = nodes.begin();it != nodes.end();++it) {
		delete (*it);
	}
}

void SequenceNode::Init()
{
	isInitialized = true;
}

bool SequenceNode::initialized()
{
	return isInitialized;
}

ITreeNode::TResult SequenceNode::Run()
{
	TResult result = E_SUCCESS;
	std::list<ITreeNode*>::iterator it = nodes.begin();
	while (it != nodes.end() && result == E_SUCCESS) {
		if (!(*it)->initialized()) {
			(*it)->Init();
		}
		result = (*it)->Run();
		++it;
	}
	return result;
}

ITreeNode * SequenceNode::AddNode(ITreeNode * node)
{
	nodes.push_back(node);
	return this;
}
