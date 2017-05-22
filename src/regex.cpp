// regex_iterator constructor
#include <iostream>
#include <string>
#include <regex>

int main ()
{
  std::string s ("q = (1,2)(3,4)(5,6)");
  std::regex e ("\\(\\d,\\d\\)");   // matches words beginning by "sub"

  std::regex_iterator<std::string::iterator> rit ( s.begin(), s.end(), e );
  std::regex_iterator<std::string::iterator> rend;

  while (rit!=rend) {
    std::cout << rit->str() << std::endl;
    ++rit;
  }

  return 0;
}
