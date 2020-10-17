#include <iostream>
#include "LinkedList.h"
using namespace std;

/**
 * Tests LinkedList<int> objects of type integer (must be of type int)
 * @param keys array of integer values for the key - type must be in
 * @param payloads aray of strings for the payloads
 * @param l LinkedList object of type int
 * @param size the size of the key and string arrays
 * @param expect the value to expect as the last negative key - type must
 * be int
 * @return true if the test passed and false otherwise
 */
bool testIntegers(int *keys, string *payloads, LinkedList<int> l, int size,
                  int expect){
    // print
    for (int i =0; i < size; i++) {
        l.add(keys[i], payloads[i]);
        cout << keys[i] << " ";
    }
    cout << endl << "last negative key = " << l.getLastNegative() << " (expect "
    << expect << ")" << endl;
    if (l.getLastNegative() == expect) {
        return true;
    }
    return false;
}

/**
 * Tests LinkedList<double> objects (must be of type double)
 * @param keys array of doubles for the key values
 * @param payloads array of strings for the payload values
 * @param l LinkedList object of type double
 * @param size the size of the double and string arrays
 * @param expect the double value to expect as the last negative key (must be
 * of type double)
 * @return true if the test passed and false otherwise
 */
bool testDoubles(double *keys, string *payloads, LinkedList<double> l, int size,
                  double expect){
    // add and print
    for (int i =0; i < size; i++) {
        l.add(keys[i], payloads[i]);
        cout << keys[i] << " ";
    }
    cout << endl << "last negative key = " << l.getLastNegative() << " (expect "
         << expect << ")" << endl;
    if (l.getLastNegative() == expect) {
        return true;
    }
    return false;
}


/**
 * Main entry point or LinkedList tests
 * @return 0
 */
int main() {
    string payloads[] = {"this", "is", "a", "great", "Lab", "five", "test!"};

    LinkedList<int> l;
    int numbers[] = {3, -2, 5, 12, -2, -4, 5};
    int size = 7;
    int expectInt = -2;
    cout << (testIntegers(numbers, payloads, l, size, expectInt) ? "passed" :
    "failed") << endl << endl;

    LinkedList<double> d;
    double doubles[] = {-3.2, 2.14, -5.7, -12.01, -2.99, 4.6, 5.2};
    int size2 = 7;
    double expectDouble = -3.2;
    cout << (testDoubles(doubles, payloads, d, size2, expectDouble) ? "passed"
    : "failed") << endl << endl;

    LinkedList<double> f;
    double moreDoubles[] = {5.2, 19.1, -51.6, 7.9, -1.1, 15.2,  1.1};
    int size3 = 7;
    double expectDouble2 = -51.6;
    cout << (testDoubles(moreDoubles, payloads, f, size3, expectDouble2) ?
    "passed" : "failed") << endl << endl;

    LinkedList<int> lli;
    int values[] = {19, 18, -10, 12, -3, 80, -17};
    int size4= 7;
    int expectInt2 = -10;
    cout << (testIntegers(values, payloads, lli, size4, expectInt2) ?
    "passed" : "failed") << endl << endl;

    return 0;
}
