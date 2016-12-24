#ifndef SCM_UI_H
#define SCM_UI_H
class Window;
class World;
class StatBar;
class UserInterface
{
public:
	UserInterface(World * world);
	void Init();
	void run();
	void draw();
	void getInputs();
	~UserInterface();

private:
	
	Window * HUD;
	World * world;
	StatBar * lifeP2, *lifeP1;
	StatBar * energyP2, *energyP1;
};
#endif // !SCM_UI_H
