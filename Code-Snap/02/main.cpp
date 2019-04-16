//
//  main.cpp
//  BoostDemo
//
//  Created by xuqi on 2019/2/19.
//  Copyright © 2019 xuqi. All rights reserved.
//

#include <boost/thread/thread.hpp>
#include <iostream>
#include <unistd.h>

using namespace std;

void StartUdhcpc()
{
    cout<< "start"<<endl;
    try {
        boost::this_thread::interruption_point();
        sleep(3);
    }
        catch(const boost::thread_interrupted&) {
            cout<< "thread_interrupted";
        }

    cout<< "end" << endl;
}

int main(int argc, char* argv[])
{
    boost::thread t(&StartUdhcpc);
    if (t.timed_join(boost::posix_time::seconds(2))==false) {
        if (t.joinable())
        {
            t.detach();
            cout << "detach";
        }
        else
        {
            cout << "thread is not joinable";
        }
    } else
    {
        cout << "aaa";
    }
    return 0;
}