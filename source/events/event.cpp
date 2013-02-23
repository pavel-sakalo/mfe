#include "event.h"
#include <algorithm>

mfe::Event::Event()
{
}

mfe::Event::~Event()
{
}

void mfe::Event::Subscribe(mfe::EventDelegate eventDelegate)
{
    delegates_.push_back(eventDelegate);
}

void mfe::Event::UnSubscribe(mfe::EventDelegate eventDelegate)
{
    delegates_.erase(std::remove(delegates_.begin(), delegates_.end(), eventDelegate), delegates_.end());
}

void mfe::Event::InvokeAll(void *arg)
{
    for (std::vector<mfe::EventDelegate>::iterator i = delegates_.begin(); i < delegates_.end(); i++)
    {
        (*i)(arg);
    }
}

mfe::Event &mfe::Event::operator +=(const mfe::EventDelegate eventDelegate)
{
    Subscribe(eventDelegate);
}

mfe::Event &mfe::Event::operator -=(const mfe::EventDelegate eventDelegate)
{
    UnSubscribe(eventDelegate);
}
