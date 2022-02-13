#include <utility>
#include <iostream>
#include <vector>


class PolynomialElement {
private:
    double coefficient;
    unsigned int power;
public:
    PolynomialElement(double coefficient, unsigned int power) {
        this->coefficient = coefficient;
        this->power = power;
    }

    double getCoefficient() const {
        return coefficient;
    }

    unsigned int getPower() const {
        return power;
    }
};

class Polynomial {
private:
    std::vector<PolynomialElement> elements;
    unsigned int polynomial_power;
public:
    Polynomial() : elements(), polynomial_power(0) {
    }

    ~Polynomial() = default;

    Polynomial(std::vector<PolynomialElement> elements) {
        this->polynomial_power = elements.size();
        this->elements = std::move(elements);
    }

    Polynomial(const Polynomial &p) {
        this->polynomial_power = p.getPolynomialPower();
        this->elements = p.getElements();
    }

    void print() {
        for (int i = 0; i < elements.size(); ++i) {
            std::cout << "(" << elements[i].getCoefficient() << "x ** " << elements[i].getPower()
                      << ")";
            if (i != elements.size() - 1)
                std::cout << " + ";
        }
        std::cout << std::endl;
    }

    Polynomial &operator=(const Polynomial &p) {
        if (this != &p) {
            this->polynomial_power = p.getPolynomialPower();
            this->elements = p.getElements();
        }
        return *this;
    }

    bool operator==(const Polynomial &p) {
//        for (int i = 0; i < this->polynomial_power; i++) {
//            if (this->elements[i].getCoefficient() == 0) {
//                for (int j = 0; j < p.getPolynomialPower(); j++) {
//                    if (p.getElements()[j].getPower() == this->elements[i].getPower()
//                        && p.getElements()[j].getCoefficient() != 0) {
//                        return false;
//                    }
//                }
//            } else {
//
//            }
//        }
return true;
    }

    bool operator!=(const Polynomial &p) {
        return !(*this == p);
    }

    Polynomial operator+(const Polynomial &p) {
        int i = 0;
        int j = 0;
        Polynomial sum;
        while (true) {
            if (elements[i].getPower() == p.elements[j].getPower()) {
                PolynomialElement element(elements[i].getCoefficient() + p.elements[i].getCoefficient(),
                                          elements[i].getPower());
                sum.addPolynomialElement(element);
                ++i;
                ++j;
            }

            if (i > getElements().size()) {
                break;
            }
            if (j > p.getElements().size()) {
                break;
            }
        }
        return Polynomial();
    }

    void addPolynomialElement(const PolynomialElement &elem) {
        elements.push_back(elem);
    }

    const std::vector<PolynomialElement> &getElements() const {
        return elements;
    }

    size_t getPolynomialPower() const {
        return polynomial_power;
    }
};

int main() {
    PolynomialElement p1(1, 3);
    PolynomialElement p2(2, 2);
    PolynomialElement p3(-3, 1);
    PolynomialElement p4(4, 0);

    Polynomial polynomial;
    polynomial.addPolynomialElement(p1);
    polynomial.addPolynomialElement(p2);
    polynomial.addPolynomialElement(p3);
    polynomial.addPolynomialElement(p4);

    polynomial.print();
}
