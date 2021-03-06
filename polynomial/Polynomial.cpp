#include <utility>
#include <iostream>
#include <vector>


class PolynomialElement {
public:
    double coefficient;
    unsigned int power;
public:
    PolynomialElement() : coefficient(0), power(0) {}

    explicit PolynomialElement(double coefficient, unsigned int power)
            : coefficient(coefficient), power(power) {}

    PolynomialElement operator+(const PolynomialElement &pe) const {
        PolynomialElement elem(this->getCoefficient() + pe.getCoefficient(),
                               this->getPower());
        return elem;
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
public:
    Polynomial() : elements() {
    }

    ~Polynomial() = default;

    explicit Polynomial(std::vector<PolynomialElement> elements) :
            elements(std::move(elements)) {}

    Polynomial(const Polynomial &p) {
        this->elements = p.getElements();
    }

    Polynomial &operator=(const Polynomial &p) {
        if (this != &p) {
            this->elements = p.getElements();
        }
        return *this;
    }

    bool operator==(const Polynomial &p) {
        Polynomial diff = *this - p;
        for (auto &element: diff.elements) {
            if (element.getCoefficient() != 0)
                return false;
        }
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

    friend std::istream &operator>>(std::istream &in, Polynomial &p) {
        int elements_number;
        in >> elements_number;
        while (elements_number > 0) {
            PolynomialElement elem;
            in >> elem.coefficient;
            in >> elem.power;
            p.elements.push_back(elem);
            --elements_number;
        }
        return in;
    }

    friend std::ostream &operator<<(std::ostream &out, const Polynomial &p) {
        for (int i = 0; i < p.elements.size(); ++i) {
            out << "(" << p.elements[i].getCoefficient() << "x ** " << p.elements[i].getPower()
                << ")";
            if (i != p.elements.size() - 1)
                out << " + ";
        }
        out << "\n";
        return out;
    }

    double operator[](int index) {
        int i = 0;
        while (index > 0) {
            if (elements[i].getCoefficient() != 0)
                --index;
            ++i;
        }
        return elements[i].getCoefficient();
    }

    void addPolynomialElement(const PolynomialElement &elem) {
        elements.push_back(elem);
    }

    const std::vector<PolynomialElement> &getElements() const {
        return elements;
    }
};

/*
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

    std::cout << poly1;

    PolynomialElement p12(1, 3);
    PolynomialElement p22(3, 2);
    PolynomialElement p32(20, 0);

    Polynomial poly2;
    poly2.addPolynomialElement(p12);
    poly2.addPolynomialElement(p22);
    poly2.addPolynomialElement(p32);

    // poly2 += poly1;
    poly2 = poly2 / 100;
    std::cout << poly2;
    Polynomial polySum = poly1 + poly2;

    std::cout << polySum;

//    Polynomial poly3;
//    std::cin >> poly3;
//    std::cout << poly3;
    std::cout << (poly1 == poly2) << "\n";
    std::cout << (poly1 != poly1);

    std::cout << "\n" << poly1[1];

}
*/
