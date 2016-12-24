#ifndef UGINE_TTFFONT_H
#define UGINE_TTFFONT_H
#include "string.h"
#include "types.h"
#include "image.h"
#include "glyph.h"
class TTFFont {
public:
	TTFFont(const String& filename, float size);
	virtual~TTFFont();
	virtual const String& GetFilename() const { return fileName; }
	virtual const uint32 GetSize() const { return fontSize; }
	virtual bool IsValid() const { return image!=NULL; }
	virtual uint32 GetTextWidth(const String& text) const;
	virtual uint32 GetTextHeight(const String& text) const;
	virtual void Render(const String& text, double x, double y) const;
private:
	String fileName;
	float fontSize;
	Array<Glyph> *glyphs;
	Image * image;
};
#endif
