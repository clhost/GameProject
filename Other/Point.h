#pragma once;

#include <cmath>

struct Point {
    int x;
    int y;

    //Point(int x, int y) : x(x), y(y) {}
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

    Cell(){}
};