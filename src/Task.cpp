//
// Created by Jordan Winemiller on 7/21/23.
//
#include "Task.h"
using namespace std;

Task::Task(string taskName, char category, int priority) {
    this->taskName = taskName;
    this->categoryType = category;
    this->taskPriority = priority;
    this->isComplete = false;
}

Task::~Task() {}

void Task::SetStatus() {
    this->isComplete = true;
}

string Task::GetTaskName() const { return this->taskName; }

string Task::GetTaskCategory() const {
    if (this->categoryType == 'a') {
        return "Activity";
    }
    else if (this->categoryType == 'g') {
        return "Grocery";
    }
    else if (this->categoryType == 'h') {
        return "Household";
    }
    else {
        return "Other";
    }
}

int Task::GetTaskPriority() const { return this->taskPriority; }

string Task::GetTaskStatus() const {
    if (this->isComplete) {
        return "complete";
    }
    else {
        return "not complete";
    }
}

// -----------------------------------------------------------------------------
// Task.h file
// -----------------------------------------------------------------------------
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
// -----------------------------------------------------------------------------