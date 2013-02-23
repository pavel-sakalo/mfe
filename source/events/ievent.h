#ifndef MFE_EVENTS_IEVENT_H_
#define MFE_EVENTS_IEVENT_H_

namespace mfe
{

typedef int (*EventDelegate)(void *arg);

class IEvent
{
public:
    virtual ~IEvent() {}
    virtual void Subscribe(EventDelegate eventDelegate) = 0;
    virtual void UnSubscribe(EventDelegate eventDelegate) = 0;
    virtual void InvokeAll(void *arg) = 0;
};
}

#endif // MFE_EVENTS_IEVENT_H_
