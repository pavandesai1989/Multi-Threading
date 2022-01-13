#include<iostream>
#include<thread>
using namespace std;

int main()
{
	int count = 1;
	const int ITERATIONS = 1E6;

	thread t1(
		[&count,ITERATIONS]() 
	{
		for (int i = 0; i < ITERATIONS; i++)
			++count;
	});

	thread t2(
		[&count,ITERATIONS]()
	{
		for (int i = 0; i < ITERATIONS; i++)
			++count;
	});

	t1.join();
	t2.join();

	cout << count << endl;

	

	return 0;

}
