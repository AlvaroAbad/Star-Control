#ifndef SCM_IA_NODE_H
#define SCM_IA_NODE_H

class ITreeNode {
public:
	enum TResult {
		E_RUNNING,
		E_SUCCESS,
		E_FAIL
	};
	virtual void Init() = 0;
	virtual TResult Run() = 0;
	virtual ITreeNode * AddNode(ITreeNode * node) = 0;
	virtual bool initialized() = 0;
};
#endif // !SCM_IA_NODE_H