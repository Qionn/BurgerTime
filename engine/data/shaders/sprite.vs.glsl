#version 450 core

layout (location = 0) in vec3 vsPosition;
layout (location = 1) in vec2 vsTexCoord;

uniform mat4 uModel;
uniform mat4 uProjection;

void main()
{
	gl_Position = uProjection * uModel * vec4(vsPosition, 1.0f);
}
