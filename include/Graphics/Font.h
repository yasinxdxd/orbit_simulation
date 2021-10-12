#ifndef GO_FONT_H
#define GO_FONT_H

#include "Math/Vectors.h"
#include <map>

typedef struct FT_LibraryRec_* FT_Library;
typedef struct FT_FaceRec_* FT_Face;

namespace go
{

	struct m_character
	{
		GOuint m_texture;	 // ID handle of the glyph texture
		go::Vec2i size;      // Size of glyph
		go::Vec2i bearing;   // Offset from baseline to left/top of glyph
		GOuint advance;		 // Horizontal offset to advance to next glyph
	};

	class Font
	{
	public:
		explicit Font();
		explicit Font(GOcchar* path_file);
		~Font();

		void loadFromFile(GOcchar* path_file);

	private:
		

	private:
		FT_Library ft;
		FT_Face face;

		std::map<char, m_character> m_FontCharacters;

		
		friend class Text;
	};

}


#endif // GO_FONT_H