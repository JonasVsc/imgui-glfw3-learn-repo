#pragma once

class Shader {


public:
	Shader();
	void loadShaderFromFile();
	static void linkShader();


private:
	const char* mVertexShaderSource;
	const char* mFragmentShaderSource;
};