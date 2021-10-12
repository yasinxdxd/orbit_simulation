#ifndef GO_VERTEXARRAY_H
#define GO_VERTEXARRAY_H

#include "Graphics/Vertex.h"
#include <vector>

namespace go
{


	class VertexArray
	{
	public:
		explicit VertexArray();
		~VertexArray();

	protected:

		//void setPositionVertices(go::Vec2f origin, go::Vec2f position, go::Vec2f size, go::Vec2ui windowsSize);
		void setPositionAndRotationVertices(go::Vec2f origin, go::Vec2f position, go::Vec2f size, go::Vec2ui windowsSize, GOfloat angle);
		void setTextureCoords(go::Vec2f position, go::Vec2f size);
		void setColorVertices(GOsint r, GOsint g, GOsint b, GOsint a, GOsint vertex);
		void bind();
		void unBind();

	private:

		GOfloat vertices[36] = {
			// positions          // colors					// texture coords
			-0.0f,  0.0f, 0.0f,   1.0f, 1.0f, 1.0f,	1.0f,	0.0f, 0.0f, // top left 
			 0.0f,  0.0f, 0.0f,   1.0f, 1.0f, 1.0f,	1.0f,	1.0f, 0.0f, // top right
			 0.0f, -0.0f, 0.0f,   1.0f, 1.0f, 1.0f,	1.0f,	1.0f, 1.0f, // bottom right
			-0.0f, -0.0f, 0.0f,   1.0f, 1.0f, 1.0f,	1.0f,	0.0f, 1.0f  // bottom left
		};


		/*0.0f, 1.0f,
			1.0f, 1.0f,
			1.0f, 0.0f,
			0.0f, 0.0f*/




		GOuint indices[6] = {
			0, 1, 2, // first triangle
			2, 3, 0  // second triangle
		};

		std::vector<Vertex> m_vertecies;
		
		
		GOuint VAO;
		GOuint VBO;
		GOuint EBO;

		friend class Renderable;
		friend class Sprite;
		friend class Text;

	};

}


#endif // GO_VERTEXARRAY_H