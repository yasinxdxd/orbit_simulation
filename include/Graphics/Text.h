#ifndef GO_TEXT_H
#define GO_TEXT_H

#include "Renderable.h"
#include "Font.h"

namespace go
{

	class Text : public go::Renderable
	{
	public:
		explicit Text();
		explicit Text(GOcchar* text);
		explicit Text(go::Font& font);
		explicit Text(GOcchar* text, go::Font& font);
		~Text();


		void setFont(go::Font& font);
		void setString(GOcchar* text);
		void setPosition(Vec2f) override;
		void setSize(Vec2f) override;
		Vec2f getPosition() const override;
		Vec2f getSize() const override;


	private:
		virtual void draw(go::Vec2ui windowSize) override;

	private:
		go::Font m_Font;
		std::string m_string;

	};

}

#endif // GO_TEXT_H