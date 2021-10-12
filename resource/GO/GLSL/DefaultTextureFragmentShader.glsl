#version 330 core
out vec4 FragColor;

in vec4 ourColor;
in vec2 TexCoord;

// texture samplers
uniform sampler2D texture1;

void main()
{
	// multipling is for Coloring 
	FragColor = texture(texture1, TexCoord) * ourColor;
}