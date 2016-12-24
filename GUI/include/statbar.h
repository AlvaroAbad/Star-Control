#ifndef GUI_STATBAR_H
#define GUI_STATBAR_H

#include "control.h"
#include "../../Ugine/include/image.h"

class StatBar : public Control
{
public:
	StatBar(String * btnId, uint8 r, uint8 g, uint8 b, float value);

	virtual void Update() {};
	virtual void Render();
	virtual bool OnInputEvent(const GUIMessage * message) { return false; };
	virtual void Register(inputs key, inputs action) {};
	virtual void Unregister(inputs key, inputs action) {};
	virtual void Unregister() {}
	virtual void SetValue(float value) { this->value = value; }
	~StatBar() {};

protected:
	uint8 r, g, b;
	Image *capsule;
	float value;
};
#endif //!GUI_STATBAR_H
