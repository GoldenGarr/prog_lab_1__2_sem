//
// Created by Максим on 08.02.2022.
//

#ifndef LAB1_CPP_TRAPEZOID_H
#define LAB1_CPP_TRAPEZOID_H

#include "Polygon.h"

class Trapezoid : public Polygon {
public:
    Trapezoid() : Polygon() {}

    Trapezoid(int angles_amount, vector<Point> points_sequence)
            : Polygon(angles_amount, points_sequence) {}

    Trapezoid(vector<Point> points_sequence)
            : Polygon(points_sequence) {}

   bool is_trapezoid() {

    }
};


#endif //LAB1_CPP_TRAPEZOID_H
