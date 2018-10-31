#version 430 core
out vec4 FragColor;
  
in vec4 vertexColor; 
in vec2 texCoords;
in vec3 normals;

void main()
{
    FragColor = vertexColor;
} 