//
// Created by Jordan Winemiller on 7/21/23.
//
#ifndef TASK_LIST_TASK_H
#define TASK_LIST_TASK_H

#include <string>

class Task {
public:
    Task(std::string taskName, char category, int priority);
    ~Task();
    void SetStatus();
    std::string GetTaskName () const;
    std::string GetTaskCategory () const;
    int GetTaskPriority () const;
    std::string GetTaskStatus () const;
private:
    std::string taskName;
    char categoryType;
    int taskPriority;
    bool isComplete;
};

#endif //TASK_LIST_TASK_H
