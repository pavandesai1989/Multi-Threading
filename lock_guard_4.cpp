Few points to remember about the lock_guard is as follows:
0. It is very light weight wrapper for owning mutex on scoped basis.
1. It acquires mutex lock the moment you create the object of lock_guard.
2. It automatically removes the lock while goes out of scope.
3. You can not explicitly unlock the lock_guard.
4. You can not copy lock_guard.
  
  
 ********* Using the mutex *************
 
  #include <iostream>
#include<thread>
#include<mutex>
using namespace std;


int buffer = 0;
mutex m;

void work(const char* thread,int cnt)
{
    m.lock();
    for(int i=0;i<cnt;i++)
    {
        buffer++;
        cout<<"thread is "<<thread<<" "<<buffer<<endl;
    }
    m.unlock();
}
int main() 
{
    thread t1(work,"T0",5);
    thread t2(work,"T1",5);

    t1.join();
    t2.join();

    cout<<buffer<<endl;
}


*********using the lock guard , no need to unlock****
#include <iostream>
#include<thread>
#include<mutex>
using namespace std;


int buffer = 0;
mutex m;

void work(const char* thread,int cnt)
{
   lock_guard<mutex>  lock(m);    // It wraps the mutex inside it’s object and locks the attached mutex in its constructor. When it’s destructor is called it releases the mutex.//IIIIIMP
    for(int i=0;i<cnt;i++)
    {
        buffer++;
        cout<<"thread is "<<thread<<" "<<buffer<<endl;
    }

}
int main() 
{
    thread t1(work,"T0",5);
    thread t2(work,"T1",5);

    t1.join();
    t2.join();

    cout<<buffer<<endl;
}

