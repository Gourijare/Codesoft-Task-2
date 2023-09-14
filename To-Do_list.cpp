#include <iostream>
#include <vector>
#include <string>

// Define a structure to represent tasks
struct Task {
    std::string description;
    bool completed;
};

// Function to add a new task to the list
void addTask(std::vector<Task>& taskList, const std::string& description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    taskList.push_back(newTask);
}

// Function to display tasks with their status
void viewTasks(const std::vector<Task>& taskList) {
    std::cout << "Task List:" << std::endl;
    for (size_t i = 0; i < taskList.size(); ++i) {
        std::cout << i + 1 << ". ";
        if (taskList[i].completed) {
            std::cout << "[X] ";
        } else {
            std::cout << "[ ] ";
        }
        std::cout << taskList[i].description << std::endl;
    }
}

// Function to mark a task as completed
void markTaskAsCompleted(std::vector<Task>& taskList, size_t index) {
    if (index >= 1 && index <= taskList.size()) {
        taskList[index - 1].completed = true;
    } else {
        std::cout << "Invalid task index." << std::endl;
    }
}

// Function to remove a task
void removeTask(std::vector<Task>& taskList, size_t index) {
    if (index >= 1 && index <= taskList.size()) {
        taskList.erase(taskList.begin() + index - 1);
    } else {
        std::cout << "Invalid task index." << std::endl;
    }
}

int main() {
    std::vector<Task> taskList;

    while (true) {
        std::cout << "Options:" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Remove Task" << std::endl;
        std::cout << "5. Exit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string description;
                std::cout << "Enter task description: ";
                std::cin.ignore(); // Clear the input buffer
                std::getline(std::cin, description);
                addTask(taskList, description);
                break;
            }
            case 2: {
                viewTasks(taskList);
                break;
            }
            case 3: {
                size_t index;
                std::cout << "Enter the task number to mark as completed: ";
                std::cin >> index;
                markTaskAsCompleted(taskList, index);
                break;
            }
            case 4: {
                size_t index;
                std::cout << "Enter the task number to remove: ";
                std::cin >> index;
                removeTask(taskList, index);
                break;
            }
            case 5: {
                // Exit the program
                return 0;
            }
            default: {
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
            }
        }
    }

    return 0;
}
