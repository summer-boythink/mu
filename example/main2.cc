#include "EventLoop.h"
#include <thread>

EventLoop* g_loop;

void threadFunc(){
    g_loop->loop();
}

int main(){
    EventLoop loop;
    g_loop = &loop;
    std::thread t1(threadFunc);
    t1.join();
}