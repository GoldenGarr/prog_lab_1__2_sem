#ifndef LAB1_CPP_POLYLINE_H
#define LAB1_CPP_POLYLINE_H

#include <utility>

#include "vector"
#include "Point.h"


class PolyLine {
private:
    std::vector<Point> points_sequence;
public:
    // Default constructor
    PolyLine() : points_sequence() {}

    // Constructor
    PolyLine(std::vector<Point> points_sequence) : points_sequence(std::move(points_sequence)) {}

    // Copy constructor
    PolyLine(const PolyLine &pl) : points_sequence(pl.points_sequence) {}

    // Assignment operator
    PolyLine &operator=(const PolyLine &pl) {
        if (this != &pl) {
            this->points_sequence = pl.getPointsSequence();
        }
        return *this;
    }

    const std::vector<Point> &getPointsSequence() const {
        return points_sequence;
    }
};


#endif //LAB1_CPP_POLYLINE_H
