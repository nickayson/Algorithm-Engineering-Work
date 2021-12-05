// 1.Write a program to do the following:
// a.	Generate 10 random numbers between 10 and 40 and store them in linked list pointed by ALL. 
// b.	Create an algorithm for making changes to the list ALL such that all even numbers appear at the beginning of the list. Use one of the following hints to write your program
// HINT 1. While traversing ALL, collect even numbers in list EVEN and odd numbers in list ODD. Now to get the final list, simply append the two lists EVEN and ODD
// Sample run:
//   Original list ALL: 20371933243811131924NULL
//   New list ALL     : 24382420371933111319NULL

#include <bits/stdc++.h>
using namespace std;
 
 //single node start
class Node
{
    public:
    int data;
    Node *next;
};
 
 //function to seperate even and odds
void segregateEvenOdd(Node **head_ref)
{
    Node *end = *head_ref;
    Node *prev = NULL;
    Node *curr = *head_ref;
 

    while (end->next != NULL)
        end = end->next;
 
    Node *new_end = end;

    while (curr->data % 2 != 0 && curr != end)
    {
        new_end->next = curr;
        curr = curr->next;
        new_end->next->next = NULL;
        new_end = new_end->next;
    }
 

    if (curr->data%2 == 0)
    {
 
        *head_ref = curr;
 
        while (curr != end)
        {
            if ( (curr->data) % 2 == 0 )
            {
                prev = curr;
                curr = curr->next;
            }
            else
            {

                prev->next = curr->next;
 
            
                curr->next = NULL;
 
                new_end->next = curr;
 
                new_end = curr;
 
                curr = prev->next;
            }
        }
    }
 
    else prev = curr;
 
    if (new_end != end && (end->data) % 2 != 0)
    {
        prev->next = end->next;
        end->next = NULL;
        new_end->next = end;
    }
    return;
}
 
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
 
    new_node->data = new_data;
 
    new_node->next = (*head_ref);
 
    (*head_ref) = new_node;
}
 
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data <<"->";
        node = node->next;
    }
    cout << "NULL" << endl;
}
 
/* Driver code*/
int main()
{
    Node* head = NULL;
    //push random number between 10 and 40
    for (int i = 0; i < 10; ++i) {
        push(&head, rand() % 40 + 10);
    }
 
    cout << "Original Linked list ";
    printList(head);
 
    segregateEvenOdd(&head);
 
    cout << "\nModified Linked list ";
    printList(head);
 
    return 0;
}
 