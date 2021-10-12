/*#version 330 core
in vec2 TexCoords;
out vec4 color;

uniform sampler2D text;
uniform vec3 textColor;

void main()
{
    vec4 sampled = vec4(1.0, 1.0, 1.0, texture(text, TexCoords).r);
    color = vec4(textColor, 0.2) * sampled;
}*/

#version 330 core
out vec4 FragColor;

in vec4 ourColor;
in vec2 TexCoord;

// text samplers
uniform sampler2D text;

void main()
{
	// multipling is for Coloring 
	FragColor = texture(text, TexCoord) * ourColor;
}