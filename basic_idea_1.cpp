#include<iostream>
using namespace std;

/*
In every application there is a default thread which is main(), in side this we create other threads
 A thread is also known as lightweight process. Idea is achieve parallelism by dividing a process into multiple threads.
   For example:
   (a) The browser has multiple tabs that can be different threads.
   (b) MS Word must be using multiple threads, one thread to format the text, another thread to process inputs (spell checker)
   (c) Visual Studio code editor would be using threading for auto completing the code. (Intellicence)

WAYS TO CREATE THREADS IN C++11
1. Function Pointers
2. Lambda Functions
3. Functors
4. Member Functions
5. Static Member functions

*/

#include<thread>
#include<chrono>

void work()
{
	for (int i = 0; i < 10; i++)
	{
		this_thread::sleep_for(chrono::milliseconds(500));
		cout << "loop "<< i << endl;
	}
}
int main()
{
	thread t1(work); //run time error//this thread runs code in his own thread and main thread quits. We need to wait till this thread finishes 

	thread t2(work);

	t1.join(); //works fine
	t2.join();

	return 0; 
}
