#include <iostream>
#include "ThreadPool.h"
#include "Task.h"

int main() {
	ThreadPool mythreadpool;
	//ThreadPool mythreadpool(2);
	// I made a change!
	Task t1(74298, "Task 1");
	Task t2(279870545, "Task 2");
	Task t3(5645, "Task 3");
	Task t4(939484821, "Task 4");

	mythreadpool.insert(t1);
	mythreadpool.insert(t2);
	mythreadpool.insert(t3);
	mythreadpool.insert(t4);

	mythreadpool.exec();

	return 0;
}