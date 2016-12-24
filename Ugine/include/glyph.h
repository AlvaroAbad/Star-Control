#ifndef UGINE_GLYPH_H
#define UGINE_GLYPH_H
#include "types.h"
class Glyph {
public:
	Glyph() {};
	Glyph(uint32 offsetX, uint32 offsetY, uint32 width, uint32 height);
	void setSize(uint32 width, uint32 height) {
		this->width = width;
		this->height = height;
	}
	void setWidth(uint32 width) { this->width = width; }
	uint32 getWidth() const{ return this->width; }
	void setHeight(uint32 height) { this->height = height; }
	uint32 getHeight() const { return this->height; }
	void setOrigin(uint32 X, uint32 Y) { 
		this->X = X;
		this->Y = Y;
	}
	void setX(uint32 X) { this->X = X; }
	uint32 getX()const { return this->X; }
	void setY(uint32 Y) { this->Y = Y; }
	uint32 getY()const { return this->Y; }
	void setOffset(int32 offsetX, int32 offsetY) {
		this->offsetX = offsetX;
		this->offsetY = offsetY;
	}
	void setOffsetX(double offsetX) { this->offsetX = offsetX; }
	double getOffsetX()const { return this->offsetX; }
	void setOffsetY(double offsetY) { this->offsetY = offsetY; }
	double getOffsetY()const { return this->offsetY; }
private:
	uint32 X;
	uint32 Y;
	uint32 height;
	uint32 width;
	double offsetX;
	double offsetY;
};
#endif
