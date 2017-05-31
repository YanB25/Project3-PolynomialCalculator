#include "polynomial.hpp"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstddef>
#include <cmath>
using std::max;
using std::cin;
using std::cout;
using std::endl;
using std::regex_iterator;

const string polynomial::pattern_ = "^(([a-zA-Z]+\\s?=\\s?)?(\\(-?(\\d+\\.)?\\d+,\\s?\\d+\\))+)$";
const string polynomial::pattern_iterate_ = "\\(-?(\\d+\\.)?\\d+,\\s?\\d+\\)";
regex polynomial::regex_(polynomial::pattern_);
regex polynomial::regex_iterate_(polynomial::pattern_iterate_);

polynomial::polynomial(string s) : polynomial() {
    regex_iterator<string::iterator> rit (s.begin(),s.end(),regex_iterate_);
    regex_iterator<string::iterator> rend;
    while (rit != rend) {
        double co, de;
        sscanf(rit->str().c_str(), "(%lf, %lf)", &co, &de);
        if (de > getDegree()) {
            setDegree(de);
        }
        coefficient_[de] = co;
        ++rit;
    }
}
void polynomial::shrink_() {
    while(coefficient_.size() != 0 && coefficient_.back() == 0) {
        coefficient_.pop_back();
    }
}
polynomial& polynomial::operator+=(const self& rhs) {
    size_t max_size = max(getDegree(), rhs.getDegree());
    if (max_size > getDegree()) {
        setDegree(max_size);
    }
    for (size_t i = 0; i <= rhs.getDegree(); ++i) {
        coefficient_[i] += rhs.getCoefficient()[i];
    }
    shrink_();
    return (*this);
}

polynomial polynomial::operator+(const self& rhs) const {
    polynomial ret(*this);
    ret += rhs;
    return ret;
}

polynomial polynomial::operator-() const {
    polynomial ret(*this);
    for (auto& i : ret.getCoefficient()) {
        i = -1 * i;
    }
    return ret;
}

polynomial& polynomial::operator-=(const self& rhs) {
    (*this) += -rhs;
    return (*this);
}

polynomial polynomial::operator-(const self& rhs) const {
    polynomial ret(*this);
    ret -= rhs;
    return ret;
}

polynomial& polynomial::operator*=(double num) {
    for (auto& i : coefficient_) {
        i *= num;
    }
    shrink_();
    return *this;
}

polynomial polynomial::operator*(double num) const {
    polynomial ret(*this);
    ret *= num;
    return ret;
}

polynomial polynomial::operator*(const self& rhs) const {
    polynomial ret;
    int degree = getDegree() + rhs.getDegree();
    ret.setDegree(degree);
    for (int i = 0; i <= degree; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j <= (int)getDegree() && i - j <= (int)rhs.getDegree()) {
                ret.getCoefficient()[i] += getCoefficient()[j] * rhs.getCoefficient()[i - j];
            }
        }
    }
    ret.shrink_();
    return ret;
}

bool polynomial::operator==(const self& rhs) const {
    size_t min_degree = std::min(getDegree(), rhs.getDegree());
    for (size_t i = 0; i <= min_degree; ++i) {
        if (coefficient_[i] != rhs.getCoefficient()[i]) {
            //cout << "ne " << i << " " << coefficient_[i] << " " << rhs.coefficient_[i] << endl; //TODO
            return false;
        }
    }

    for (size_t i = min_degree + 1; i < rhs.getDegree(); ++i) {
        if (rhs.getCoefficient()[i] != 0) {
            //cout << "ne2 " << i << rhs.get
            return false;
        }
    }
    for (size_t i = min_degree + 1; i < getDegree(); ++i) {
        if (getCoefficient()[i] != 0) {
            return false;
        }
    }
    return true;
}

ostream& operator<<(ostream& os, const polynomial& rhs) {
    bool has_reach_nonzero = false;
    size_t degree = rhs.getDegree();
    const auto& coefficient = rhs.getCoefficient();
    if (coefficient.size() == 0) {
        cout << "0";
        return os;
    }
    if (degree == 0) {
        cout << coefficient[0];
        return os;
    }
    for (int i = rhs.getDegree(); i >= 1; i--) {
        if (coefficient[i] != 0) {
            if (coefficient[i] < 0 && has_reach_nonzero) {
                os << " - ";
            } else if (coefficient[i] > 0 && has_reach_nonzero){
                os << " + ";
            }
            if (coefficient[i] != 1 && has_reach_nonzero) {
                os << abs(coefficient[i]);
            } else if (coefficient[i] != 1){
                os << coefficient[i];
            }
            os << "x";
            if (i != 1) {
                os << "^" << i;
            }
            has_reach_nonzero = true;
        }
    }
    if (coefficient[0] != 0) {
        if (coefficient[0] > 0) {
            cout << " + " << coefficient[0];
        } else {
            cout << " - " << abs(coefficient[0]);
        }
    }
    return os;
}

double polynomial::evaluate(double x) const {
    double sum = 0;
    for (size_t i = 0; i <= getDegree(); ++i) {
        sum += coefficient_[i] * pow(x, i);
    }
    return sum;
}

polynomial polynomial::derivation() const {
    polynomial dev;
    size_t degree = getDegree() - 1;
    dev.setDegree(degree);
    for (int i = degree; i >= 0; --i) {
        dev.getCoefficient()[i] = (i + 1) * getCoefficient()[i + 1];
    }
    return dev;
}





