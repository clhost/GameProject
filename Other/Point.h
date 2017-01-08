#pragma once;

#include <cmath>

struct Point {
    int x;
    int y;

    Point() {};
    Point(int x, int y) : x(x), y(y) {}
};

enum Condition {
    PASSABLE,
    IMPASSABLE,
    DOOR,
    FOOD,
    SUPERFOOD
};

class Cell {
public:
    Point uL;
    Point uR;
    Condition condition;

    Cell() {};
    Cell(Point a, Point b, Condition c) : uL(a), uR(b), condition(c) {}
};