
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
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::regex;

const string ORDER_ERROR = "ERROR: Wrong Order";
const string ANSWER_SAVE_MSG = "SUCCESS: input a name to save the answer, or input <Enter> to discard";
int main() {
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
	//discard spaces 
        //while (sin.peek() == ' ') sin.get(); 
        //check the syntax 
        //if (!regex_search(input, results, checkValidInput)) {
	//	PrintError(SYNTAX_ERROR);
	//	continue;
	//}
	//
			
	//work
	if (input == "0") {
            return 0;
	}
	
	else if (input == "9") {
            PrintHelp();
	} 
	
        else if (input == "1") {
            //
        }

	else if (input == "2") {
            auto pair_poly = getPolyPair();
            polynomial sum = pair_poly.first + pair_poly.second;
            cout << ANSWER_SAVE_MSG << endl;
            cout << sum << endl;
            //TODO save the  poly
	}

        else if (input == "3") {
            auto pair_poly = getPolyPair();
            polynomial diff = pair_poly.first - pair_poly.second;
            cout << ANSWER_SAVE_MSG << endl;
            cout << diff << endl;
        }

        else if (input == "4") {
            auto poly = getOnePoly();
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
            }
        }

        else if (input == "5") {
            auto poly = getOnePoly();
            cout << "input a num: " << endl;
            PrintPromtForInput();
            double num;
            cin >> num;
            cout << poly.evaluate(num) << endl;
        }

        else {
            cout << ORDER_ERROR << endl; 
        }
    }
    return 0;
} 
