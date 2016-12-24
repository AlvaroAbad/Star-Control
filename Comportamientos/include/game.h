#ifndef SCM_GAME_H
#define SCM_GAME_H
class World;
class UserInterface;
#pragma warning(disable:4514)
class Game
{
public:
	Game() {};
	~Game();
	void initialize();
	void run();
	void draw() const;
	void getInput();
	bool isGameEnd();
private:
	World * world;
	UserInterface * ui;
};
#endif // !SCM_GAME_H

