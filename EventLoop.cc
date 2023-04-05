#include <iostream>
#include "EventLoop.h"
#include <cassert>
#include <sys/poll.h>

#include <glog/logging.h>

__thread EventLoop* t_loopInThisThread = nullptr;

EventLoop::EventLoop()
    :looping_(false),
    threadId_(std::this_thread::get_id())
    {
         LOG(INFO) << "EventLoop created" << this << " in thread "<< threadId_;
        if(t_loopInThisThread)
        {
             LOG(ERROR) << "Another EventLoop " << t_loopInThisThread
             << " exists in this thread " << threadId_;
        }else {
            t_loopInThisThread = this;
        }
    }

EventLoop::~EventLoop()
{
    assert(!looping_);
    t_loopInThisThread = nullptr;
}

EventLoop* EventLoop::getEventLoopOfCurrentThread()
{
    return t_loopInThisThread;
}

void EventLoop::abortNotInLoopThread()
{
     LOG(ERROR) << "EventLoop::abortNotInLoopThread - EventLoop " << this
             << " was created in threadId_ = " << threadId_
             << ", current thread id = " <<  std::this_thread::get_id();
}

void EventLoop::loop()
{
    assert(!looping_);
    assertInLoopThread();
    looping_ = true;
     LOG(INFO) << "EventLoop " << this << " start looping";
    ::poll(nullptr,0,5*1000);
     LOG(INFO) << "EventLoop " << this << " stop looping";
    looping_ = false;
}
