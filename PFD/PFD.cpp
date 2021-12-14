// PFD
#include <iostream>

using namespace std;

int main() {
    const int ORDER = 4;
    const int TARGET = 33;
    
    int arr[ORDER];
    int sum = 0;
    
    // initialize talbe
    // inital row of PFD contains [1, 0, 0, ..., 0]
    // all element except the first one is 0
    arr[0] = 1;
    for (int i = 1; i < ORDER; ++i)
        arr[i] = 0;
    
    while (sum < TARGET) {
        // calculate sum of array "arr"
        sum = 0;
        for (int i = 0; i < ORDER; ++i) {
            sum += arr[i];
            cout << arr[i] << " ";
        }
        cout << sum << endl;
        
        // apply distribution rule
        // PFD rules as follow
        // current row of table: [a, b, c, d, ...]  <-------------------------┐
        // next row of table: [a + b, a + c, a + d, ..., a]                   ┃
        // note last element of the next row is the first element of the previous row
        int first_element = arr[0];
        for (int i = 0; i < ORDER - 1; ++i)
            arr[i] = arr[i + 1] + first_element;
        arr[ORDER - 1] = first_element;
    }

    return 0;
}