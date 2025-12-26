#include "parser/parser.h"
#include "cpu/cpu.h"

#include "gui/gui_renderer.h"
#include "gui/gui_reg_file.h"

int main(int argc, char** argv) {

    parser_t parser;
    auto cli_info  = parser.parse_cli(argc, argv);

    if (!cli_info.valid)
        return 1;

    CPU cpu(cli_info.predictor);
    cpu.load_program(parser.parse_program(cli_info.input_file));

    gui::reg_file_element_t gui_reg_file(&cpu.get_reg_file());

    gui::renderer::init("BranchPredict", 800, 600);
    GLFWwindow* window = gui::renderer::get_window();

    if (!window)
        return 1;

    while (!glfwWindowShouldClose(window)) {
        gui::renderer::new_frame();
        gui_reg_file.draw();
        if (!cpu.halt())
            cpu.execute();
        gui::renderer::render_frame(window);
    }

    gui::renderer::cleanup(window);
}

