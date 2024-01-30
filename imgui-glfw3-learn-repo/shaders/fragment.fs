#version 330 Core
out vec4 FragColor;

in vec4 VertexColor;

void main()
{
    FragColor = VertexColor;
}