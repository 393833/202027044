#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>
#include <iostream>

void errorCallback(int error, const char* description)
{
    std::cerr << "GLFW Error: " << description << std::endl;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT)
    {
        if (action == GLFW_PRESS)
        {
            glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // 빨간색
        }
        else if (action == GLFW_RELEASE)
        {
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // 검정색
        }
    }
    else if (button == GLFW_MOUSE_BUTTON_RIGHT)
    {
        if (action == GLFW_PRESS)
        {
            glClearColor(0.0f, 1.0f, 0.0f, 1.0f); // 녹색
        }
        else if (action == GLFW_RELEASE)
        {
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // 검정색
        }
    }
}

void cursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{
    int leftButtonState = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
    int rightButtonState = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);

    if (rightButtonState == GLFW_PRESS)
    {
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // 파랑색
    }
    else if (leftButtonState == GLFW_PRESS)
    {
        glClearColor(1.0f, 0.0f, 1.0f, 1.0f); // 마젠타색
    }
}

int main(void)
{
    if (!glfwInit())
        return -1;

    GLFWwindow* window;
    window = glfwCreateWindow(1280, 768, "MuSoeunEngine", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetCursorPosCallback(window, cursorPosCallback);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}