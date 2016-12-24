#ifndef SCM_SUBCOMPONENT_H
#define SCM_SUBCOMPONENT_H
struct Message;
class Component;
class SubComponent {
public:
	virtual void Update(float elapsed) = 0;
	virtual void ReciveMessage(Message * message) = 0;
	void SetFather(Component * father) { this->father = father; }
protected:
	Component * father;
};
#endif // !SCM_SUBCOMPONENT_H
