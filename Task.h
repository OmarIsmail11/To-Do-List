#ifndef TASK_H
#define TASK_H
#pragma once

#include <iostream>
using namespace std;

class Task
{
private:
    string Name;
    bool Status;
public:
    Task();
    Task(string name);
    void SetName(string name);
    void SetStatus(bool status);
    string GetName();
    bool GetStatus();
};
#endif