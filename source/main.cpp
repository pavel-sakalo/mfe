#include <iostream>
#include "mfe.h"

int engineInitialize(void* arg)
{
    std::cout << "Initialize" << std::endl;
}

int engineMainLoop(void* arg)
{
    //std::cout << "Main Loop" << std::endl;
}

int main(int argc, char** argv)
{
    mfe::EngineCore core;
    core.get_initialize_event() += engineInitialize;
    core.get_main_loop_event() += engineMainLoop;
    core.Initialize(0, 0, "", mfe::EIF_DEFAULT);

	return 0;
}
