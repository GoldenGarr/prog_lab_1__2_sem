#include <utility>
#include <vector>

using namespace std;

class Polynomial {
private:
    vector<int> coefficients;
    size_t polynomial_power;
public:
    Polynomial() : coefficients(), polynomial_power(0) {
    }

    Polynomial(vector<int> coefficients) {
        this->polynomial_power = coefficients.size();
        this->coefficients = std::move(coefficients);
    }

    Polynomial(size_t polynomial_power) : coefficients(), polynomial_power(polynomial_power) {
    }

    Polynomial(const Polynomial &p) {
        this->polynomial_power = p.getPolynomialPower();
        this->coefficients = p.getCoefficients();
    }

    Polynomial &operator=(const Polynomial &p) {
        if (this != &p) {
            this->coefficients = p.getCoefficients();
            this->polynomial_power = p.getPolynomialPower();
        }
        return *this;
    }

    const vector<int> &getCoefficients() const {
        return coefficients;
    }

    size_t getPolynomialPower() const {
        return polynomial_power;
    }
};


