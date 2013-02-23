#ifndef MFE_CORE_ENGINECORE_H_
#define MFE_CORE_ENGINECORE_H_

#include "../events/event.h"
#include "ienginecore.h"

namespace mfe
{

/**
 * \brief The E_ENGINE_INIT_FLAGS enum
 */
enum E_ENGINE_INIT_FLAGS
{
    EIF_DEFAULT         = 0x00000000,   /**< Load engine with default settings. */
    EIF_FULL_SCREEN     = 0x00000001,   /**< Load MainWindow in fullscreen mode. */
    EIF_NO_LOGGING      = 0x00000002    /**< Logging will be turned off. */
};

class EngineCore : public IEngineCore
{
public:

    EngineCore();
    virtual ~EngineCore();

    Event&                      get_initialize_event() { return initialize_event_; }
    Event&                      get_destroy_event() { return destroy_event_; }
    Event&                      get_main_loop_event() { return main_loop_event_; }
    Event&                      get_render_event() { return render_event_; }
    Event&                      get_message_proc_event() { return message_proc_event_; }

    int                         Initialize(const int window_x, const int window_y, const char *window_name, mfe::E_ENGINE_INIT_FLAGS init_flags);
    int                         Destroy();

private:

    void                        MainLoop();
    void                        Render();
    void                        MessageProc();

    bool                        main_loop_exit_;

    Event                       initialize_event_;
    Event                       destroy_event_;
    Event                       main_loop_event_;
    Event                       render_event_;
    Event                       message_proc_event_;

}; // class EngineCore

} // namespace mfe

#endif // MFE_CORE_ENGINECORE_H_
