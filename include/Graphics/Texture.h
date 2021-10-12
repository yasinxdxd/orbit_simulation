#ifndef GO_TEXTURE_H
#define GO_TEXTURE_H


#include "Math/Vectors.h"
#include <string>
#include <iostream>

namespace go
{
	class Texture
	{
	public:
		explicit Texture();
		explicit Texture(GOcchar* path_file);
		~Texture();
	public:
		void loadFromFile(GOcchar* path_file);
		void loadFromMemory();

	public:
		operator GOuint () const noexcept;
		
	private:
		struct textureData
		{
			Vec2i size;
			GOint channels;
			GOuchar* data;
		}textureData;

		GOuint m_texture;
		
	friend class Sprite;

	};

}

#endif //GO_TEXTURE_H
