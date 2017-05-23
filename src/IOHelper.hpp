#ifndef _FRAME_H_
#define _FRAME_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include "polynomial.hpp"
using std::ostream;
using std::endl;
using std::cout;
using std::cerr;
using std::cin;
using std::string;
using std::pair;
typedef pair<polynomial, polynomial> poly_pair;
//used to print error message
//s means error message
inline void PrintError(const string& s) {
    cerr << s << endl;
}

void PrintHelp();
void PrintInstroduction();
inline void PrintPromt() {
    cout << ">>> " ;
}

inline void PrintPromtForInput() {
    cout << "... ";
}

poly_pair getPolyPair();
polynomial getOnePoly();
#endif
