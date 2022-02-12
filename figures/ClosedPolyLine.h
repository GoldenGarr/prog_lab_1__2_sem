#ifndef LAB1_CPP_CLOSEDPOLYLINE_H
#define LAB1_CPP_CLOSEDPOLYLINE_H

#include <utility>
#include <vector>
#include "Point.h"

class ClosedPolyLine {
private:
    std::vector<Point> points_sequence;
public:
    // Default constructor
    ClosedPolyLine() : points_sequence() {}

    // Constructor
    ClosedPolyLine(std::vector<Point> points_sequence) {
        if (!isValid())
            throw std::invalid_argument("Closed Polyline's first Point has to be equal to the last Point");
        this->points_sequence = std::move(points_sequence);
    }

    // Copy constructor
    ClosedPolyLine(const ClosedPolyLine &pl) {
        this->points_sequence = pl.points_sequence;
    }

    // Assignment operator
    ClosedPolyLine &operator=(const ClosedPolyLine &pl) {
        if (this != &pl) {
            this->points_sequence = pl.getPointsSequence();
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

    bool isValid() {
        return points_sequence[0] == points_sequence[points_sequence.size() - 1];
    }

    const std::vector<Point> &getPointsSequence() const {
        return points_sequence;
    }

    void setPointsSequence(const std::vector<Point> &pointsSequence) {
        points_sequence = pointsSequence;
    }
};


#endif //LAB1_CPP_CLOSEDPOLYLINE_H
