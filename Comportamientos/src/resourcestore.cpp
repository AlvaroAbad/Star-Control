#include "..\include\resourcestore.h"
#include "../../Ugine/include/resourcemanager.h"
ResourceStore* ResourceStore::store = nullptr;

ResourceStore & ResourceStore::Instance() {
	if (!store)
		store = new ResourceStore();
	return *store;
}

TTFFont * ResourceStore::GetMainFont() {
	if (!mainFont) {
		mainFont = ResourceManager::Instance().LoadTTFFont(MAIN_FONT_DIR, 30);
	}
	return mainFont;
}

TTFFont * ResourceStore::GetDropDownFont()
{
	if (!dropdownFont) {
		dropdownFont = ResourceManager::Instance().LoadTTFFont(MAIN_DROPDOWN_FONT_DIR, 12);
	}
	return dropdownFont;
}

Image * ResourceStore::GetMenuBackGround()
{
	if (!menuBackGround) {
		menuBackGround = ResourceManager::Instance().LoadImage(MENU_BACKGROUND_DIR);
	}
	return menuBackGround;
}

Image * ResourceStore::GetMenuImage()
{
	if (!menuImage) {
		menuImage = ResourceManager::Instance().LoadImage(MENU_IMAGE_DIR);
	}
	return menuImage;
}

Image * ResourceStore::GetMenuButtonNeutralImage()
{
	if (!menuButtonNeutral) {
		menuButtonNeutral = ResourceManager::Instance().LoadImage(MENU_BUTTON_NEUTRAL_DIR);
	}
	return menuButtonNeutral;
}

Image * ResourceStore::GetMenuButtonPressedImage()
{
	if (!menuButtonPressed) {
		menuButtonPressed = ResourceManager::Instance().LoadImage(MENU_BUTTON_PRESSED_DIR);
	}
	return menuButtonPressed;
}

Image * ResourceStore::GetMenuButtonHooverImage()
{
	if (!menuButtonHoover) {
		menuButtonHoover = ResourceManager::Instance().LoadImage(MENU_BUTTON_HOOVER_DIR);
	}
	return menuButtonHoover;
}

Image * ResourceStore::GetMenuButtonDisabledImage()
{
	if (!menuButtonDisabled) {
		menuButtonDisabled = ResourceManager::Instance().LoadImage(MENU_BUTTON_DISABLED_DIR);
	}
	return menuButtonDisabled;
}

Image * ResourceStore::GetMenuButtonBackImage()
{
	if (!menuButtonBackNeutral) {
		menuButtonBackNeutral = ResourceManager::Instance().LoadImage(MENU_BUTTON_BACK_DIR);
	}
	return menuButtonBackNeutral;
}

Image * ResourceStore::GetMenuButtonBackPressedImage()
{
	if (!menuButtonBackPressed) {
		menuButtonBackPressed = ResourceManager::Instance().LoadImage(MENU_BUTTON_BACK_PRESSED_DIR);
	}
	return menuButtonBackPressed;
}

Image * ResourceStore::GetMenuButtonBackHooverImage()
{
	if (!menuButtonBackHoover) {
		menuButtonBackHoover = ResourceManager::Instance().LoadImage(MENU_BUTTON_BACK_HOOVER_DIR);
	}
	return menuButtonBackHoover;
}

Image * ResourceStore::GetDropDownListButtonImage()
{
	if (!dropDownListButtonNeutral) {
		dropDownListButtonNeutral = ResourceManager::Instance().LoadImage(MENU_DROPDOWNLIST_BUTTON_NEUTRAL_DIR);
	}
	return dropDownListButtonNeutral;
}

Image * ResourceStore::GetDropDownListButtonHooverImage()
{
	if (!dropDownListButtonHoover) {
		dropDownListButtonHoover = ResourceManager::Instance().LoadImage(MENU_DROPDOWNLIST_BUTTON_BACK_HOOVER_DIR);
	}
	return dropDownListButtonHoover;
}

Image * ResourceStore::GetDropDownButtonImage()
{

	if (!dropDownButtonNeutral) {
		dropDownButtonNeutral = ResourceManager::Instance().LoadImage(DROPDOWN_BUTTON_BACK_DIR);
	}
	return dropDownButtonNeutral;
}

Image * ResourceStore::GetDropDownButtonPressedImage()
{
	if (!dropDownButtonPressed) {
		dropDownButtonPressed = ResourceManager::Instance().LoadImage(DROPDOWN_BUTTON_BACK_PRESSED_DIR);
	}
	return dropDownButtonPressed;
}

Image * ResourceStore::GetDropDownButtonHooverImage()
{
	if (!dropDownButtonHoover) {
		dropDownButtonHoover = ResourceManager::Instance().LoadImage(DROPDOWN_BUTTON_BACK_HOOVER_DIR);
	}
	return dropDownButtonHoover;
}

Image * ResourceStore::GetAvatarImage()
{
	if (!avatar) {
		avatar = ResourceManager::Instance().LoadImage(AVATAR_DIR);
	}
	return avatar;
}

Image * ResourceStore::GetDreadnoughtImage()
{
	if (!dreadnought) {
		dreadnought = ResourceManager::Instance().LoadImage(DREADNOUGHT_DIR);
	}
	return dreadnought;
}

Image * ResourceStore::GetDroneImage(unsigned short int hFrames, unsigned short int vFrames)
{
	if (!drone) {
		drone = ResourceManager::Instance().LoadImage(DRONE_DIR, hFrames, vFrames);
	}
	return drone;
}

Image * ResourceStore::GetShipExplosionImage(unsigned short int hFrames, unsigned short int vFrames, int explosion)
{
		return ResourceManager::Instance().LoadImage(SHIPEXPLOSION_DIR(explosion), hFrames, vFrames);
}

Image * ResourceStore::GetSmallExplosionImage()
{
	if (!smallExplosion) {
		smallExplosion= ResourceManager::Instance().LoadImage(SMALLEXPLOSION_DIR, 10, 4);
	}
	return smallExplosion;
}

Image * ResourceStore::GetMissileImage()
{

	if (!missile) {
		missile = ResourceManager::Instance().LoadImage(MISSILE_DIR);
	}
	return missile;
}

Image * ResourceStore::GetImageSelectorImage()
{
	if (!imageSelector) {
		imageSelector = ResourceManager::Instance().LoadImage(MENU_IMAGE_SELECTOR_DIR);
	}
	return imageSelector;
}

Image * ResourceStore::GetPlayer1Holder()
{
	if (!player1Holder) {
		player1Holder = ResourceManager::Instance().LoadImage(MENU_PLAYER1_HOLDER_DIR);
	}
	return player1Holder;
}
Image * ResourceStore::GetPlayer2Holder()
{
	if (!player2Holder) {
		player2Holder = ResourceManager::Instance().LoadImage(MENU_PLAYER2_HOLDER_DIR);
	}
	return player2Holder;
}

Image * ResourceStore::GetCapsuleImage()
{
	if (!capsule) {
		capsule = ResourceManager::Instance().LoadImage(MENU_CAPSULE_DIR);
	}
	return capsule;
}

ResourceStore::~ResourceStore() {
}
