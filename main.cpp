// Horn, Jonathan
// CS211  Section 52B Homework 2
// Equivalent Arrays

#include <iostream>
using namespace std;

// Helper function for testing the shifting function
void arrayToString(int a[]) {
    for (int i = 0; i < 5; i++) {
        cout << a[i] << ", ";
    }
    cout << endl;
}

// shifts pointed array of n length one position to the right
void shiftRight(int arr[], int n) {
    int temp = arr[n - 1];  // last element index is length - 1
//    cout << typeid(temp).name() << endl;
    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
//    arrayToString(arr);
}

bool equivalent(int a[], int b[], int n) {
    // shiftCounter tracks the number of times shifting the array
    // iterator acts as a match counter as well as indexer for the loop
    int iterator = 0, shiftCounter = 0;
    
/*      debug code
    cout << "Before Shifting: " << endl << "Array 1 is: ";
    arrayToString(a);
    cout << "Array 2 is: ";
    arrayToString(b);
*/
    
    // loop as long as we havent shifted n times or found n matches
    while (shiftCounter != (n - 1) && iterator != (n - 1)) {
        if (a[iterator] == b[iterator]) {
            iterator++;
        }
        else {
            shiftRight(b, n);
            shiftCounter++;
            iterator = 0;
        }
    }
    
/*     debug code
    cout << "After shifting: " << endl << "Array 1 is: ";
    arrayToString(a);
    cout << "Array 2 is: ";
    arrayToString(b);
 */
    
    if (iterator == (n - 1)) return true; // iterator will only reach 4 if all 5 elements match
    else return false;
}

int main() {
    cout << boolalpha;
    
    int testArray1[] = {1, 1, 0, 1, 1};
    int testArray2[] = {0, 1, 1, 1, 1};
    cout << equivalent(testArray1, testArray2, 5) << endl;  // true
    
    int testArray3[] = {1, 2, 3, 4, 5};
    int testArray4[] = {3, 4, 5, 1, 2};
    cout << equivalent(testArray3, testArray4, 5) << endl;  // true
    
    int a3[3] = {1, 2, 3};
    int a4[3] = {2, 3, 3};
    cout << equivalent(a3, a4, 3) << endl; // false
    
    return 0;
}
