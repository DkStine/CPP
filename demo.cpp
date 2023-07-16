#include <iostream>
using namespace std;

// Process structure
struct Process {
    Process *previousProcess;
    Process *nextProcess;
    int id;
};

// Linked list class
class ProcessScheduler {
private:
    Process *head;

public:
    ProcessScheduler() {
        head = nullptr;
    }

    // Add process to the back of the linked list
    void add_process(int processId) {
        Process *newProcess = new Process;
        newProcess->id = processId;
        newProcess->nextProcess = nullptr;

        if (head == nullptr) {
            newProcess->previousProcess = nullptr;
            head = newProcess;
        } else {
            Process *current = head;
            while (current->nextProcess != nullptr) {
                current = current->nextProcess;
            }
            current->nextProcess = newProcess;
            newProcess->previousProcess = current;
        }
    }

    // Delete process with given processId
    void delete_process(int processId) {
        Process *current = head;
        while (current != nullptr) {
            if (current->id == processId) {
                if (current->previousProcess == nullptr) {
                    // Deleting the head process
                    head = current->nextProcess;
                    if (head != nullptr) {
                        head->previousProcess = nullptr;
                    }
                } else {
                    current->previousProcess->nextProcess = current->nextProcess;
                    if (current->nextProcess != nullptr) {
                        current->nextProcess->previousProcess = current->previousProcess;
                    }
                }
                delete current;
                break;
            }
            current = current->nextProcess;
        }
    }

    // Fork process with given processId and add it to the linked list
    void fork(int pid, int newId) {
        Process *current = head;
        while (current != nullptr) {
            if (current->id == pid) {
                Process *newProcess = new Process;
                newProcess->id = newId;
                newProcess->previousProcess = current;
                newProcess->nextProcess = current->nextProcess;

                if (current->nextProcess != nullptr) {
                    current->nextProcess->previousProcess = newProcess;
                }
                current->nextProcess = newProcess;
                break;
            }
            current = current->nextProcess;
        }
    }

    // Print all the process ids in order
    void print_schedule() {
        Process *current = head;
        while (current != nullptr) {
            cout << current->id << " ";
            current = current->nextProcess;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;

    ProcessScheduler scheduler;

    for (int i = 0; i < n; i++) {
        int operation, processId, newId;
        cin >> operation;

        switch (operation) {
            case 0: // add_process
                cin >> processId;
                scheduler.add_process(processId);
                break;
            case 1: // delete_process
                cin >> processId;
                scheduler.delete_process(processId);
                break;
            case 2: // fork
                cin >> processId >> newId;
                scheduler.fork(processId, newId);
                break;
            case 3: // print_schedule
                scheduler.print_schedule();
                break;
        }
    }

    return 0;
}
