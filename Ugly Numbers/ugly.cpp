
// C++ implementation to check
// if a number is an ugly
// number or not
 
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
 

int isUgly(int n)
{
    // Base Cases
    if (n == 1)
        return 1;
    if (n <= 0)
        return 0;

    //has to be divided by 2 3 or 5
    if (n % 2 == 0) {
        return (isUgly(n / 2));
    }
    if (n % 3 == 0) {
        return (isUgly(n / 3));
    }
    if (n % 5 == 0) {
        return (isUgly(n / 5));
    }
 
    return 0;
}
// Driver Code
int main()
{   
    int n;
    cout << "Please enter number: ";
    cin >> n;

    int no = isUgly(n);
    if (no == 1)
        cout << n << " Is a ugly number" << endl;
    else
        cout << n << " Is not a ugly number" << endl;
    return 0;
}
