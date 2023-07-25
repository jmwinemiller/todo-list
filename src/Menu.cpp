//
// Created by Jordan Winemiller on 7/23/23.
//
#include "Menu.h"
using namespace std;

Menu::Menu() {
    availableTasks = false;
}

Menu::~Menu() {}

void Menu::SetTask() {
    string taskName;
    string tempStr;
    char category;
    int priority;

    cout << "(a) Activity, (g) Grocery, (h) Household,"
         << " or (any other key not f) for other." << endl;
    cout << "Please enter a category for your TO-DO list: ";
    cin >> category;

    getline(cin, taskName);
    cout << "Now enter the task: ";
    getline(cin, taskName);

    while (category != 'f') {
        try {
            cout << "Enter the task priority (1-5): ";
            cin >> priority;

            if (cin.fail()) {
                cin.clear();
                throw invalid_argument("enter an integer between 1 and 5.");

            }
            else if ((priority < 1) || (priority > 5)) {
                throw logic_error("task priority needs to be between 1 and 5.");
            }
            Task taskItem = Task(taskName, category, priority);
            taskList.push_back(taskItem);
            Menu::SetAvailableTasks();

            cout << "(a) Activity, (g) Grocery, (h) Household,"
                 << " (any other key not f) for other"
                 << " or (f) for finished." << endl;
            cout << "Please enter another category for your TO-DO list: ";
            cin >> category;
            if (category == 'f') {
                break;
            }

            getline(cin, tempStr);
            cout << "Now enter the task: ";
            getline(cin, taskName);
        }
        catch (invalid_argument setError1) {
            cout << "Invalid error - " << setError1.what() << endl;
            break;
        }
        catch (logic_error setError2) {
            cout << "Logic error - " << setError2.what() << endl;
        }
    }
}

void Menu::SetAvailableTasks() {
    this->availableTasks = taskList.size() > 0;
}

int Menu::GetAvailableTasks() const {
    return taskList.size();
}

void Menu::PrintTaskList() {
    if (!availableTasks) {
        cout << "Your task list is currently empty" << endl;
    }
    else {
        for (int i = 0; i < taskList.size(); i++) {
            cout << i + 1 << ". " << taskList.at(i).GetTaskName()
                 << " - Priority: " << taskList.at(i).GetTaskPriority()
                 << " in the " << taskList.at(i).GetTaskCategory()
                 << " category, and is current "
                 << taskList.at(i).GetTaskStatus() << "."
                 << endl;
        }
    }
}

void Menu::RemoveTask() {
    bool found = false;
    if (!availableTasks) {
        cout << "Your task list is currently empty" << endl;
    }
    else {
        string removeTask;
        string tempStr;
        cout << "Please enter the task name that you want to remove: ";
        getline(cin, tempStr);
        getline(cin, removeTask);
        for (int i = 0; i < taskList.size(); i++) {
            if (removeTask == taskList.at(i).GetTaskName()) {
                found = true;
                taskList.erase(taskList.begin() + i);
                Menu::SetAvailableTasks();
                cout << "Your task has been removed." << endl;
            }
        }

        if (!found) {
            cout << "Your task was not found." << endl;
        }
    }
}

void Menu::UpdateTaskStatus() {
    string updateTask;
    string tempStr;
    bool found = false;

    if (!availableTasks) {
        cout << "Your task list is currently empty" << endl;
    }
    else {
        cout << "Please enter the task name that you want to update: ";
        getline(cin, tempStr);
        getline(cin, updateTask);

        for (int i = 0; i < taskList.size(); i++) {
            if (updateTask == taskList.at(i).GetTaskName()) {
                found = true;
                taskList.at(i).SetStatus();
                cout << "Your task is now complete." << endl;
            }
        }

        if (!found) {
            cout << "Your task was not found." << endl;
        }
    }
}

// -----------------------------------------------------------------------------
// Menu.h file
// -----------------------------------------------------------------------------
// #ifndef TODO_LIST_MENU_H
// #define TODO_LIST_MENU_H
//
// #include <iostream>
// #include <stdexcept>
// #include <vector>
// #include "Task.h"
//
// class Menu {
// public:
//     Menu ();
//     ~Menu ();
//     void SetTask();
//     void SetAvailableTasks();
//     int GetAvailableTasks() const;
//     void PrintTaskList();
//     void RemoveTask();
//     void UpdateTaskStatus();
// private:
//     std::vector<Task> taskList;
//     bool availableTasks;
// };
//
// #endif //TODO_LIST_MENU_H
// -----------------------------------------------------------------------------