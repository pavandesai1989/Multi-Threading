#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

void work(int &count,mutex &mtx)
{
	for (int i = 0; i < 1E6; i++)
	{
		mtx.lock();//another thread comes here and wait untill unlock called//must happen before data change happens
		++count;
		mtx.unlock();
	}

}

int main()
{
	int count = 0;
	mutex mtx;

	//if u want to pass by value 
	//thread t1(work,count,mtx);
	thread t1(work,ref(count),ref(mtx));
	thread t2(work,ref(count),ref(mtx));

	t1.join();
	t2.join();

	cout << count << endl;
	return 0;

}
