#include"game.h"

Game::Game()
	: mWindow()
{
	if (!glfwInit())
	{
		std::cerr << "ERROR::GLFW Init";
		exit(-1);
	}

	mWindow = glfwCreateWindow(1280, 720, "OpenGL Application", NULL, NULL);

	if (!mWindow)
	{
		glfwTerminate();
		exit(-1);
	}

	glfwMakeContextCurrent(mWindow);
	glewInit();

	//imgui here
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable; // Enable docking

	ImGui_ImplGlfw_InitForOpenGL(mWindow, true);
	ImGui_ImplOpenGL3_Init();

}

void Game::run()
{
	while (!glfwWindowShouldClose(mWindow))
	{
		glfwPollEvents();
		updateGUI();
		render();
	}

	shutdown();
}

void Game::render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 1, 0.5f, 0);

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	glfwSwapBuffers(mWindow);
}

void Game::updateGUI()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
	ImGui::ShowDemoWindow();
}

void Game::shutdown()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();
}

