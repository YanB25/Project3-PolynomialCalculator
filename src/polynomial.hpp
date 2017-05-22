#ifndef _POLYNOMIAL_
#define _POLYNOMIAL_
#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;
using std::ostream;
class polynomial {
public:
    typedef vector<double> coefficient_t;
    typedef polynomial self;
    //TODO
    //polynomial(string s) {}
    //TODO for debug, please delete
    polynomial(int d) {
        coefficient_.resize(d);
        for (int i = 0; i < d; ++i) { 
            coefficient_[i] = 4 - i;
        }
    }
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

    static bool isValid(const string& s);

    size_t getDegree() const { return coefficient_.size() - 1; }
    void setDegree(size_t d) { if (d > getDegree()) coefficient_.resize(d + 1); }
    coefficient_t& getCoefficient() { return coefficient_; }
    const coefficient_t& getCoefficient() const { return coefficient_; }
    
private:
    coefficient_t coefficient_;
    static self parse_(const string& s);
    void shrink_();
};


#endif
