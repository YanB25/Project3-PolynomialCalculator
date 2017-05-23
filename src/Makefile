object = PolynomialCalculator.o polynomial.o IOHelper.o
header = polynomial.hpp IOHelper.hpp
PolynomialCalculator.out : $(object) $(header) 
	g++ -g $(object) -o PolynomialCalculator.out
	./PolynomialCalculator.out
PolynomialCalculator.o : PolynomialCalculator.cpp
	g++ -c PolynomialCalculator.cpp -std=c++14 -Wall -W
polynomial.o : polynomial.cpp polynomial.hpp
	g++ -c polynomial.cpp -std=c++14 -Wall -W
IOHelper.o : IOHelper.cpp IOHelper.hpp polynomial.hpp
	g++ -c IOHelper.cpp -std=c++14 -Wall -W
run:
	./PolynomialCalculator.out
clear:
	rm *.o
	rm *.out
