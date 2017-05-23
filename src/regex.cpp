// regex_iterator constructor
#include <iostream>
#include <cstdio>
#include <string>
#include <regex>
using namespace std;
int main ()
{
  const string s = "p = (-1, 2)(3,4)(-3.24,4)(4.21, 2)";
  std::regex e ("\\(-?(\\d+\\.)?\\d+,\\s?\\d+\\)");

  std::regex_iterator<std::string::iterator> rit ( s.begin(), s.end(), e );
  std::regex_iterator<std::string::iterator> rend;

  while (rit!=rend) {
    double a, b;
    sscanf(rit->str().c_str(), "(%lf, %lf)", &a, &b);
    cout << a << " " << b << endl;
    ++rit;
  }

  return 0;
  //  string pattern("^(([a-zA-Z]+\\s?=\\s?)?(\\(-?(\\d+\\.)?\\d+,\\s?\\d+\\))+)$");
  //  regex e(pattern);
  //  smatch results;
  //  string txt;
  //  while (getline(cin ,txt)) {
  //      cout << txt << endl;
  //      if (regex_search(txt, results, e)) {
  //          cout << "ok" << endl;
  //      } else {
  //          cout << "no" << endl;
  //      }
  //  }
  //  return 0;
}
