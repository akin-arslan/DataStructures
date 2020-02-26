#include <iostream>

#include "Polynomial.hpp"

int main() {
    Polynomial p1("(3)x^2 + (-1)x^2 + (4)x^5 + (7)x^3");

    p1.printPolynomial();

    p1.simplifyByExponents();

    p1.printPolynomial();

    return 0;
}