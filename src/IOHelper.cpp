#include "polynomial.hpp"
#include "IOHelper.hpp"
#include <iostream>
#include <iomanip>
#include <string>
using std::cout;
using std::endl;
using std::ostream;
using std::left;
using std::setw;
using std::string;
using std::cin;

void PrintInstroduction() {
    cout << "\tWelcome to Polynomial Calculator" << endl;
    cout << "\tuse <9> to get tutorial" << endl;
    cout << "\tuse <0> to exit" << endl;
}

void PrintHelp() {
     cout << "\t<1> to input a polynomial"  << endl;
     cout << "\t<2> add two polynomial"  << endl;
     cout << "\t<3> sub one polynomial from another" << endl;
     cout << "\t<4> multiply polynomial by a constant" << endl;
     cout << "\t<5> evaluate" << endl;
     cout << "\t<6> show all store polynomial" << endl;
     cout << endl;
}

poly_pair getPolyPair() {
    polynomial first = getOnePoly();
    polynomial second = getOnePoly();
    poly_pair p(first, second);
    return p;
}

polynomial getOnePoly() {
    string input;
    cout << "input polynomial: " << endl;
    PrintPromtForInput();
    getline(cin, input);
    while (!polynomial::isValid(input)) {
        PrintError("Error: invalid input");
        PrintPromtForInput();
        getline(cin ,input);
    }
    polynomial poly(input);
    cout << poly << endl;
    return poly;
}
