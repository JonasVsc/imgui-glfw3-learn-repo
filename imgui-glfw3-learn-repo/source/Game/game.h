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
	void render();
	void updateGUI();
	void shutdown();


private:
	GLFWwindow* mWindow;


};