#ifndef LAB1_CPP_TRIANGLE_H
#define LAB1_CPP_TRIANGLE_H

#include <utility>
#include <vector>
#include "Polygon.h"

class Triangle : public Polygon {
public:
    Triangle() : Polygon() {}

    Triangle(const Point& p1, const Point& p2, const Point& p3) {
        this->points_sequence.push_back(p1);
        this->points_sequence.push_back(p2);
        this->points_sequence.push_back(p3);
    }

    Triangle(vector<Point> points_sequence) : Polygon(std::move(points_sequence)) {
        if (!isValid())
            throw std::invalid_argument("Triangle has to be initialized by 3 Points");
    }

    Triangle(const Triangle &tr) : Polygon(tr) {}

    // KEKIS
    bool isValid() {
        return Polygon::points_sequence.size() == 3;
    }
};


#endif //LAB1_CPP_TRIANGLE_H
