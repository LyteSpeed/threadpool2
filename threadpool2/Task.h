#pragma once
#include <iostream>
#include <string>
#include <mutex>

class Task {
public:
	Task(long const, std::string const&);

	// Virtual allows child class to override
	// = 0 FORCES child class to override, cannot create instance of a task object
	virtual void run() = 0;

private:
	
	//Made these constant, we will never change them

	std::string const name_;
	
	// unique Id for tasks
	long const task_id_;

};