#include "polynomial.hpp"
#include <iostream>
#include <algorithm>
#include <cstddef>
#include <cmath>
using std::max;
using std::cin;
using std::cout;
using std::endl;
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
    return *this;
}

polynomial polynomial::operator*(double num) const {
    polynomial ret(*this);
    ret *= num;
    return ret;
}

bool polynomial::operator==(const self& rhs) const {
    for (size_t i = 0; i <= getDegree(); ++i) {
        if (coefficient_[i] != rhs.getCoefficient()[i]) {
            return false;
        }
    }

    for (size_t i = getDegree(); i < rhs.getDegree(); ++i) {
        if (rhs.getCoefficient()[i] != 0) {
            return false;
        }
    }
    return true;
}

ostream& operator<<(ostream& os, const polynomial& rhs) {
    bool has_reach_nonzero = false;
    size_t degree = rhs.getDegree();
    const auto& coefficient = rhs.getCoefficient();
    if (degree == 0) {
        os << "0";
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












