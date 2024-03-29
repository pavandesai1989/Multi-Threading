In this video we will learn about std::mutex::try_lock() On Mutex In C++11 Threading.
Few points to remember about the try_lock is as follows:
0. try_lock() Tries to lock the mutex. Returns immediately. On successful lock acquisition returns true otherwise returns false.
1. If try_lock() is not able to lock mutex, then it doesn't get blocked that's why it is called non-blocking.
2. If try_lock is called again by the same thread which owns the mutex, the behaviour is undefined.
   It is a dead lock situation with undefined behaviour. (if you want to be able to lock the same mutex by same thread more than one time the go for recursive_mutex)

There are so many try_lock function
1. std::try_lock
2. std::mutex::try_lock
3. std::shared_lock::try_lock
4. std::timed_mutex::try_lock
5. std::unique_lock::try_lock
6. std::shared_mutex::try_lock
7. std::recursive_mutex::try_lock
8. std::shared_timed_mutex::try_lock
9. std::recursive_timed_mutex::try_lock

Now what is the difference between “lock()” that we saw in previous chapter and “try_lock()”?
when 2nd thread calls “lock()” function, and if the “lock()” is acquired by previous thread, the second thread will be blocked till the first thread 
unlocks the resource. This is a blocking call.

But with “try_lock()”, if the 2nd thread tries to acquire lock, but the lock has been already acquired by other thread, the 2nd thread will return 
  immediately. Thus it is a non blocking call.
  
  
  
  
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

int count = 0;

std::mutex mu;
void incrementCount()
{
    if (mu.try_lock()) // try_lock()
    {
   		count++;//critial section
   		cout<<count<<endl;
   
   		mu.unlock();
   	}
}

int main(void)
{
    std::thread t1(incrementCount);
    std::thread t2(incrementCount);
    std::thread t3(incrementCount);

    t1.join();
    t2.join();
    t3.join();
    
    
    return 0;
}
