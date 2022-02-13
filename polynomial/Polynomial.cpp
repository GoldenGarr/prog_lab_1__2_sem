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

    PolynomialElement operator+(const PolynomialElement &pe) const {
        return {this->getCoefficient() + pe.getCoefficient(),
                this->getPower()};
    }

    void invertCoefficient() {
        coefficient = -coefficient;
    }

    void multiplyCoefficient(double multiplier) {
        coefficient *= multiplier;
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
                PolynomialElement element = elements[i] + p.elements[j];
                sum.addPolynomialElement(element);
                ++i;
                ++j;
            } else if (elements[i].getPower() > p.elements[j].getPower()) {
                sum.addPolynomialElement(elements[i]);
                ++i;
            } else {
                sum.addPolynomialElement(p.getElements()[j]);
                ++j;
            }

            if (i >= getElements().size()) {
                while (j < p.getElements().size()) {
                    sum.addPolynomialElement(p.getElements()[j]);
                    ++j;
                }
                break;
            }
            if (j >= p.getElements().size()) {
                while (i < elements.size()) {
                    sum.addPolynomialElement(elements[i]);
                    ++i;
                }
                break;
            }
        }
        return sum;
    }

    // Unary
    Polynomial operator-() {
        Polynomial inverted = *this;
        for (int i = 0; i < elements.size(); ++i) {
            inverted.elements[i].invertCoefficient();
        }
        return inverted;
    }

    // Binary
    Polynomial operator-(const Polynomial &p) {
        Polynomial p_copy = p;
        p_copy = -p_copy;
        Polynomial diff = *this + p_copy;
        return diff;
    }

    Polynomial operator+=(const Polynomial &p) {
        *this = *this + p;
        return *this;
    }

    Polynomial operator-=(const Polynomial &p) {
        *this = *this - p;
        return *this;
    }

    Polynomial operator*(double multiplier) {
        Polynomial p_copy = *this;
        for (int i = 0; i < p_copy.elements.size(); ++i) {
            p_copy.elements[i].multiplyCoefficient(multiplier);
        }
        return p_copy;
    }

    Polynomial operator/(double divider) {
        Polynomial p_copy = *this;
        for (int i = 0; i < p_copy.elements.size(); ++i) {
            p_copy.elements[i].multiplyCoefficient(1.0 / divider);
        }
        return p_copy;
    }

    Polynomial operator*=(double multiplier) {
        *this = *this * multiplier;
        return *this;
    }

    Polynomial operator/=(double divider) {
        *this = *this / divider;
        return *this;
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

    Polynomial poly1;
    poly1.addPolynomialElement(p1);
    poly1.addPolynomialElement(p2);
    poly1.addPolynomialElement(p3);
    poly1.addPolynomialElement(p4);

    poly1.print();

    PolynomialElement p12(1, 3);
    PolynomialElement p22(3, 2);
    PolynomialElement p32(20, 0);

    Polynomial poly2;
    poly2.addPolynomialElement(p12);
    poly2.addPolynomialElement(p22);
    poly2.addPolynomialElement(p32);

    // poly2 += poly1;
    poly2 = poly2 / 100;
    poly2.print();
    Polynomial polySum = poly1 + poly2;

    polySum.print();
}
