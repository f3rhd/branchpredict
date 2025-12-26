#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#pragma once
namespace gui {

    namespace renderer {

        void init(const char* window_name, int32_t width, int32_t height); // creates window and imgui context if window creating was succesful
        GLFWwindow* get_window();
        void cleanup(GLFWwindow* window);
        void render_frame(GLFWwindow* window);
        void new_frame();
        ImVec2 get_window_size();
    }

}