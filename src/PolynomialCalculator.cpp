/*
by 颜彬
class 7
student's id 16337269
github: YanB25

*/
#include <string>
#include <iostream>
#include <iomanip>
#include <string>
#include <regex>
#include "IOHelper.hpp"
#include <map>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::regex;
using std::map;

typedef string name_t;

const string ORDER_ERROR = "ERROR: Wrong Order";
const string ANSWER_SAVE_MSG = "SUCCESS: input a name to save the answer, or input <Enter> to discard";
int main() {
    map<string, polynomial> poly_map;
    PrintInstroduction();
    string input;
    while (true) {
	PrintPromt(); //print ">>> "
	//when we simply touch "Enter",we creat a new line 
	if (cin.peek() == '\n') {
            cin.get();
            continue;
	}
	getline(cin, input);
	//work
	if (input == "0") {
            return 0;
	}
	
	else if (input == "9") {
            PrintHelp();
	} 
	
        else if (input == "1") {
            auto poly = getOnePoly(poly_map);
            cout << "enter name: " << endl;
            string name;
            getline(cin, name);
            poly_map[name] = poly;
        }

	else if (input == "2") {
            auto pair_poly = getPolyPair(poly_map);
            polynomial sum = pair_poly.first + pair_poly.second;
            cout << ANSWER_SAVE_MSG << endl;
            cout << sum << endl;
            savePoly(poly_map, sum);
	}

        else if (input == "3") {
            auto pair_poly = getPolyPair(poly_map);
            polynomial diff = pair_poly.first - pair_poly.second;
            cout << ANSWER_SAVE_MSG << endl;
            cout << diff << endl;
            savePoly(poly_map, diff);
        }

        else if (input == "4") {
            auto poly = getOnePoly(poly_map);
            cout << "input a num: " << endl;
            PrintPromtForInput();
            double num;
            if (!(cin >> num)) {
                cout << "ERROR: input error" << endl;
                cin.clear();
                while (cin.peek() != '\n') cin.get();
                cin.get();
            } else {
                poly = poly * num;
                cout << ANSWER_SAVE_MSG << endl;
                cout << poly << endl;
                cin.get();
                savePoly(poly_map, poly);
            }
        }

        else if (input == "5") {
            auto poly = getOnePoly(poly_map);
            cout << "input a num: " << endl;
            PrintPromtForInput();
            double num;
            cin >> num;
            if (!cin) {
                cin.clear();
                while (cin.peek() != '\n') cin.get();
            }
            cin.get(); 
            cout << poly.evaluate(num) << endl;
        }

        else if (input == "6") {
            for (const auto& p : poly_map) {
                cout << p.first << " : " << p.second << endl;
            }
        }

        else if (input == "7") {
            auto poly_pair = getPolyPair(poly_map);
            auto mul = poly_pair.first * poly_pair.second;
            cout << ANSWER_SAVE_MSG << endl;
            cout << mul << endl;
            savePoly(poly_map, mul);
        }

        else if (input == "8") {
            auto poly_pair = getPolyPair(poly_map);
            bool equal = poly_pair.first == poly_pair.second;
            cout << (equal ? "Equal" : "NOT Equal") << endl;
        }
        else if (input == "11") {
            auto poly = getOnePoly(poly_map);
            auto d = poly.derivation();
            cout << ANSWER_SAVE_MSG << endl;
            cout << d << endl;
            savePoly(poly_map, d);
        }
        else {
            cout << ORDER_ERROR << endl; 
        }
    }
    return 0;
} 
