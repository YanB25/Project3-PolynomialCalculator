object = PolynomialCalculator.o polynomial.o
header = polynomial.hpp
PolynomialCalculator.out : $(object) $(header) 
	g++ -g $(object) -o PolynomialCalculator.out
	./PolynomialCalculator.out
	rm *.o
PolynomialCalculator.o : PolynomialCalculator.cpp
	g++ -c PolynomialCalculator.cpp -std=c++14 -Wall -W
polynomial.o : polynomial.cpp polynomial.hpp
	g++ -c polynomial.cpp -std=c++14 -Wall -W
