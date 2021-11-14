// C++ Program to find n'th fibonacci Number in
// with O(Log n) arithmetic operations
#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 1000;
 
int f[MAX] = {0};

// If n is even then k = n/2:
// F(n) = [2*F(k-1) + F(k)]*F(k)

// If n is odd then k = (n + 1)/2
// F(n) = F(k)*F(k) + F(k-1)*F(k-1)

// Returns n'th fibonacci number using table f[]
int fib(int n)
{
    // Base cases
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return (f[n] = 1);
 
    if (f[n])
        return f[n];
 
    int k = (n & 1)? (n+1)/2 : n/2;
 
    // Applying above formula 
    f[n] = (n & 1)? (fib(k)*fib(k) + fib(k-1)*fib(k-1))
           : (2*fib(k-1) + fib(k))*fib(k);
 
    return f[n];
}
 
/* Driver program to test above function */
int main()
{
    int n;
    cout << "Please enter the nth fibonacci number you would like to find: ";
    cin >> n;
    printf("%d ", fib(n));
    return 0;
}