//
// Created by Jordan Winemiller on 7/22/23.
//
// Program: To-do task list that is driven by a menu taking in commands for the
// terminal. An example is at the bottom of the file.
//
#include "Menu.h"
#include <iostream>
using namespace std;

int main() {
    Menu menu;
    char menuCmd = 'x';
    char quitCmd = 'x';

    while (quitCmd != 'y') {
        try {
            cout << "Please review the menu options." << endl;
            cout << "(a) for adding a tasks, ";
            cout << "(v) for viewing tasks, ";
            cout << "(r) for removing tasks, ";
            cout << "(c) to complete a task, ";
            cout << "or (e) for exiting the program." << endl;
            cout << "Please enter a menu option: ";
            cin >> menuCmd;

            if ((menuCmd != 'a') && (menuCmd != 'v') && (menuCmd != 'r')
                && (menuCmd != 'e') && (menuCmd != 'c')) {
                throw invalid_argument("Please enter a valid option.");
            }
            else if (menuCmd == 'a') {
                menu.SetTask();
            }
            else if (menuCmd == 'v') {
                menu.PrintTaskList();
            }
            else if (menuCmd == 'c') {
                menu.UpdateTaskStatus();
            }
            else if (menuCmd == 'r') {
                menu.RemoveTask();
            }
            else if (menuCmd == 'e') {
                cout << "There are " << menu.GetAvailableTasks()
                    << " available tasks." << endl;
                cout << "Are you sure you want to exit (y) for Yes: ";
                cin >> quitCmd;
            }
        }
        catch (invalid_argument menuError) {
            cout << "Invalid argument - " << menuError.what() << endl;
        }
    }

    return 0;
}

