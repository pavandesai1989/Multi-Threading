#include<iostream>
using namespace std;

/*
 JOIN NOTES
 0. Once a thread is started we wait for this thread to finish by calling join() function on thread object.
 1. Double join will result into program termination.
 2. If needed we should check thread is joinable before joining. ( using joinable() function)


 DETACH NOTES
 0. This is used to detach newly created thread from the parent thread.
 1. Always check before detaching a thread that it is joinable otherwise we may end up double detaching and
    double detach() will result into program termination.
 2. If we have detached thread and main function is returning then the detached thread execution is suspended.

 NOTES:
 Either join() or detach() should be called on thread object, otherwise during thread object�s destructor it will
 terminate the program. Because inside destructor it checks if thread is still joinable? if yes then it terminates the program.
 
 */

/**********************join **********/
#include<thread>
#include<chrono>
void run(int count)
{
    while(count!=0)
    {
        cout<<count<<endl;
        count--;
    }
        
    
    std::this_thread::sleep_for(chrono::seconds(3));
}

int main()
{
    thread t1(run,5);
    cout<<"main"<<endl;
    
    t1.join();//waiting for thread to complete.note that main is back and printed //main
    
    cout<<"after"<<endl; //u can see in the console after some time this prints
    
    return 0;
}

/************Double join will result into program termination.*************/
/*in the above example 
call t1.join at line 44 again.it crashes ******/


/************ If needed we should check thread is joinable before joining.*************/
     
int main()
{
    thread t1(run,5);
    cout<<"main"<<endl;
    
  if(t1.joinable())
        t1.join();//waiting for thread to complete.note that main is back and printed //main
    
    cout<<"after"<<endl; //u can see in the console after some time this prints
    
    return 0;
}

/************ detach**********/
int main()
{
    thread t1(run,5);//request goes to OS to create and then main resumes
    cout<<"main"<<endl;
    t1.detach(); // i dont want to wait for the thread to complete
    cout<<"after"<<endl;
    std::this_thread::sleep_for(chrono::seconds(3));
    
    return 0;
}

//op
main
after
5run 
4run 
3run 
2run 
1run 
thread finished
/**********************double detach() will result into program termination**************/
int main()
{
    thread t1(run,5);//request goes to OS to create and then main resumes
    cout<<"main"<<endl;
    t1.detach(); // i dont want to wait for the thread to complete
    cout<<"after"<<endl;
    std::this_thread::sleep_for(chrono::seconds(3));
    
    t1.detach();  //crash 
    
    return 0;
}

/***** check joinable before detaching*******/
int main()
{
    thread t1(run,5);//request goes to OS to create and then main resumes
    cout<<"main"<<endl;
    t1.detach(); // i dont want to wait for the thread to complete
    cout<<"after"<<endl;
    std::this_thread::sleep_for(chrono::seconds(3));
    
  if(t1.joinable())
    t1.detach();  //crash 
    
    return 0;
}
/**********VVVVVVVVVVIMP Either join() or detach() should be called on thread object***************/

//below code is bad
int main()
{
    thread t1(run,5);//request goes to OS to create and then main resume
    
    return 0;
}
//below code is correct
int main()
{
    thread t1(run,5);//request goes to OS to create and then main resumes
    if(t1.joinable())
      t1.join();
    
    return 0;
}






















