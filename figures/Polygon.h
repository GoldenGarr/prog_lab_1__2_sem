#ifndef LAB1_CPP_POLYGON_H
#define LAB1_CPP_POLYGON_H

#include <utility>
#include <vector>
#include "Point.h"
#include <cmath>

using namespace std;


class Polygon {
protected:
    size_t angles_amount;
    vector<Point> points_sequence;
public:
    Polygon() : angles_amount(0), points_sequence() {}

    Polygon(int angles_amount, vector<Point> points_sequence) {
        this->angles_amount = angles_amount;
        this->points_sequence = std::move(points_sequence);
    }

    Polygon(vector<Point> pointsSequence) : points_sequence(std::move(pointsSequence)) {
        this->angles_amount = points_sequence.size();
    }

    Polygon(const Polygon &pg) {
        this->angles_amount = pg.angles_amount;
        this->points_sequence = pg.points_sequence;
    }

    Polygon &operator=(const Polygon &pg) {
        if (this != &pg) {
            this->points_sequence = pg.points_sequence;
            this->angles_amount = pg.angles_amount;
        }
        return *this;
    }

    double getPerimeter() {
        double perimeter = 0.0;
        for (int i = 0; i < points_sequence.size() - 1; ++i) {
            perimeter += sqrt(pow(points_sequence[i].getX() - points_sequence[i + 1].getX(), 2)
                              + pow(points_sequence[i].getY() - points_sequence[i + 1].getY(), 2));
        }
        perimeter += sqrt(pow(points_sequence[0].getX() - points_sequence[angles_amount - 1].getX(), 2)
                          + pow(points_sequence[0].getY() - points_sequence[angles_amount - 1].getY(), 2));
        return perimeter;
    }

    double getSpace() {
        // Shoelace formula
        double left = 0.0;
        double right = 0.0;
        for (int i = 0; i < points_sequence.size(); ++i) {
            unsigned long j = (i + 1) % points_sequence.size();
            left += points_sequence[i].getX() * points_sequence[j].getY();
            right += points_sequence[j].getX() * points_sequence[i].getY();
        }
        return 0.5 * abs(left - right);
    }
};


#endif //LAB1_CPP_POLYGON_H
