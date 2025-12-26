#pragma once
#include "../aliases.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
namespace gui {

    class reg_file_element_t {
    public:
        reg_file_element_t(const cpu_reg_file_t* reg_file) : _reg_file(reg_file){}
        void draw();
    private:
        const cpu_reg_file_t* _reg_file = nullptr;
    };
}