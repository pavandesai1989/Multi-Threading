#include<iostream>
#include<thread>
#include<mutex>

/*
lock and unlock may throw exception. Hence it wont call unlock itself.use lock guards.
*/

using namespace std;

class App
{
private:
	int count = 0;
	mutex mtx;

public:
	void operator()()
	{
		for (int i = 0; i < 1E6; i++)
		{
			lock_guard<mutex> guard(mtx);
			//unique_lock<mutex> guard(mtx);
			++count;
		}//after this line guard goes out of scope and calls unlock
	}

	inline int getcount()
	{
		return count;
	}
};


int main()
{
	App ob;
	//make sure u pass ob pass ref 

	//if u want to pass by value 
	//thread t1(work,count,mtx);
	thread t1(ref(ob));
	thread t2(ref(ob));

	t1.join();
	t2.join();

	cout << ob.getcount() << endl;
	return 0;

}
