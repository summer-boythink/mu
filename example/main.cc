#include <iostream>
#include <unistd.h>
#include <thread>

#include "EventLoop.h"

using namespace std;

void threadFunc()
{
    cout << "threadFunc(): pid = "<< getpid()<<" tid = "<< this_thread::get_id() << endl;
    EventLoop loop;
    loop.loop();
}

int main(){
    cout << "main(): pid = "<< getpid()<<" tid = "<< this_thread::get_id() << endl;
    EventLoop loop;
    thread t1(threadFunc);
    t1.join();
    loop.loop();
    pthread_exit(NULL);
    return 0;
}