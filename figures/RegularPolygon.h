//
// Created by Максим on 12.02.2022.
//

#ifndef LAB1_CPP_REGULARPOLYGON_H
#define LAB1_CPP_REGULARPOLYGON_H

#include "Polygon.h"
#include <iostream>

#include <utility>


class RegularPolygon : public Polygon {
public:
    // TODO
    RegularPolygon() : Polygon() {}

    RegularPolygon(vector<Point> points_sequence) : Polygon(std::move(points_sequence)) {
        if (!isValid())
            throw std::invalid_argument("Not a regular polygon");
    }

    bool isValid() {
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

            if (fabs((a * a + b * b - c * c) / (2 * a * b) -
                     cos(M_PI * ((double) points_sequence.size() - 2) / (double) points_sequence.size())) > 0.01f)
                return false;
        }
        return true;
    }
};


#endif //LAB1_CPP_REGULARPOLYGON_H
