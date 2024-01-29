#include<iostream>
#include<GLFW/glfw3.h>

int main()
{

	GLFWwindow* window;


	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(1280, 720, "ImGui-GLFW-OpenGL Application", 0, 0);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0, 1, 0.5f, 0);
		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}