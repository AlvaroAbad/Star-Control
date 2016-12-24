#ifndef SCM_RESOURCESSTORE_H
#define SCM_RESOURCESSTORE_H
class TTFFont;
class Image;
class ResourceManager;
class ResourceStore {
public:
	static	ResourceStore& Instance();
	TTFFont* GetMainFont();
	TTFFont* GetDropDownFont();
	Image * GetMenuBackGround();
	Image * GetMenuImage();
	Image * GetMenuButtonNeutralImage();
	Image * GetMenuButtonPressedImage();
	Image * GetMenuButtonHooverImage();
	Image * GetMenuButtonDisabledImage();
	Image * GetMenuButtonBackImage();
	Image * GetMenuButtonBackPressedImage();
	Image * GetMenuButtonBackHooverImage();
	Image * GetDropDownListButtonImage();
	Image * GetDropDownListButtonHooverImage();
	Image * GetDropDownButtonImage();
	Image * GetDropDownButtonPressedImage();
	Image * GetDropDownButtonHooverImage();
	Image * GetImageSelectorImage();
	Image * GetPlayer1Holder();
	Image * GetPlayer2Holder();
	Image * GetCapsuleImage();

	Image * GetAvatarImage();
	Image * GetDreadnoughtImage();
	Image * GetDroneImage(unsigned short int hFrames, unsigned short int vFrames);
	Image * GetShipExplosionImage(unsigned short int hFrames, unsigned short int vFrames, int explosion);
	Image * GetSmallExplosionImage();
	Image * GetMissileImage();

protected:
	ResourceStore() {
		mainFont = nullptr;
		menuBackGround = nullptr;
		dropdownFont = nullptr;
		menuImage = nullptr;
		menuButtonNeutral = nullptr;
		menuButtonPressed = nullptr;
		menuButtonHoover = nullptr;
		menuButtonDisabled = nullptr;
		menuButtonBackNeutral = nullptr;
		menuButtonBackPressed = nullptr;
		menuButtonBackHoover=nullptr;
		dropDownListButtonNeutral = nullptr;
		dropDownListButtonHoover = nullptr;
		dropDownButtonNeutral = nullptr;
		dropDownButtonPressed = nullptr;
		dropDownButtonHoover = nullptr;
		imageSelector = nullptr;
		player1Holder = nullptr;
		player2Holder = nullptr;
		capsule = nullptr;
		avatar = nullptr;
		dreadnought = nullptr;
		drone = nullptr;
		missile = nullptr;
		smallExplosion = nullptr;
	}
	virtual ~ResourceStore();
private:
	static ResourceStore* store;
	TTFFont * mainFont;
	TTFFont * dropdownFont;
	Image * menuBackGround;
	Image * menuImage;
	Image * menuButtonNeutral;
	Image * menuButtonPressed;
	Image * menuButtonHoover;
	Image * menuButtonDisabled;
	Image * menuButtonBackNeutral;
	Image * menuButtonBackPressed;
	Image * menuButtonBackHoover;
	Image * dropDownListButtonNeutral;
	Image * dropDownListButtonHoover;
	Image * dropDownButtonNeutral;
	Image * dropDownButtonPressed;
	Image * dropDownButtonHoover;
	Image * imageSelector;
	Image * player1Holder;
	Image * player2Holder;
	Image * capsule;

	Image * avatar;
	Image * dreadnought;
	Image * drone;
	Image * missile;
	Image * smallExplosion;

#define MAIN_FONT_DIR "../data/Fonts/spaceage.ttf"
#define MAIN_DROPDOWN_FONT_DIR "../data/Fonts/DIGITALDREAM.ttf"
#define MENU_BACKGROUND_DIR "../data/ui/mainmenubg.jpg"
#define MENU_IMAGE_DIR "../data/ui/mainmenu.png"
#define MENU_BUTTON_NEUTRAL_DIR "../data/ui/mainmenubutton.png"
#define MENU_BUTTON_PRESSED_DIR "../data/ui/mainmenubuttonpressed.png"
#define MENU_BUTTON_HOOVER_DIR "../data/ui/mainmenubuttonhoover.png"
#define MENU_BUTTON_DISABLED_DIR "../data/ui/mainmenubuttondisabled.png"
#define MENU_BUTTON_BACK_DIR "../data/ui/back.png"
#define MENU_BUTTON_BACK_PRESSED_DIR "../data/ui/backpressed.png"
#define MENU_BUTTON_BACK_HOOVER_DIR "../data/ui/backhoover.png"
#define MENU_DROPDOWNLIST_BUTTON_NEUTRAL_DIR "../data/ui/dropdownlistbutton.png"
#define MENU_DROPDOWNLIST_BUTTON_BACK_HOOVER_DIR "../data/ui/dropdownlistbuttonhoover.png"
#define DROPDOWN_BUTTON_BACK_DIR "../data/ui/dropdownbutton.png"
#define DROPDOWN_BUTTON_BACK_PRESSED_DIR "../data/ui/dropdownbuttonpressed.png"
#define DROPDOWN_BUTTON_BACK_HOOVER_DIR "../data/ui/dropdownbuttonHoover.png"
#define MENU_IMAGE_SELECTOR_DIR "../data/ui/imageselector.png"
#define MENU_PLAYER1_HOLDER_DIR "../data/ui/player1dataholder.png"
#define MENU_PLAYER2_HOLDER_DIR "../data/ui/player2dataholder.png"
#define MENU_CAPSULE_DIR "../data/ui/statcapsule.png"

#define AVATAR_DIR "../data/spaceships/avatar/ship.png"
#define DREADNOUGHT_DIR "../data/spaceships/dreadnought/ship.png"
#define DRONE_DIR "../data/spaceships/dreadnought/drone.png"
#define MISSILE_DIR "../data/spaceships/dreadnought/missile.png"
#define SHIPEXPLOSION_DIR(explosion) String("../data/explosions/shipexplosion")+String::FromInt(explosion)+String(".png")
#define SMALLEXPLOSION_DIR "../data/explosions/smallexplosions.png"

};
#endif // !SCM_RESOURCESSTORE_H

