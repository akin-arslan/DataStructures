#include "Polynomial.hpp"

Polynomial::Polynomial() {
    // Does nothing.
}

Polynomial::Polynomial(std::string expression) {
    // expression = (c_1)x^n_1 + (c_2)x^n_2 + ... + (c_k)x^n_k
    // c's are integer coefficients, n's are non-negative integer exponents.

    std::string delimiter = " + ";

    std::string term;
    std::string coefficient;
    std::string exponent;
    size_t pos = 0;

    while (true) {
        pos = expression.find(delimiter);

        bool breakTheLoop = (pos == std::string::npos);

        term = expression.substr(0, pos);
        expression.erase(0, pos + delimiter.length());

        pos = term.find("x");

        coefficient = term.substr(1, pos - 2);
        exponent = term.substr(pos + 2, term.length() - pos);

        terms.insertAtTheEnd(Term(std::atoi(coefficient.c_str()), std::atoi(exponent.c_str())));

        if (breakTheLoop) break;
    }
}

void Polynomial::printPolynomial() {
    // prints the polynomial in expression format.
    // expression = (c_1)x^n_1 + (c_2)x^n_2 + ... + (c_k)x^n_k

    Node<Term> *node = terms.getFirstNode();

    while (node) {
        std::cout << "(" << node->element.getCoefficient() << ")x^" << node->element.getExponent();
        if (node->next) std::cout << " + ";
        node = node->next;
    }

    std::cout << std::endl;
}

void Polynomial::simplifyByExponents() {
    /* TODO */

    Node<Term> *outer = (this -> terms).getFirstNode();
    Node<Term> *inner = outer -> next;
    Node<Term> *temp = NULL;

    while (outer != NULL) {
        inner = outer -> next;
        while (inner != NULL) {
            if ((inner -> element).getExponent() == (outer -> element).getExponent()) {

                (outer -> element).setCoefficient((inner -> element).getCoefficient() + (outer -> element).getCoefficient());
                temp = inner;
                inner = inner -> next;
                (this -> terms).removeNode(temp);
            }
            else {
                inner = inner -> next;
            }
        }
        outer = outer -> next;

    }

    outer = (this -> terms).getFirstNode();

    while (outer != NULL) {
        if (outer -> element.getCoefficient() != 0) {
            outer  = outer -> next;
        }
        else {
            temp = outer;
            outer = outer -> next;
            (this -> terms).removeNode(temp);
        }
    } 

}

Polynomial Polynomial::operator+(const Polynomial &rhs) const {
    /* TODO */

    Polynomial new_object;

    Node<Term> *gez = (this -> terms).getFirstNode();

    while (gez) {
         (new_object.terms).insertAtTheEnd(Term(gez -> element.getCoefficient(), gez -> element.getExponent()));
         gez = gez -> next;
    }

    gez = (rhs.terms).getFirstNode();

    while (gez) {
        (new_object.terms).insertAtTheEnd(Term(gez -> element.getCoefficient(), gez -> element.getExponent()));
        gez = gez -> next;
    }

    return new_object;

}
