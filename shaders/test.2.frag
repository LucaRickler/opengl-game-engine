#version 430 core
out vec4 FragColor;
  
in vec4 vertexColor; 
in vec2 texCoords;
in vec3 normals;

uniform sampler2D tex;

void main()
{
	FragColor=texture(tex, texCoords);
}
