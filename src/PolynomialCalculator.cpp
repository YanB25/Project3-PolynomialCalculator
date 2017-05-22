#include "polynomial.hpp"
#include <iostream>
using namespace std;
int main() {
    polynomial p1(2);
    polynomial p2(5);
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p1 + p2 << endl;
    cout << p2 + p1 << endl;
    cout << p1 - p2 << endl;
    cout << p2 - p1 << endl;
    cout << p1 * 5 << endl;
    cout << p2 * 2.5 << endl;
    cout << (p1 == p2) << endl;
    cout << (p1 == p1) << endl;
    return 0;
}
