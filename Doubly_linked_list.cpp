#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* prev;
    struct node* next;
};

int main()
{
    node* head_node = new node();
    head_node -> data = 1;
    head_node -> prev = NULL;

    node* tail_node = new node();
    tail_node -> data = 2;
    tail_node -> prev = 

    return 0;
}