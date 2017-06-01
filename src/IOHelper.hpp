#ifndef _FRAME_H_
#define _FRAME_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include "polynomial.hpp"
#include <map>
using std::map;
using std::ostream;
using std::endl;
using std::cout;
using std::cerr;
using std::cin;
using std::string;
using std::pair;
typedef map<string, polynomial> map_t;
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

poly_pair getPolyPair(map_t& map);
polynomial getOnePoly(map_t& map);
bool savePoly(map_t& map, const polynomial& poly);
#endif
