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
    DOOR
};

class Cell {
public:
    Point uL;
    Point uR;
    Condition condition;
    /*int gridColumn;
    int gridRow;*/

    Cell(){}
};