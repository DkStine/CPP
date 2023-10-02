#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void insert_at_front(struct node **head, int data)
{
    node *new_node = new node();
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = *head;

    if (*head != NULL)
    {
        (*head)->prev = new_node;
    }

    (*head) = new_node;
}

int main()
{
    node *head = NULL;
    node *tail = NULL;

    for (int i = 1; i <= 4; i++)
    {
        insert_at_front(&head, i);
    }

    while (head != NULL)
    {
        tail = head;
        cout<<head->data<<" ";
        head = head->next;
    }

    cout<<endl;

    while (tail != NULL)
    {
        cout<<tail->data<<" ";
        tail = tail->prev;
    }

    return 0;
}