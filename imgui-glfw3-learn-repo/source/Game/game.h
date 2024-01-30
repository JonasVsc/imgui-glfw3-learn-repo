#include<iostream>
#include<gl/glew.h>
#include<GLFW/glfw3.h>
#include<imgui.h>
#include<imgui_impl_glfw.h>
#include<imgui_impl_opengl3.h>



class Game {

public:
	Game();
	void run();

private:
	void render();
	void update();
	void updateGUI();
	void processInput();
	void shutdown();
	void imguiInit();


private:
	GLFWwindow* mWindow;
	unsigned int mVAO;
	unsigned int mVBO;
	unsigned int mShaderProgram;


};