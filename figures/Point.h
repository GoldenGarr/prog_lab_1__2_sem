#ifndef LAB1_CPP_POINT_H
#define LAB1_CPP_POINT_H


class Point {
private:
    double x, y;

public:
    // Default constructor
    Point() {
        x = 0.0;
        y = 0.0;
    }

    // Constructor
    Point(double x, double y) : x(x), y(y) {}

    // Copy constructor
    Point(const Point &p) : x(p.x), y(p.y) {}

    // Assignment operator
    Point &operator=(const Point &p) {
        if (this != &p) {
            this->x = p.getX();
            this->y = p.getY();
        }
        return *this;
    }

    // IsEqual operator
    bool operator==(const Point &p1) const {
        return (this->x == p1.getX()) && (this->y == p1.getY());
    }

    bool operator!=(const Point &p1) const {
        return !((this->x == p1.getX()) && (this->y == p1.getY()));
    }

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }
};


#endif //LAB1_CPP_POINT_H
