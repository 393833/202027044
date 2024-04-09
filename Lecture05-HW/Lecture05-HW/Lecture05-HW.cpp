#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include <iostream>

float moveFactor = 0.0f;
float scaleFactor = 1.0f;
double lastX = 0.0;
double lastY = 0.0;
bool leftMousePressed = false;
bool rightMousePressed = false;

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
            leftMousePressed = true;
            glfwGetCursorPos(window, &lastX, &lastY);
        }
        else if (action == GLFW_RELEASE)
        {
            leftMousePressed = false;
        }
    }
    else if (button == GLFW_MOUSE_BUTTON_RIGHT)
    {
        if (action == GLFW_PRESS)
        {
            rightMousePressed = true;
            glfwGetCursorPos(window, &lastX, &lastY);
        }
        else if (action == GLFW_RELEASE)
        {
            rightMousePressed = false;
        }
    }
}

void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
{
    if (leftMousePressed)
    {
        double deltaX = xpos - lastX;
        double deltaY = ypos - lastY;
        moveFactor += static_cast<float>(deltaX) / 100.0f;
        lastX = xpos;
        lastY = ypos;
    }
    if (rightMousePressed)
    {
        double deltaX = xpos - lastX;
        double deltaY = ypos - lastY;
        scaleFactor += static_cast<float>(deltaX) / 100.0f; 
        lastX = xpos;
        lastY = ypos;
    }
}

int render()
{
    glLoadIdentity();
    glTranslatef(moveFactor, 0.0f, 0.0f);
    glScalef(scaleFactor, scaleFactor, 1.0f);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.0f, 0.5f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.2f, -0.3f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.2f, -0.3f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.4f, 0.1f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.3f, -0.7f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.1f, 0.1f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.4f, 0.1f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.1f, 0.1f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.3f, -0.7f);

    glEnd();

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
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetCursorPosCallback(window, cursorPositionCallback);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        render();

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;

}
