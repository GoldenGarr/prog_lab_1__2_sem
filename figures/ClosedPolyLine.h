#ifndef LAB1_CPP_CLOSEDPOLYLINE_H
#define LAB1_CPP_CLOSEDPOLYLINE_H

#include <utility>
#include <vector>
#include "Point.h"

class ClosedPolyLine {
private:
    size_t points_amount;
    std::vector<Point> points_sequence;
public:
    // Default constructor
    ClosedPolyLine(): points_amount(0), points_sequence() {}

    // Constructor
    ClosedPolyLine(size_t points_amount, std::vector<Point> points_sequence) {
        if (points_sequence[0] != points_sequence[points_sequence.size() - 1]) {
            // TODO: UB
        }
        this->points_amount = points_amount;
        this->points_sequence = std::move(points_sequence);
    }

    ClosedPolyLine(std::vector<Point> points_sequence) {
        if (points_sequence[0] != points_sequence[points_sequence.size() - 1]) {
            // TODO: UB
        }
        this->points_amount = points_sequence.size();
        this->points_sequence = std::move(points_sequence);
    }

    // Copy constructor
    ClosedPolyLine(const ClosedPolyLine &pl) {
        this->points_amount = pl.points_amount;
        this->points_sequence = pl.points_sequence;
    }

    // Assignment operator
    ClosedPolyLine &operator=(const ClosedPolyLine &pl) {
        if (this != &pl) {
            this->points_sequence = pl.getPointsSequence();
            this->points_amount = pl.getPointsAmount();
        }
        return *this;
    }

    // Considering the polyline to be non-self-intersecting
    float getPerimeter() {
        return 0.0;
    }

    float getSpace() {
        return 0.0;
    }

    size_t getPointsAmount() const {
        return points_amount;
    }

    const std::vector<Point> &getPointsSequence() const {
        return points_sequence;
    }
};


#endif //LAB1_CPP_CLOSEDPOLYLINE_H
