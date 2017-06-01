#ifndef _POLYNOMIAL_
#define _POLYNOMIAL_
#include <iostream>
#include <regex>
#include <vector>
#include <string>
using std::vector;
using std::string;
using std::ostream;
using std::regex;
class polynomial {
public:
    typedef vector<double> coefficient_t;
    typedef polynomial self;
    polynomial(string s); 
    polynomial() { coefficient_.resize(1); }
    polynomial(const polynomial& rhs) = default;
    ~polynomial() = default;

    self& operator+=(const self& rhs);
    self operator+(const self& rhs) const;
    self& operator-=(const self& rhs);
    self operator-(const self& rhs) const;
    //self& operator*=(const self& rhs);
    self& operator*=(double num);
    self operator*(const self& rhs) const;
    self operator*(double num) const;
    self operator-() const; 
    bool operator==(const self& rhs) const;
    bool operator!=(const self& rhs) const;
    friend ostream& operator<<(ostream& os, const self& s);

    size_t getDegree() const { return coefficient_.size() - 1; }
    void setDegree(size_t d) { if (d > getDegree()) coefficient_.resize(d + 1); }
    coefficient_t& getCoefficient() { return coefficient_; }
    const coefficient_t& getCoefficient() const { return coefficient_; }
    
    polynomial derivation() const;

    static bool isValid(const string& s) { return regex_search(s, regex_); }
    double evaluate(double) const;

    static const string pattern_;
    static const string pattern_iterate_;
    static const string poly_name_pattern_;
    static regex regex_;
    static regex regex_iterate_;
    static regex regex_poly_name_;
private:
    coefficient_t coefficient_;
    //static self parse_(const string& s);
    void shrink_();
};


#endif
