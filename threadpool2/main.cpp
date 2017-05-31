#include <iostream>
#include "ThreadPool.h"
#include "Task.h"

int main() {

	// scope trick to prevent system("pause") race condition
	{
		ThreadPool mythreadpool;

		ThreadPool mythreadpool2(10);

		ThreadPool mythreadpool3(40);
	} // <-- all 3 pools get cleaned up here, forces join on all threads to prevent race condition

	//Commented these commands for now.
	//ThreadPool mythreadpool(2);
	// I made a change!


	

/*	Task t1(74298, "Task 1");
	Task t2(279870545, "Task 2");
	Task t3(5645, "Task 3");
	Task t4(939484821, "Task 4");

	mythreadpool.insert(t1);
	mythreadpool.insert(t2);
	mythreadpool.insert(t3);
	mythreadpool.insert(t4);

	mythreadpool.exec();
	*/

	// quick and dirty hault and end of program
	system("pause");
	return 0;
}