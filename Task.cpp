#include "Task.h"
#include <iostream>

using namespace std;

Task::Task() : Status(0)
{
    Name = "New Task";
}

Task::Task(string name) : Status(0)
{
    Name = "New Task";
}

void Task::SetName(string name)
{
    Name = name;
}

void Task::SetStatus(bool status)
{
    Status = status;
}

string Task::GetName()
{
    return Name;
}

bool Task::GetStatus()
{
    return Status;
}