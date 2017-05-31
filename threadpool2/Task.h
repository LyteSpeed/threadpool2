#pragma once
#include <iostream>
#include <string>
#include <cstdio>
#include <mutex>

class Task {
public:
	Task(long z, std::string n);
	void run();

private:
	std::string name;
	long x;

friend class ThreadPool;
};