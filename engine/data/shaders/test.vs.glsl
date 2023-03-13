#version 450

layout (location = 0) in vec3 vsPos;

void main()
{
	gl_Position = vec4(vsPos, 1.0f);
}
