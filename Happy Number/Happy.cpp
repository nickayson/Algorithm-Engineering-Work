//    C/C++ program to check a number is a Happy
//  number or not
#include <bits/stdc++.h>
using namespace std;
 
// Utility method to return sum of square of
// digit of n
int numSquareSum(int n)
{
    int squareSum = 0;
    int digit1 = n / 10;
    int digit2 = n % 10;
    while (n)
    {
        int digit1 = n % 10;
        int digit2 = n % 10;
        squareSum += digit1 * digit2;
        n /= 10;
    }
    cout << digit1 << "^2 + " << digit2 << "^2 = "<<  squareSum << endl;
    return squareSum;
}
 
// Returns true if n is Happy number
// else returns false.
bool isHappy(int n)
{

    set<int> s;
    s.insert(n);
 
    // Keep replacing n with sum of
    // squares of digits until we either
    // reach 1 or we endup in a cycle
    while (1) {
 
        // Number is Happy if we reach 1
        if (n == 1)
            return true;
 
        // Replace n with sum of squares
        // of digits
        n = numSquareSum(n);
 
        // If n is already visited, a cycle
        // is formed, means not Happy
        if (s.find(n) != s.end())
            return false;
 
        // Mark n as visited
        s.insert(n);
    }
 
    return false;
}
 
//    Driver code to test above methods
int main()
{
    int n; 
    cout << "Type a number: "; // Type a number and press enter
    cin >> n; // Get user input from the keyboard
    if (isHappy(n))
        cout << n << " is a Happy number\n";
    else
        cout << n << " is not a Happy number\n";
}