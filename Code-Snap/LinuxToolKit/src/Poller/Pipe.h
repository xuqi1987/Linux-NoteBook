
#ifndef Pipe_h
#define Pipe_h

#include <stdio.h>
#include <functional>
#include "PipeWrap.h"
#include "EventPoller.h"

using namespace std;

namespace toolkit {

class Pipe
{
public:
    Pipe(const function<void(int size,const char *buf)> &onRead=nullptr, const EventPoller::Ptr &poller = nullptr);
    ~Pipe();
    void send(const char *send,int size=0);
private:
	std::shared_ptr<PipeWrap> _pipe;
	EventPoller::Ptr _poller;

};


}  // namespace toolkit


#endif /* Pipe_h */
