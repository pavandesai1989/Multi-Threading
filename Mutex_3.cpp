#include<iostream>
#include<thread>
#include<mutex>

Mutex: Mutual Exclusion

RACE CONDITION:
0. Race condition is a situation where two or more threads/process happens to change a common data at the same time.
1. If there is a race condition then we have to protect it and the protected section is  called critical section/region.
	
	
	What is a Race Condition?
Race condition is a kind of a bug that occurs in multithreaded applications.

When two or more threads perform a set of operations in parallel, that access the same memory location.  Also, one or more thread out of them 
modifies the data in that memory location, then this can lead to an unexpected results some times.
	

MUTEX:
0. Mutex is used to avoid race condition.
1. We use lock() , unlock() on mutex to avoid race condition.
	

#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

int x = 0;
mutex m;

void increment()
{
    m.lock();
    ++x;
    m.unlock();
}

  
int main()
{
    thread t1(increment);
   
    thread t2(increment);
    thread t3(increment);

    t1.join();
    t2.join();
    t3.join();

    cout<<"value is "<<x<<endl;
}
