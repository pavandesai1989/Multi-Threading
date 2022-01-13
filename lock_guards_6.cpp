#include<iostream>
#include<thread>
#include<mutex>

/*
lock and unlock may throw exception. Hence it wont call unlock itself.use lock guards.
*/

using namespace std;

void work(int &count, mutex &mtx)
{
	for (int i = 0; i < 1E6; i++)
	{
		lock_guard<mutex> guard(mtx);
		//unique_lock<mutex> guard(mtx);
		++count;
    }//after this line guard goes out of scope and calls unlock

}

int main()
{
	int count = 0;
	mutex mtx;

	//if u want to pass by value 
	//thread t1(work,count,mtx);
	thread t1(work, ref(count), ref(mtx));
	thread t2(work, ref(count), ref(mtx));

	t1.join();
	t2.join();

	cout << count << endl;
	return 0;

}
