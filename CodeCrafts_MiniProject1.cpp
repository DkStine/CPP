#include <iostream>
using namespace std;

using ProcessId = int;
// using std::cin, std::cout, std::endl;

struct Process
{
    Process *previousProcess = nullptr;
    Process *nextProcess = nullptr;
    ProcessId id;

    Process(int id) : id(id){};
};

class Scheduler
{
    Process *head = nullptr;

public:
    // adds process with id = pid to the end of the linked list
    void add_process(ProcessId pid)
    {
        Process *new_process = new Process(pid);

        if (head == nullptr)
        {
            head = new_process;
        }
        else
        {
            Process *traverse = head;
            while (traverse->nextProcess != nullptr)
            {
                traverse = traverse->nextProcess;
            }
            traverse->nextProcess = new_process;
            new_process->previousProcess = traverse;
        }
    }

    // deletes process with id == pid
    void delete_process(ProcessId pid)
    {

    }

    // add a process with id == childId after process with id == parentId
    void fork(ProcessId pid, ProcessId newId)
    {
        Process *traverse = head;
        
        while (traverse != nullptr)
        {
            if (traverse->id = pid)
            {
                Process *new_process = new Process(newId);
                new_process->nextProcess = traverse->nextProcess;
                new_process->previousProcess = traverse;

                if (traverse->nextProcess != nullptr)
                {
                    traverse->nextProcess->previousProcess = new_process;
                }
                traverse->nextProcess = new_process;
                break;
            }
            traverse = traverse->nextProcess;
        }
    }

    void print_schedule()
    {
        Process *curr = head;
        while (curr != nullptr)
        {
            cout << curr->id << " ";
            curr = curr->nextProcess;
        }
        cout << endl;
    }
};

enum Operations
{
    ADD_PROCESS,
    DELETE_PROCESS,
    FORK,
    PRINT_SCHEDULE,
};

int main()
{
    Scheduler s;
    int n;
    cin >> n;

    while (n--)
    {
        int operationInput;
        cin >> operationInput;

        Operations opId = static_cast<Operations>(operationInput);

        if (opId == ADD_PROCESS)
        {
            ProcessId newPid;
            cin >> newPid;
            s.add_process(newPid);
        }
        else if (opId == DELETE_PROCESS)
        {
            ProcessId toBeDeletedPid;
            cin >> toBeDeletedPid;
            s.delete_process(toBeDeletedPid);
        }
        else if (opId == FORK)
        {
            ProcessId pidToBeForked;
            ProcessId newPid;
            cin >> pidToBeForked;
            cin >> newPid;
            s.fork(pidToBeForked, newPid);
        }
        else if (opId == PRINT_SCHEDULE)
        {
            s.print_schedule();
        }
    }
}