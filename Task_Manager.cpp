#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;
class Task {

private:
    string name;
    bool completed;

public:

    Task(string taskName) {
        name = taskName;
        completed = false;
    }


    void showTask(int number) {

        cout << number << ". ";

        if (completed) {
            cout << "completed task---> ";
        }
        else {
            cout << "Pending task--->  ";
        }

        cout << name << endl;
    }


    void updateTask(string newName) {
        name = newName;
    }


    void completeTask() {
        completed = true;
    }


    bool isCompleted() {
        return completed;
    }
};



class TaskManager {

private:

    vector<Task> tasks;


public:

    void addTask() {

        string taskName;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nEnter new task: ";
        getline(cin, taskName);


        if (!taskName.empty()) {

            Task newTask(taskName);

            tasks.push_back(newTask);

            cout << "Task added successfully!\n";
        }
        else {

            cout << "Task cannot be empty.\n";
        }
    }  

    void showTasks() {



        if (tasks.empty()) {

            cout << "No tasks available.\n";

            return;
        }


        for (int i = 0; i < tasks.size(); i++) {

            tasks[i].showTask(i + 1);
        }
    }   
    void updateTask() {

        if (tasks.empty()) {

            cout << "\nNo tasks available to update.\n";

            return;
        }


        showTasks();


        int taskNumber;

        cout << "\nEnter task number to update: ";
        cin >> taskNumber;


        if (taskNumber < 1 || taskNumber > tasks.size()) {

            cout << "Invalid task number.\n";

            return;
        }


        cin.ignore(numeric_limits<streamsize>::max(), '\n');


        string newName;

        cout << "Enter new task name: ";
        getline(cin, newName);


        if (!newName.empty()) {

            tasks[taskNumber - 1].updateTask(newName);

            cout << "Task updated successfully!\n";
        }
        else {

            cout << "Task name cannot be empty.\n";
        }
    }


    void completeTask() {

        if (tasks.empty()) {

            cout << "\nNo tasks available.\n";

            return;
        }


        showTasks();


        int taskNumber;

        cout << "\nEnter task number to complete: ";
        cin >> taskNumber;


        if (taskNumber >= 1 && taskNumber <= tasks.size()) {

            tasks[taskNumber - 1].completeTask();

            cout << "Task completed successfully!\n";
        }
        else {

            cout << "Invalid task number.\n";
        }
    }

    void showAnalysis() {

        int completedTasks = 0;


        for (int i = 0; i < tasks.size(); i++) {

            if (tasks[i].isCompleted()) {

                completedTasks++;
            }
        }


        int totalTasks = tasks.size();

        int pendingTasks = totalTasks - completedTasks;


        double progress = 0;


        if (totalTasks > 0) {

            progress =
                (completedTasks * 100.0) / totalTasks;
        }


        cout << "\n     15 DAY ANALYSIS       \n";

        cout << "Total Tasks     : "
             << totalTasks << endl;

        cout << "Completed Tasks : "
             << completedTasks << endl;

        cout << "Pending Tasks   : "
             << pendingTasks << endl;

        cout << "Progress        : "
             << progress << "%\n";


        if (progress >= 80) {

            cout << "Excellent progress! Keep it up!\n";
        }
        else if (progress >= 50) {

            cout << "Good progress! You can do even better!\n";
        }
        else {

            cout << "Keep working consistently. You can improve!\n";
        }
    }
};


int main() {

    string name;
    string email_Id;
    string goal;



    cout << "         15 DAY TASK MANAGER    \n";


    cout << "\nEnter your name: ";
    cin >> name;


    cout << "Enter your email id: ";
    cin >> email_Id;


    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    cout << "What is your goal: ";
    getline(cin, goal);
    cout << "\nThat's a great goal! "
         << "Let's achieve it together!\n";

    cout << "Break your goals into small, "
         << "achievable tasks.\n";
    TaskManager manager;
    cout << "Enter your tasks one by one.\n";
    cout << "Type 'done' when you are finished.\n";


    while (true) {

        string taskName;

        cout << "\nEnter task: ";

        getline(cin, taskName);


        if (taskName == "done") {

            break;
        }
        if (!taskName.empty()) {
            cout << "Use option 2 from the menu "
                 << "to add tasks.\n";

            break;
        }
    }

    while (true) {
        cout << "             TASK MANAGER MENU      \n";

        cout << "1. View Tasks\n";
        cout << "2. Add New Task\n";
        cout << "3. Update Task\n";
        cout << "4. Complete Task\n";
        cout << "5. Show 15 Day Analysis\n";
        cout << "6. Exit\n";


        cout << "\nEnter your choice: ";

        int choice;

        cin >> choice;


        switch (choice) {

            case 1:

                manager.showTasks();

                break;


            case 2:

                manager.addTask();

                break;


            case 3:

                manager.updateTask();

                break;


            case 4:

                manager.completeTask();

                break;


            


            case 5:

                manager.showAnalysis();

                break;


            case 6:

                cout << "\nThank you for using "
                     << "15 Day Task Manager!\n";

                cout << "Keep working towards your goal!\n";

                return 0;


            default:

                cout << "\nInvalid choice. "
                     << "Please try again.\n";
        }
    }


    return 0;
}