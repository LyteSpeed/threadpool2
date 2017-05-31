#include "Task.h"

// Best way to init variables :) http://en.cppreference.com/w/cpp/language/initializer_list
Task::Task(long const id, std::string const& name)
	: task_id_(id), name_(name)
{
}
