//
// Created by Максим on 08.02.2022.
//

#ifndef LAB1_CPP_TRAPEZOID_H
#define LAB1_CPP_TRAPEZOID_H

#include <utility>
#include "Polygon.h"

class Trapezoid : public Polygon {
public:
    // TODO
    Trapezoid() : Polygon() {}

    Trapezoid(vector<Point> points_sequence)
            : Polygon(std::move(points_sequence)) {
        if (!isValid())
            throw std::invalid_argument("Not a trapezoid!");
    }

    bool isValid() {
        if ((points_sequence[0].getX() - points_sequence[1].getX() == 0)) {
            if (points_sequence[2].getX() - points_sequence[3].getX() == 0)
                return true;
        } else {
            double k1 = (points_sequence[0].getY() - points_sequence[1].getY()) / (points_sequence[0].getX() - points_sequence[1].getX());
            if (points_sequence[2].getX() - points_sequence[3].getX() != 0) {
                double k2 = (points_sequence[2].getY() - points_sequence[3].getY()) /
                            (points_sequence[2].getX() - points_sequence[3].getX());
                if (k1 == k2)
                    return true;
            }
        }

        if ((points_sequence[1].getX() - points_sequence[2].getX() == 0)) {
            if (points_sequence[3].getX() - points_sequence[30].getX() == 0)
                return true;
        } else {
            double k1 = (points_sequence[1].getY() - points_sequence[2].getY()) / (points_sequence[1].getX() - points_sequence[2].getX());
            if (points_sequence[3].getX() - points_sequence[0].getX() != 0) {
                double k2 = (points_sequence[3].getY() - points_sequence[0].getY()) /
                            (points_sequence[3].getX() - points_sequence[0].getX());
                if (k1 == k2)
                    return true;
            }
        }

        return false;
    }
};


#endif //LAB1_CPP_TRAPEZOID_H
