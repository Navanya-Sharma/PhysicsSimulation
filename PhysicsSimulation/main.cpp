#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

/*#include "glm/glm.hpp"
#include "stb_image.h"*/



#include <unordered_map>
using namespace std;


#include "Base.h"
#include "SceneManager.h"
//#include "ImGuiClass.h"

// Global Variables
GLFWwindow* window=NULL;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // write the function here that you want to be called when your window is resized
    
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    //glViewport(0, 0, width, height);
}

bool start() {
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw window creation
    // --------------------
    window = glfwCreateWindow(1500, 900, "Physics Simulation", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
    }
    return true;
}


int main() {
    if (!start()) { std::cout << "Glwf is not glad" <<std::endl; }

    SceneManager gSceneManager = *(SceneManager::get());
    gSceneManager.NextScene = Base::get();

    gSceneManager.ImGuiInit(window);

    while (!glfwWindowShouldClose(window))
    {
        
        glClearColor(gSceneManager.color[0], gSceneManager.color[1], gSceneManager.color[2], 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        gSceneManager.CurrentScene->HandleEvents(window);
        gSceneManager.CurrentScene->UpdateImGui();
        gSceneManager.ImGuiUpdate();

        gSceneManager.CurrentScene->Update();
        
        gSceneManager.CurrentScene->Render();

        glfwSwapBuffers(window);
        glfwPollEvents();

        gSceneManager.ChangeScene();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}
