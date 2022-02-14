#ifndef LAB1_CPP_POLYGON_H
#define LAB1_CPP_POLYGON_H

#include <utility>
#include <vector>
#include "Point.h"
#include <cmath>
#include <iostream>

using namespace std;


class Polygon {
protected:
    vector<Point> points_sequence;
public:
    Polygon() : points_sequence() {}

    Polygon(vector<Point> points_sequence) : points_sequence(std::move(points_sequence)) {
        if (!isPolygon())
            throw std::invalid_argument("Not a polygon");
    }

    Polygon(const Polygon &pg) : points_sequence(pg.points_sequence) {}

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

    bool isPolygon() {
        double angle_sum = 0;
        for (int i = 0; i < points_sequence.size(); ++i) {
            int point1 = i;
            int point2 = (i + 1) % points_sequence.size();
            int point3 = (i + 2) % points_sequence.size();

            double a = sqrt(pow(points_sequence[point1].getX() - points_sequence[point2].getX(), 2)
                            + pow(points_sequence[point1].getY() - points_sequence[point2].getY(), 2));

            double b = sqrt(pow(points_sequence[point2].getX() - points_sequence[point3].getX(), 2)
                            + pow(points_sequence[point2].getY() - points_sequence[point3].getY(), 2));

            double c = sqrt(pow(points_sequence[point1].getX() - points_sequence[point3].getX(), 2)
                            + pow(points_sequence[point1].getY() - points_sequence[point3].getY(), 2));

            // Duplicate points
            if (a == 0 || b == 0)
                return false;
            // Fewer angles than expected
            if (fabs(acos((a * a + b * b - c * c) / (2 * a * b)) - M_PI) < 0.01f)
                return false;
            angle_sum += acos((a * a + b * b - c * c) / (2 * a * b));
        }
        std::cout << angle_sum << "\n";
        // Self-crossing or non-convex
        if (fabs(angle_sum - M_PI * ((double) points_sequence.size() - 2)) > 0.01f)
            return false;
        return true;
    }
};


#endif //LAB1_CPP_POLYGON_H
