#ifndef LAB1_CPP_TRIANGLE_H
#define LAB1_CPP_TRIANGLE_H

#include <utility>
#include <vector>
#include "Polygon.h"

class Triangle : public Polygon {
public:
    // TODO:
    Triangle() : Polygon() {}

    Triangle(int angles_amount, vector<Point> points_sequence) : Polygon(angles_amount, std::move(points_sequence)) {}

    Triangle(vector<Point> points_sequence) : Polygon(std::move(points_sequence)) {}

    Triangle(const Triangle &tr) : Polygon(tr) {
    }

    // KEKIS
    bool is_triangle() {
        return Polygon::points_sequence.size() == 3;
    }
};


#endif //LAB1_CPP_TRIANGLE_H