/* Code Run
Please review the menu options.
(a) for adding a tasks, (v) for viewing tasks, (r) for removing tasks, (c) to complete a task, or (e) for exiting the program.
Please enter a menu option: v
Your task list is currently empty
Please review the menu options.
(a) for adding a tasks, (v) for viewing tasks, (r) for removing tasks, (c) to complete a task, or (e) for exiting the program.
Please enter a menu option: r
Your task list is currently empty
Please review the menu options.
(a) for adding a tasks, (v) for viewing tasks, (r) for removing tasks, (c) to complete a task, or (e) for exiting the program.
Please enter a menu option: c
Your task list is currently empty
Please review the menu options.
(a) for adding a tasks, (v) for viewing tasks, (r) for removing tasks, (c) to complete a task, or (e) for exiting the program.
Please enter a menu option: o
Invalid argument - Please enter a valid option.
Please review the menu options.
(a) for adding a tasks, (v) for viewing tasks, (r) for removing tasks, (c) to complete a task, or (e) for exiting the program.
Please enter a menu option: a
(a) Activity, (g) Grocery, (h) Household, or (any other key not f) for other.
Please enter a category for your TO-DO list: a
Now enter the task: Programming Project
Enter the task priority (1-5): 5
(a) Activity, (g) Grocery, (h) Household, (any other key not f) for other or (f) for finished.
Please enter another category for your TO-DO list: a
Now enter the task: Rugby Practice
Enter the task priority (1-5): 4
(a) Activity, (g) Grocery, (h) Household, (any other key not f) for other or (f) for finished.
Please enter another category for your TO-DO list: g
Now enter the task: Buy chicken
Enter the task priority (1-5): 1
(a) Activity, (g) Grocery, (h) Household, (any other key not f) for other or (f) for finished.
Please enter another category for your TO-DO list: g
Now enter the task: Buy salad
Enter the task priority (1-5): 3
(a) Activity, (g) Grocery, (h) Household, (any other key not f) for other or (f) for finished.
Please enter another category for your TO-DO list: h
Now enter the task: Buy Dish Soap
Enter the task priority (1-5): 3
(a) Activity, (g) Grocery, (h) Household, (any other key not f) for other or (f) for finished.
Please enter another category for your TO-DO list: f
Please review the menu options.
(a) for adding a tasks, (v) for viewing tasks, (r) for removing tasks, (c) to complete a task, or (e) for exiting the program.
Please enter a menu option: c
Please enter the task name that you want to update: Rugby Practice
Your task is now complete.
Please review the menu options.
(a) for adding a tasks, (v) for viewing tasks, (r) for removing tasks, (c) to complete a task, or (e) for exiting the program.
Please enter a menu option: v
1. Programming Project - Priority: 5 in the Activity category, and is current not complete.
2. Rugby Practice - Priority: 4 in the Activity category, and is current complete.
3. Buy chicken - Priority: 1 in the Grocery category, and is current not complete.
4. Buy salad - Priority: 3 in the Grocery category, and is current not complete.
5. Buy Dish Soap - Priority: 3 in the Household category, and is current not complete.
Please review the menu options.
(a) for adding a tasks, (v) for viewing tasks, (r) for removing tasks, (c) to complete a task, or (e) for exiting the program.
Please enter a menu option: r
Please enter the task name that you want to remove: Buy chicken
Your task has been removed.
Please review the menu options.
(a) for adding a tasks, (v) for viewing tasks, (r) for removing tasks, (c) to complete a task, or (e) for exiting the program.
Please enter a menu option: v
1. Programming Project - Priority: 5 in the Activity category, and is current not complete.
2. Rugby Practice - Priority: 4 in the Activity category, and is current complete.
3. Buy salad - Priority: 3 in the Grocery category, and is current not complete.
4. Buy Dish Soap - Priority: 3 in the Household category, and is current not complete.
Please review the menu options.
(a) for adding a tasks, (v) for viewing tasks, (r) for removing tasks, (c) to complete a task, or (e) for exiting the program.
Please enter a menu option: r
Please enter the task name that you want to remove: Buy salad
Your task has been removed.
Please review the menu options.
(a) for adding a tasks, (v) for viewing tasks, (r) for removing tasks, (c) to complete a task, or (e) for exiting the program.
Please enter a menu option: e
There are 3 available tasks.
Are you sure you want to exit (y) for Yes: n
Please review the menu options.
(a) for adding a tasks, (v) for viewing tasks, (r) for removing tasks, (c) to complete a task, or (e) for exiting the program.
Please enter a menu option: v
1. Programming Project - Priority: 5 in the Activity category, and is current not complete.
2. Rugby Practice - Priority: 4 in the Activity category, and is current complete.
3. Buy Dish Soap - Priority: 3 in the Household category, and is current not complete.
Please review the menu options.
(a) for adding a tasks, (v) for viewing tasks, (r) for removing tasks, (c) to complete a task, or (e) for exiting the program.
Please enter a menu option: a
(a) Activity, (g) Grocery, (h) Household, or (any other key not f) for other.
Please enter a category for your TO-DO list: a
Now enter the task: Bike ride
Enter the task priority (1-5): 9
Logic error - task priority needs to be between 1 and 5.
Enter the task priority (1-5): 3
(a) Activity, (g) Grocery, (h) Household, (any other key not f) for other or (f) for finished.
Please enter another category for your TO-DO list: f
Please review the menu options.
(a) for adding a tasks, (v) for viewing tasks, (r) for removing tasks, (c) to complete a task, or (e) for exiting the program.
Please enter a menu option: v
1. Programming Project - Priority: 5 in the Activity category, and is current not complete.
2. Rugby Practice - Priority: 4 in the Activity category, and is current complete.
3. Buy Dish Soap - Priority: 3 in the Household category, and is current not complete.
4. Bike ride - Priority: 3 in the Activity category, and is current not complete.
Please review the menu options.
(a) for adding a tasks, (v) for viewing tasks, (r) for removing tasks, (c) to complete a task, or (e) for exiting the program.
Please enter a menu option: c
Please enter the task name that you want to update: Buy Dish Soap
Your task is now complete.
Please review the menu options.
(a) for adding a tasks, (v) for viewing tasks, (r) for removing tasks, (c) to complete a task, or (e) for exiting the program.
Please enter a menu option: v
1. Programming Project - Priority: 5 in the Activity category, and is current not complete.
2. Rugby Practice - Priority: 4 in the Activity category, and is current complete.
3. Buy Dish Soap - Priority: 3 in the Household category, and is current complete.
4. Bike ride - Priority: 3 in the Activity category, and is current not complete.
Please review the menu options.
(a) for adding a tasks, (v) for viewing tasks, (r) for removing tasks, (c) to complete a task, or (e) for exiting the program.
Please enter a menu option: c
Please enter the task name that you want to update: Bike ride
Your task is now complete.
Please review the menu options.
(a) for adding a tasks, (v) for viewing tasks, (r) for removing tasks, (c) to complete a task, or (e) for exiting the program.
Please enter a menu option: r
Please enter the task name that you want to remove: Buy Dish Soad
Your task was not found.
Please review the menu options.
(a) for adding a tasks, (v) for viewing tasks, (r) for removing tasks, (c) to complete a task, or (e) for exiting the program.
Please enter a menu option: r
Please enter the task name that you want to remove: Buy Dish Soap
Your task has been removed.
Please review the menu options.
(a) for adding a tasks, (v) for viewing tasks, (r) for removing tasks, (c) to complete a task, or (e) for exiting the program.
Please enter a menu option: v
1. Programming Project - Priority: 5 in the Activity category, and is current not complete.
2. Rugby Practice - Priority: 4 in the Activity category, and is current complete.
3. Bike ride - Priority: 3 in the Activity category, and is current complete.
Please review the menu options.
(a) for adding a tasks, (v) for viewing tasks, (r) for removing tasks, (c) to complete a task, or (e) for exiting the program.
Please enter a menu option: c
Please enter the task name that you want to update: Programming Project
Your task is now complete.
Please review the menu options.
(a) for adding a tasks, (v) for viewing tasks, (r) for removing tasks, (c) to complete a task, or (e) for exiting the program.
Please enter a menu option: e
There are 3 available tasks.
Are you sure you want to exit (y) for Yes: n
Please review the menu options.
(a) for adding a tasks, (v) for viewing tasks, (r) for removing tasks, (c) to complete a task, or (e) for exiting the program.
Please enter a menu option: r
Please enter the task name that you want to remove: Bike ride
Your task has been removed.
Please review the menu options.
(a) for adding a tasks, (v) for viewing tasks, (r) for removing tasks, (c) to complete a task, or (e) for exiting the program.
Please enter a menu option: e
There are 2 available tasks.
Are you sure you want to exit (y) for Yes: y
*/

