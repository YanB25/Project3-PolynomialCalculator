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
using std::smatch;
using std::regex_search;

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
     cout << "\t<7> multiply polynomial by a polynomial" << endl;
     cout << "\t<8> judge whether two polynomial equal" << endl;
     cout << "\t<11> get derivation of a polynomial" << endl;
     cout << endl;
}

poly_pair getPolyPair(map_t& map) {
    polynomial first = getOnePoly(map);
    polynomial second = getOnePoly(map);
    poly_pair p(first, second);
    return p;
}

polynomial getOnePoly(map_t& map) {
    string input;
    cout << "input polynomial: " << endl;
    PrintPromtForInput();
    getline(cin, input);
    while (!polynomial::isValid(input) && map.find(input) == map.end()) {
        PrintError("Error: invalid input or not this name");
        PrintPromtForInput();
        getline(cin ,input);
    }
    if (map.find(input) != map.end()) {
        polynomial poly(map.find(input)->second);
        cout << poly << endl;
        return poly;
    }  else {
        polynomial poly(input);
        cout << poly << endl;
        smatch m;
        if (regex_search(input, m, polynomial::regex_poly_name_)) {
            map[m[0]] = poly;
        }
        return poly;
    }
}

bool savePoly(map_t& map, const polynomial& poly) {
    PrintPromtForInput();
    string input;
    if (cin.peek() == '\n') {
        cin.get();
        return false;
    }
    getline(cin, input);
    if (!regex_match(input, polynomial::regex_poly_name_)) {
        return false;
    }
    map[input] = poly;
    return true;
}
