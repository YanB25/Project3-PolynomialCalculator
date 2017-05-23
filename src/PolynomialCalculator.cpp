#include <string>
#include "polynomial.hpp"
#include <iostream>
using namespace std;
int main() {
    polynomial p1("p = (3, 2)(5,4)(2,0)");
    polynomial p2("q = (2, 1)(1, 5)(-3, 0)");
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p1.derivation() << endl;
    cout << p2.derivation() << endl;
    cout << p1 - p2 << endl;
    cout << (p1 - p2).evaluate(1) << endl;
    return 0;

}
