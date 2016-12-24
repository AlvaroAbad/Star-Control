#include "..\include\selectornode.h"

SelectorNode::~SelectorNode()
{
	for (std::list<ITreeNode*>::iterator it = nodes.begin();it != nodes.end();++it) {
		delete (*it);
	}
}

void SelectorNode::Init()
{
	isInitialized = true;
}

bool SelectorNode::initialized()
{
	return isInitialized;
}

ITreeNode::TResult SelectorNode::Run()
{
	TResult result = E_FAIL;
	std::list<ITreeNode*>::iterator it = nodes.begin();
	while ( it != nodes.end() && result==E_FAIL) {
		if (!(*it)->initialized()) {
			(*it)->Init();
		}
		result=(*it)->Run();
		++it;
	}
	return result;
}

ITreeNode * SelectorNode::AddNode(ITreeNode * node)
{
	nodes.push_back(node);
	return this;
}
