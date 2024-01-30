#include"game.h"

Game::Game()
	:	mWindow()
{
	// glfw initi and configure
	glfwInitializationAndConfiguration();

	// glfw window creation
	glfwWindowCreation();

	// glew init
	glewInit();

	//imgui initi and configure
	imguiInitializationAndConfiguration();
}

void Game::glfwInitializationAndConfiguration()
{
	if (!glfwInit())
	{
		std::cerr << "ERROR::GLFW Init";
		exit(-1);
	}
}

void Game::glfwWindowCreation()
{
	if (!mWindow)
	{
		glfwTerminate();
		exit(-1);
	}

	glfwMakeContextCurrent(mWindow);
}

void Game::imguiInitializationAndConfiguration()
{
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
	// application loop
	while (!glfwWindowShouldClose(mWindow))
	{
		glfwPollEvents();
		processInput();

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
	ImGui::Text("OOP OpenGL");
}

void Game::shutdown()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();
}

void Game::processInput()
{
	if (glfwGetKey(mWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(mWindow, true);
	}
}

