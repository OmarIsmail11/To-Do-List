#include "Task.h"
#include <iostream>
#include <string>
using namespace std;

void AddTask(Task ToDoList[], int &Count)
{
    string TaskName;
    cout << "Please enter task name : ";
    cin >> TaskName;
    ToDoList[Count].SetName(TaskName);
    Count++;
    cout << "Task added successfully !\n";
}

void ViewTasks(Task ToDoList[], int count)
{
    cout << "Your To-Do List:\n";
    cout << "Task Name" << "\t" << "Status\n";
    for (int i=0; i < count; i++)
    {
        cout << ToDoList[i].GetName() << "\t\t";
        if (ToDoList[i].GetStatus())
        {
            cout << "Completed\n";
        }
        else
        {
            cout << "Pending\n";
        }
    }
}

void DeleteTask(Task ToDoList[], string Name, int &Count)
{
    for (int i=0; i<Count; i++)
    {
        if (ToDoList[i].GetName() == Name)
        {
            ToDoList[i] = ToDoList[Count-1];
            Count--;
            break;
        }
    }
}

void MarkAsCompleted(Task ToDoList[], string Name, int &Count)
{
    for (int i=0; i<Count; i++)
    {
        if (ToDoList[i].GetName() == Name)
        {
            ToDoList[i].SetStatus(1);
            break;
        }
    }
}
void DisplayMenu()
{
    cout << "Welcome to your To-Do List.\n";
    cout << "Press 1 : Add new task to list.\n";
    cout << "Press 2 : Delete a task from list.\n";
    cout << "Press 3 : Mark a task as completed\n";
    cout << "Press 4 : Display To-Do List.\n";
    
}
int main()
{
    Task* ToDoList = new Task[20];
    int Count = 0;
    int Choice;
    char Exit;
    string NameToDelete;
    string NameToMarkAsCompleted;
    while (Exit != 'N')
    {
        DisplayMenu();
        cout << "Please enter your choice : ";
        cin >> Choice;
        while (Choice < 0 || Choice > 4)
        {
            cout << "Invalid Choice ! Please re-enter your choice : ";
            cin >> Choice;
        }
        switch (Choice)
        {
            case 1 :
                AddTask(ToDoList,Count);
                ViewTasks(ToDoList,Count);
                break;
            case 2 :
                cout << "Please enter name of task to be deleted : ";
                cin >> NameToDelete;
                DeleteTask(ToDoList,NameToDelete,Count);
                ViewTasks(ToDoList,Count);
                break;
            case 3 : 
                cout << "Please enter name of task to be marked as completed : ";
                cin >> NameToMarkAsCompleted;
                MarkAsCompleted(ToDoList,NameToMarkAsCompleted,Count);
                ViewTasks(ToDoList,Count);
                break;
            case 4 :
                ViewTasks(ToDoList,Count);
                break;
        }
        cout << "Do you want to continue ? (Y/N) : ";
        cin >> Exit;
    }
}