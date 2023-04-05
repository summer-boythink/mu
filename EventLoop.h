#include <thread>

#ifndef EVENTLOOP_H
#define EVENTLOOP_H

class EventLoop
{
private:
    void abortNotInLoopThread();
    bool looping_;
    const std::thread::id threadId_;
public:
    EventLoop();
    ~EventLoop();
    void loop();
    static EventLoop* getEventLoopOfCurrentThread();
    void assertInLoopThread(){
        if(!isInLoopThread()){
            abortNotInLoopThread();
        }
    };
    bool isInLoopThread() const {
        return threadId_ == std::this_thread::get_id();
    }
};

#endif