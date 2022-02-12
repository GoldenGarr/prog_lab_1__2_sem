#include <iostream>
#include "figures/Point.h"
#include "figures/PolyLine.h"
#include "figures/Triangle.h"


void print_vec(std::vector<Point> vec) {
    for (auto & i : vec) {
        std::cout << "(" << i.getX() << ", " << i.getY() << "), ";
    }
    std::cout << std::endl;
}


void point_test() {
    // Default
    Point p1;
    std::cout << p1.getX() << ", " << p1.getY() << std::endl;

    // Constructor
    Point p2(100.1, 200.2);
    std::cout << p2.getX() << ", " << p2.getY() << std::endl;

    // Copy
    Point p3(p2);
    std::cout << p3.getX() << ", " << p3.getY() << std::endl;

    // Assignment
    Point p4 = p2;
    std::cout << p4.getX() << ", " << p4.getY() << std::endl;

}


void polyLine_test() {
    Point p1;
    Point p2(1.1, 2.2);
    Point p3(3.3, 4.4);

    // Default
    PolyLine default_pl;
    std::cout << default_pl.getPointsAmount() << "; ";
    print_vec(default_pl.getPointsSequence());
}


int main() {
    // point_test();
    // polyLine_test();
    Point p1(0, 0);
    Point p2(3, 0);
    Point p3(0, 4);
    std::vector<Point> vec;
    vec.push_back(p1);
    vec.push_back(p2);
    vec.push_back(p3);
    Triangle tr(vec);
    Triangle tr2 = tr;
    std::cout << tr.getSpace();
    return 0;
}
