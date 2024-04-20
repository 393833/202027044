#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include <iostream>
#include <random>
#include "MsList.h"
#include "Star.hpp"

MSList list;
float moveFactor = 0.0f;
float scaleFactor = 1.0f;

void errorCallback(int error, const char* description)
{
	std::cerr << "\033[1;31mGLFW Error: " << description << "\033[0m" << std::endl;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
	if (key == GLFW_KEY_UP && action == GLFW_PRESS)
	{
		moveFactor += 0.01f;
	}
	if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
	{
		scaleFactor += 0.1f;
	}
}


int initialize()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> disX(-1.0f, 1.0f);
	std::uniform_real_distribution<float> disY(-1.0f, 1.0f);
	std::uniform_real_distribution<float> disColor(0.0f, 1.0f);

	for (int i = 0; i < 300; ++i) {
		float x = disX(gen);
		float y = disY(gen);
		float r = disColor(gen);
		float g = disColor(gen);
		float b = disColor(gen);

		Star* star = new Star(x, y, r, g, b);
		list.push_back(star);
	}

	return 0;
}

int release()
{
	return 0;
}

int update()
{
	return 0;
}

int render()
{
	glClearColor(0.1f, 0.2f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0; i < list.size(); i++) {
		Star* star = dynamic_cast<Star*>(list.at(i));
		if (star) {
			star->render();
		}
	}

	return 0;
}



int main(void)
{
	//glfw라이브러리 초기화
	if (!glfwInit())
		return -1;

	GLFWwindow* window;
	window = glfwCreateWindow(1280, 768, "MuSoeunEngine", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glfwSetErrorCallback(errorCallback);
	glfwSetKeyCallback(window, keyCallback);

	initialize();

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		update();
		render();
		glfwSwapBuffers(window);
	}

	release();

	glfwTerminate();
	return 0;

}