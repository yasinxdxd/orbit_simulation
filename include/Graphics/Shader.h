#ifndef GO_SHADER_H
#define GO_SHADER_H
//#define GLFW_INCLUDE_NONE

#include "Core/Definitions.h"
#include "Math/Vectors.h"
#include <string>
#include <iostream>
#include <fstream>

namespace go
{

	class Shader
	{
	public:
		explicit Shader();
		explicit Shader(GOcchar* vertex_path, GOcchar* frag_path);
		~Shader();
		void use();
	public:
		inline GOuint getProgramID() const { return m_ProgramID; }
	public:
		void setVertexAndFragment(GOcchar* vertex_path, GOcchar* frag_path);

	public:
		void setBool(const std::string& name, GObool value) const;
		void setInt(const std::string& name, GOint value) const;
		void setFloat(const std::string& name, GOfloat value) const;
		void setFloat_4(const std::string& name, GOfloat r, GOfloat g, GOfloat b, GOfloat a) const;
		void setFloat_3(const std::string& name, GOfloat r, GOfloat g, GOfloat b) const;

	private:
		GObool createShader(GOcchar* vertex_path, GOcchar* frag_path);
		GObool attachShader();
		
		std::string loadFromFile(GOcchar* filePath);

	private:
		std::string m_verPathStr;
		std::string m_fragPathStr;
		const char* m_verPath;
		const char* m_fragPath;
		GOuint m_ProgramID;
		GOuint m_VertexID;
		GOuint m_FragID;



	};

}
#endif //GO_SHADER_H