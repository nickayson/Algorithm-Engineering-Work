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

template <typename T>
struct Node {
	T data;
	Node<T> *left, *right;

	Node() : data(""), left(nullptr), right(nullptr) {}
	Node(const T& d) : data(d), left(nullptr), right(nullptr) {}
};

template <typename T>
class BST {
private:
	Node<T>* root;

public:
    //constructor
	BST() : root(nullptr) {}

    //insert into the tree function
	void insert(Node<T>* &curr, const T& v) {
		if (!curr) curr = new Node<T>(v);
		else {
			if (v < curr->data) insert(curr->left, v);
			if (v > curr->data) insert(curr->right, v);
		}
	}
    //inorder transveral display
	void inOrder(Node<T>* curr) {
		if (curr) {
			inOrder(curr->left);
			cout << curr->data << " ";
			inOrder(curr->right);
		}
	} 

    //main find function for rest of functions to reference
	Node<T>* find(Node<T>* curr, const T& v) {
		if (curr) {
			if (curr->data == v) return curr;
			if (v < curr->data) return find(curr->left, v); // search left-sub-tree
			if (v > curr->data) return find(curr->right, v); // search right-sub-tree
		}
		return nullptr;
	}

    //diplay height of tree
	int heightBT(Node<T>* r) {
		if (r == nullptr) {
            return -1;
        }
		else {
            return 1 + std::max(heightBT(r->left), heightBT(r->right));
        }
	}

    //finding ancestors of Dec
	bool findAncestors(Node<T>* curr, const T& target) {
		if (!curr) {
            return false;
        }
		if (curr->data == target) {
            return true;
        }
		if (findAncestors(curr->left, target) || findAncestors(curr->right, target)) {
			std::cout << curr->data << " ";
			return true;
		}
		return false;
	}

    //finding descendents of dec
    void findDescendants(const T& x) {
		Node<T>* curr = find(root, x);
		if (!curr) {
            cout << "could not find element \'" << x << "\'";
            }
		else if (!curr->left && !curr->right) {
            cout << "\'" << x << "\' is a leaf";
        }
		else {
			inOrder(curr->left);
			inOrder(curr->right);
		}
	}
    //remove leaves
	Node<T>* removeLeaves(struct Node<T>* curr) {
		if (!curr) {
            return nullptr;
        }
		if (!curr->left && !curr->right) {
			std::cout << curr->data << " ";
			free(curr);
			return nullptr;
		}

		curr->left = removeLeaves(curr->left);
		curr->right = removeLeaves(curr->right);

		return curr;
	}
    //rotate and display tree
	void rotate(Node<T>* curr, int s) {
		if (curr) {
			rotate(curr->right, s += 5);
			std::cout << std::setw(s) << curr->data << std::endl;
			rotate(curr->left, s);
		}		
	}
    //count the amount of nodes in tree with recursion
	int countNodes(Node<T>* curr) {
		return (curr ? 1 + countNodes(curr->left) + countNodes(curr->right) : 0); 
	}
    
	void insert(const T& x)		    { insert(root, x);		   }
	void inOrder()                  { inOrder(root);		   }
	int height()		            { return heightBT(root);   }
  	int nodes()			            { return countNodes(root); }
	void removeLeaves()             { removeLeaves(root);	   }
	void rotate()				    { rotate(root, 0);		   }
	void findAncestors(const T& x)  { findAncestors(root, x);  }
	Node<T>* find(const T& x)	    { find(root, x);		   }
};

int main() {
	BST<string> newtree;
	string monthName[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

	for (int i = 0; i < 12; ++i) newtree.insert(monthName[i]);

	cout << "InOrder Traversal: "; 
    newtree.inOrder();
	cout << "\nHeight: " << newtree.height();
	cout << "\nAncestors of 'Dec': "; 
    newtree.findAncestors("Dec");
	cout << "\nDescendants of 'Dec': "; 
    newtree.findDescendants("Dec");
	cout << "\nRemoving Leaves: "; 
    newtree.removeLeaves();
	cout << "\nRotating BST: \n"; 
    newtree.rotate();
	cout << "\nNumber of Nodes: " << newtree.nodes() << endl;

	return 0;
}