#include <iostream>
using namespace std;

struct listNode
{
	int  info;
	listNode *next;
};

void displayReverse(listNode* list)
{
	if (list == NULL) 	return;
	if (list != NULL)	displayReverse(list->next);
	cout << list->info << "  "; 
}	

int main()
{   
	listNode  *stack, *queue, *list;
	int a[7] = { 10, 8, 6, 9, 2,4,1 };
    cout << displayReverse(list);
}
