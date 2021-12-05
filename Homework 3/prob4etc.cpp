// a.	Insert the data in array : string monthName[12]={“Jan”,”Feb”,……,”Dec”};
// Into a BST
// b.	Display the tree using inorder traversal 
// c.	Find and display the height of the tree
// d.	Display all ancestors of “Dec”
// e.	Display are descendants of “DE”
// f.	Delete the leaves of the tree
// g.	Display the tree side way
// h.	How many nodes are in the new tree (write a recursive function)

#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct node
{
	string   info;
	node *left, *right;
};

void insert(node* &p, string x)//-------------------------inserting x in BST
{
	if( p==NULL)
	{
		p = new node; p->info = x;  
		p->left = NULL; p->right = NULL;
	}
	else
	{
		if (x < p->info) insert(p->left, x);
		if (x > p->info) insert(p->right, x);
	}
}

void show(node* p)//----------------------------display BST using inorder traversal
{
	if (p != NULL)
	{
		show(p->left);
		cout << p->info << "  ";
		show(p->right);
	}
}

int height(node* p)//-------------------------------------- return the tree height
{
	if (p == NULL) return -1;  //for tree level return 0
	else return 1 + max(height(p->left), height(p->right));
}

node* find(node* curr, string v) {
        if (curr) {
            if (curr->info == v) return curr;
            if (v < curr->info) return find(curr->left, v); // search left-sub-tree
            if (v > curr->info) return find(curr->right, v); // search right-sub-tree
        }
        return nullptr;
    }

void findDescendants(node* p, string x)//------------------------------------ search for item X
{
    node* curr = find(p, x);
    if (!curr) {
        cout << "could not find element \'" << x << "\'";
    }
    else if (!curr->left && !curr->right) {
        cout << "\'" << x << "\' is a leaf";
    }
    else {
        insert(curr->left, x);
        insert(curr->right, x);
    }

}


bool showAncestor(node* t, string target) //--display the ancestors of node with info target
{
	if (t == NULL) return false;
	if (t->info == target) return true;

	if (showAncestor(t->left, target) ||
		showAncestor(t->right, target) )
	{
		cout << t->info << " ";
		return true;
	}
	else
		return false;
}

node* remLeaves(node* &t)//---------------------remove existing binary tree leaves
{
    if (!t) {
        return nullptr;
    }
    if (!t->left && !t->right) {
        std::cout << t->info << " ";
        free(t);
        return nullptr;
    }

    t->left = remLeaves(t->left);
    t->right = remLeaves(t->right);

    return t;
}

void sideWay(node* t, int s)// ------------------------------- display BST sideway
{
	if (t != NULL)
	{
		sideWay(t->right, s += 5);
		cout << setw(s) << t->info<<endl;
		sideWay(t->left, s);
	}
}

int countNodes(node* t)// ----------------------count number of nodes recursively 
{
	if (t == NULL) return 0;
	else return 1 + countNodes(t->left) + countNodes(t->right);
	//to find total of all nodes replace 1 with t->info
}

//--------------------------------main --------------------------------------------
int main()
{
	node *t = NULL; node *t2=NULL;
	string monthName[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

	//creat tree and display 
	for (int i = 0; i < 12; ++i)
	{
		insert(t, monthName[i]);
	}
    cout << "InOrder Transversal: ";
	show(t); 
    cout << endl;

	//find and display tree hight
	cout << "The tree hight is " << height(t) << endl;

    //ancestor call
    cout << "Ancestors of Dec: " ;
    showAncestor(t, "Dec");
    cout << endl;

    //descendent call
    cout << "Descendents of Dec: " ;
    findDescendants(t, "Dec");
    cout << endl;

    //remove leaves
    cout << "Removing Leaves: ";
    remLeaves(t);
    cout << endl;

	//display tree side-way
	cout << "Tree in sideway direction\n";
	int s = 0;
	sideWay(t, s);

	//fid and display number of nodes in tree
	cout << "No. of nodes=" << countNodes(t) << endl;

	return 0;

}
