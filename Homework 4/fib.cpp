#include <iostream>

using namespace std;

size_t s[100] = { 0 };

int cassini(int n) { return (n & 1) ? -1 : 1; }

size_t fib(const int& n) {
	if (s[n]) return s[n];
	if (n <= 2) return s[n] = 1;
	else 
    {
		s[n] = fib(n-1) + fib(n-2);
		return s[n];
	}
}

int main(int argc, char** argv) {

    for(int i = 0; i < 11; i++){
	    cout << fib(i) << "         " << cassini(i) << endl;
    }
    return 0;
}