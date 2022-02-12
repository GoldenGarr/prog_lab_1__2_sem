#ifndef LAB1_CPP_POLYGON_H
#define LAB1_CPP_POLYGON_H

#include <utility>
#include <vector>
#include "Point.h"
#include <cmath>

using namespace std;


class Polygon {
protected:
    vector<Point> points_sequence;
public:
    Polygon() : points_sequence() {}

    Polygon(vector<Point> points_sequence) {
        this->points_sequence = std::move(points_sequence);
    }

    Polygon(const Polygon &pg) {
        this->points_sequence = pg.points_sequence;
    }

    Polygon &operator=(const Polygon &pg) {
        if (this != &pg) {
            this->points_sequence = pg.points_sequence;
        }
        return *this;
    }

    double perimeter() {
        double output = 0.0;
        for (int i = 0; i < points_sequence.size(); ++i) {
            unsigned long j = (i + 1) % points_sequence.size();
            output += sqrt(pow(points_sequence[i].getX() - points_sequence[j].getX(), 2)
                           + pow(points_sequence[i].getY() - points_sequence[j].getY(), 2));
        }
        return output;
    }

    double space() {
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
