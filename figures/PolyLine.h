#ifndef LAB1_CPP_POLYLINE_H
#define LAB1_CPP_POLYLINE_H

#include <utility>

#include "vector"
#include "Point.h"


class PolyLine {
private:
    size_t points_amount;
    std::vector<Point> points_sequence;
public:
    // Default constructor
    PolyLine() : points_amount(0), points_sequence() {}

    // Constructor
    PolyLine(size_t points_amount, std::vector<Point> points_sequence) {
        this->points_amount = points_amount;
        this->points_sequence = std::move(points_sequence);
    }

    PolyLine(std::vector<Point> points_sequence) {
        this->points_amount = points_sequence.size();
        this->points_sequence = std::move(points_sequence);
    }

    // Copy constructor
    PolyLine(const PolyLine &pl) {
        this->points_amount = pl.points_amount;
        this->points_sequence = pl.points_sequence;
    }

    // Assignment operator
    PolyLine &operator=(const PolyLine &pl) {
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


#endif //LAB1_CPP_POLYLINE_H
