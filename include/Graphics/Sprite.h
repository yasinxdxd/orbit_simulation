#ifndef GO_SPRITE_H
#define GO_SPRITE_H

#include "Graphics/Renderable.h"
#include "Graphics/Texture.h"


namespace go
{

	class Sprite : public go::Renderable
	{
	public:
		explicit Sprite();
		explicit Sprite(go::Texture& texture);
		~Sprite();

		//Setters:
		void setTexture(Texture& texture);
		void setPosition(Vec2f) override;
		void setTextureCoords(Vec2f, Vec2f) override;
		void setOrigin(Vec2f) override;
		void setSize(Vec2f) override;
		void setRotatiton(GOfloat angle) override;
		void setColor(GOsint r, GOsint g, GOsint b) override;
		void setColor(GOsint r, GOsint g, GOsint b, GOsint a) override;
		//Getters:
		Vec2f getPosition() const override;
		Vec2f getOrigin() const override;
		Vec2f getSize() const override;
		GOfloat getRotatiton() const override;
	
	
	private:
		virtual void draw(go::Vec2ui windowSize) override;

	private:
		Texture* m_Texture;
	};

}


#endif //GO_SPRITE_H