#ifndef MFE_EVENTS_EVENT_H_
#define MFE_EVENTS_EVENT_H_

#include "ievent.h"
#include <vector>

namespace mfe
{

class Event : public IEvent
{
public:

    Event();
    virtual ~Event();

    virtual void                    Subscribe(const EventDelegate eventDelegate);
    virtual void                    UnSubscribe(EventDelegate eventDelegate);
    virtual void                    InvokeAll(void *arg);
    Event&                          operator +=(const EventDelegate eventDelegate);
    Event&                          operator -=(const EventDelegate eventDelegate);

private:

    std::vector<EventDelegate>      delegates_;

};

} // namespace mfe

#endif // MFE_EVENTS_EVENT_H_
