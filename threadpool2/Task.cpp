#include "Task.h"

Task::Task(long z, std::string n) {
	x = z;
	name = n;
}

void Task::run() {
	std::cout << name << " running" << std::endl;
	long r = 0;
	for (int i = 0; i <= x; i++)
		r += i;
}