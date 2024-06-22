#include "Task.h"
#include <iostream>

using namespace std;

int main()
{
    Task Task1;
    Task1.SetName("Omar");
    cout << Task1.GetName();
    return 0;
}