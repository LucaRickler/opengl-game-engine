#version 430 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 uv;
layout (location = 3) in vec3 aNorm;

out VData{
  vec4 vertexColor;
  vec2 texCoords;
  vec3 normals;
} vdata; 

layout (std140) uniform Matrices
{
    mat4 view;
    mat4 projection;
};

uniform mat4 model;

void main()
{
	gl_Position = projection * view * model * vec4(aPos, 1.0);
  vdata.vertexColor = vec4(color, 1.0);
  vdata.texCoords = uv;
  vdata.normals = aNorm;
}
