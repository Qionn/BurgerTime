#version 450 core

out vec4 oColor;

uniform vec3 uColor;

void main()
{
	oColor = vec4(uColor, 1.0f);
}
