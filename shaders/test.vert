#version 430 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 uv;
layout (location = 3) in vec3 aNorm;

out vec4 vertexColor;
out vec2 texCoords;
out vec3 normals;

uniform mat4 transform;

void main()
{
	gl_Position = transform * vec4(aPos, 1.0);
    vertexColor = vec4(color, 1.0);
    texCoords = uv;
    normals = aNorm;
}
