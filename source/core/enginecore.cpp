#include "enginecore.h"

mfe::EngineCore::EngineCore()
{
}

mfe::EngineCore::~EngineCore()
{
}

int mfe::EngineCore::Initialize(const int window_x, const int window_y, const char *window_name, mfe::E_ENGINE_INIT_FLAGS init_flags)
{
    initialize_event_.InvokeAll(0);

    while (!main_loop_exit_)
    {
        main_loop_event_.InvokeAll(0);
    }
}

int mfe::EngineCore::Destroy()
{
    destroy_event_.InvokeAll(0);

    main_loop_exit_ = false;
}
