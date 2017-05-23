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
    cout << p1.evaluate(2) << endl;
    cout << p2.evaluate(1.3) << endl;
    cout << p1 * p2 << endl;
    cout << (p2 * p1).evaluate(1) << endl;
    cout << polynomial::isValid("p = (1, 3)(4, 5)") << endl;
    cout << polynomial::isValid("p = (1, 4))(3, 4)") << endl;
    cout << polynomial::isValid("ysf = (1, 343)(1,234)(45, 234)") << endl;
    cout << polynomial::isValid("sdf = (1, 4, 3)") << endl;
    return 0;

}
