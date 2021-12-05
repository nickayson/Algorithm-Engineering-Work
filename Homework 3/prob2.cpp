// Use doubly linked list to determine whether a given phrase is a palindrome or not (ignore the 
//            special characters such as . , ; space , reads the same from both directions)
//       Sample run:
//       Enter a phrase: Top Spot
//            The phrase is a palindrome
//       NOTE your doubly linked list will look like this. To test for palindrome, visit the nodes from left-to-
//       right and at the same time from right-to-left.

#include<bits/stdc++.h>
using namespace std;
 
// Structure of node
struct Node
{
    char data;
    struct Node *next;
    struct Node *prev;
};
 
/* Given a reference (pointer to pointer) to
   the head of a list and an int, inserts a
   new node on the front of the list. */
void push(struct Node** head_ref, char new_data)
{
    struct Node* new_node = new Node;
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if ((*head_ref) !=  NULL)
      (*head_ref)->prev = new_node ;
    (*head_ref)    = new_node;
}
 
// Function to check if list is palindrome or not
bool isPalindrome(struct Node *left)
{
    if (left == NULL)
       return true;
 
    // Find rightmost node
    struct Node *right = left;
    while (right->next != NULL)
        right = right->next;
 
    while (left != right)
    {
        if (left->data != right->data)
            return false;
 
        left = left->next;
        right = right->prev;
    }
 
    return true;
}
 
// Driver program
int main()
{
    string phrase;
    struct Node* head = NULL;
    cout << "Please enter a phrase: ";
    getline(cin, phrase); 
    // gets rid of spaces and any other sppecial characters
    phrase.erase(remove(phrase.begin(), phrase.end(), ' '), phrase.end());
    phrase.erase(remove(phrase.begin(), phrase.end(), '.'), phrase.end());
    phrase.erase(remove(phrase.begin(), phrase.end(), ','), phrase.end());
    //get rid of all upper cases
    for_each(phrase.begin(), phrase.end(), [](char & c){
        c = ::tolower(c);
    });

    int n = phrase.length();
 
    // declaring character array
    char char_array[n + 1];
 
    // copying the contents of the
    // string to char array
    strcpy(char_array, phrase.c_str());

    for (int i = 0; i < n; i++)
        cout << char_array[i] << endl;
        
    for (int i = 0; i < n; i++){
        push(&head, char_array[i]);
    }

    if (isPalindrome(head))
        printf("It is Palindrome");
    else
        printf("Not Palindrome");
 
    return 0;
}