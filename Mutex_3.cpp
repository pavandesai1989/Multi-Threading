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
	
	
	How to fix Race Conditions?
To fix this problem we need to use Lock mechanism i.e. each thread need to acquire a lock before modifying or reading the shared data and
	after modifying the data each thread should unlock the Lock.
	
	
	But what if we forgot to unlock the mutex at the end of function. In such scenario, one thread will exit without releasing the lock and 
	other threads will remain in waiting.This kind of scenario can happen in case some exception came after locking the mutex. To avoid such 
	scenarios we should use std::lock_guard.
	

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
