#ifndef WORLDDEFENDER_LEVEL_MANAGER
#define WORLDDEFENDER_LEVEL_MANAGER
#pragma warning(disable:4514)
class LevelManager {
public:
	enum SpaceShip {
		AVATAR,
		DREADNOUGH
	};
	enum PlayerType {
		HUMAN,
		EASY,
		MEDIUM,
		HARD
	};
	static LevelManager& Instance();

	SpaceShip GetPLayerOneSpaceShip() { return ssPlayer1; }
	SpaceShip GetPLayerTwoSpaceShip() { return ssPlayer2; }

	void SetPlayerOneSpceShip(SpaceShip ss) { ssPlayer1 = ss; }
	void SetPlayerTwoSpceShip(SpaceShip ss) { ssPlayer2 = ss; }

	PlayerType GetPLayerOneType() { return tPlayer1; }
	PlayerType GetPLayerTwoType() { return tPlayer2; }

	void SetPlayerOneType(PlayerType pt) { tPlayer1 = pt; }
	void SetPlayerTwoType(PlayerType pt) { tPlayer2 = pt; }

protected:
	LevelManager() {};
	virtual ~LevelManager() {};
private:
	static LevelManager *levelManager;
	SpaceShip ssPlayer1, ssPlayer2;
	PlayerType tPlayer1, tPlayer2;
};
#endif
