//
// Created by Jordan Winemiller on 7/25/23.
//
#ifndef TODO_LIST_MENU_H
#define TODO_LIST_MENU_H

#include <iostream>
#include <stdexcept>
#include <vector>
#include "Task.h"

class Menu {
public:
    Menu ();
    ~Menu ();
    void SetTask();
    void SetAvailableTasks();
    int GetAvailableTasks() const;
    void PrintTaskList();
    void RemoveTask();
    void UpdateTaskStatus();
private:
    std::vector<Task> taskList;
    bool availableTasks;
};

#endif //TODO_LIST_MENU_H
