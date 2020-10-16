#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList<int> l;
    int numbers[] = {3, -2, 5, 12, -2, -4, 5};
    int size = 7;
    l.add(numbers[0], "hi"); l.add(numbers[1], "this");
    l.add(numbers[2], "is"); l.add(numbers[3], "my");
    l.add(numbers[4], "first"); l.add(numbers[5], "Lab 5");
    l.add(numbers[6], "test!");

    for (int i =0; i < size; i++)
        cout << numbers[i] << " ";
    cout << endl << l.getLastNegative() << endl << endl;

    LinkedList<double> d;
    double doubles[] = {-3.2, 2.14, -5.7, -12.01, -2.99, 4.6, 5.2};
    int size2 = 7;
    d.add(doubles[0], "hi"); d.add(doubles[1], "this");
    d.add(doubles[2], "is"); d.add(doubles[3], "my");
    d.add(doubles[4], "first"); d.add(doubles[5], "Lab 5");
    d.add(doubles[6], "test!");

    for (int i =0; i < size2; i++)
        cout << doubles[i] << " ";
    cout << endl << d.getLastNegative() << endl << endl;


    return 0;
}