// ----------------------------------------------------------------------------
// Menu.h file
// ----------------------------------------------------------------------------
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
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// Menu.cpp file
// ----------------------------------------------------------------------------
// #include "Menu.h"
// using namespace std;
//
// Menu::Menu() {
//     availableTasks = false;
// }
//
// Menu::~Menu() {}
//
// void Menu::SetTask() {
//     string taskName;
//     string tempStr;
//     char category;
//     int priority;
//
//     cout << "(a) Activity, (g) Grocery, (h) Household,"
//          << " or (any other key not f) for other." << endl;
//     cout << "Please enter a category for your TO-DO list: ";
//     cin >> category;
//
//     getline(cin, taskName);
//     cout << "Now enter the task: ";
//     getline(cin, taskName);
//
//     while (category != 'f') {
//         try {
//             cout << "Enter the task priority (1-5): ";
//             cin >> priority;
//
//             if (cin.fail()) {
//                 cin.clear();
//                 throw invalid_argument("enter an integer between 1 and 5.");
//
//             }
//             else if ((priority < 1) || (priority > 5)) {
//                 throw logic_error("task priority needs to be between 1 and 5.");
//             }
//             Task taskItem = Task(taskName, category, priority);
//             taskList.push_back(taskItem);
//             Menu::SetAvailableTasks();
//
//             cout << "(a) Activity, (g) Grocery, (h) Household,"
//                  << " (any other key not f) for other"
//                  << " or (f) for finished." << endl;
//             cout << "Please enter another category for your TO-DO list: ";
//             cin >> category;
//             if (category == 'f') {
//                 break;
//             }
//
//             getline(cin, tempStr);
//             cout << "Now enter the task: ";
//             getline(cin, taskName);
//         }
//         catch (invalid_argument setError1) {
//             cout << "Invalid error - " << setError1.what() << endl;
//             break;
//         }
//         catch (logic_error setError2) {
//             cout << "Logic error - " << setError2.what() << endl;
//         }
//     }
// }
//
// void Menu::SetAvailableTasks() {
//     this->availableTasks = taskList.size() > 0;
// }
//
// int Menu::GetAvailableTasks() const {
//     return taskList.size();
// }
//
// void Menu::PrintTaskList() {
//     if (!availableTasks) {
//         cout << "Your task list is currently empty" << endl;
//     }
//     else {
//         for (int i = 0; i < taskList.size(); i++) {
//             cout << i + 1 << ". " << taskList.at(i).GetTaskName()
//                  << " - Priority: " << taskList.at(i).GetTaskPriority()
//                  << " in the " << taskList.at(i).GetTaskCategory()
//                  << " category, and is current "
//                  << taskList.at(i).GetTaskStatus() << "."
//                  << endl;
//         }
//     }
// }
//
// void Menu::RemoveTask() {
//     bool found = false;
//     if (!availableTasks) {
//         cout << "Your task list is currently empty" << endl;
//     }
//     else {
//         string removeTask;
//         string tempStr;
//         cout << "Please enter the task name that you want to remove: ";
//         getline(cin, tempStr);
//         getline(cin, removeTask);
//         for (int i = 0; i < taskList.size(); i++) {
//             if (removeTask == taskList.at(i).GetTaskName()) {
//                 found = true;
//                 taskList.erase(taskList.begin() + i);
//                 Menu::SetAvailableTasks();
//                 cout << "Your task has been removed." << endl;
//             }
//         }
//
//         if (!found) {
//             cout << "Your task was not found." << endl;
//         }
//     }
// }
//
// void Menu::UpdateTaskStatus() {
//     string updateTask;
//     string tempStr;
//     bool found = false;
//
//     if (!availableTasks) {
//         cout << "Your task list is currently empty" << endl;
//     }
//     else {
//         cout << "Please enter the task name that you want to update: ";
//         getline(cin, tempStr);
//         getline(cin, updateTask);
//
//         for (int i = 0; i < taskList.size(); i++) {
//             if (updateTask == taskList.at(i).GetTaskName()) {
//                 found = true;
//                 taskList.at(i).SetStatus();
//                 cout << "Your task is now complete." << endl;
//             }
//         }
//
//         if (!found) {
//             cout << "Your task was not found." << endl;
//         }
//     }
// }
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// Task.h file
// ----------------------------------------------------------------------------
// #ifndef TASK_LIST_TASK_H
// #define TASK_LIST_TASK_H
//
// #include <string>
//
// class Task {
// public:
//     Task(std::string taskName, char category, int priority);
//     ~Task();
//     void SetStatus();
//     std::string GetTaskName () const;
//     std::string GetTaskCategory () const;
//     int GetTaskPriority () const;
//     std::string GetTaskStatus () const;
// private:
//     std::string taskName;
//     char categoryType;
//     int taskPriority;
//     bool isComplete;
// };
//
// #endif //TASK_LIST_TASK_H
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// Task.cpp file
// ----------------------------------------------------------------------------
// #include "Task.h"
// using namespace std;
//
// Task::Task(string taskName, char category, int priority) {
//     this->taskName = taskName;
//     this->categoryType = category;
//     this->taskPriority = priority;
//     this->isComplete = false;
// }
//
// Task::~Task() {}
//
// void Task::SetStatus() {
//     this->isComplete = true;
// }
//
// string Task::GetTaskName() const { return this->taskName; }
//
// string Task::GetTaskCategory() const {
//     if (this->categoryType == 'a') {
//         return "Activity";
//     }
//     else if (this->categoryType == 'g') {
//         return "Grocery";
//     }
//     else if (this->categoryType == 'h') {
//         return "Household";
//     }
//     else {
//         return "Other";
//     }
// }
//
// int Task::GetTaskPriority() const { return this->taskPriority; }
//
// string Task::GetTaskStatus() const {
//     if (this->isComplete) {
//         return "complete";
//     }
//     else {
//         return "not complete";
//     }
// }
// ----------------------------------------------------------------------------
