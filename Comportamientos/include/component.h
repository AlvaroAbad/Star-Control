#ifndef SCM_COMPONENT_H
#define SCM_COMPOENT_H
struct Message;
class Entity;
class Component {
public:
	virtual void Update(float elapsed) = 0;
	virtual void ReciveMessage(Message * message) = 0;
	void SetFather(Entity * father) { this->father = father; }
	virtual ~Component() {};
protected:
	Entity * father;
};
#endif // !SCM_COMPONENT_H

