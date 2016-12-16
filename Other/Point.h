#pragma once;

#include <cmath>

struct Point {
    int x;
    int y;

    Point() {};
    Point(int x, int y) : x(x), y(y) {}
    /*Point(Point const& point) : x(point.x), y(point.y) {}
    Point&operator=(Point const& point) {
        x = point.x;
        y = point.y;
        return *this;
    }*/
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
    Point* uL;
    Point* uR;
    Condition condition;

    Cell() {};
    Cell(Point* a, Point* b, Condition c) : uL(a), uR(b), condition(c) {}
    /*Cell(Cell const& cell) : uL(cell.uL), uR(cell.uR), condition(cell.condition) {}
    Cell&operator=(Cell const& cell) {
        uL = cell.uL;
        uR = cell.uR;
        condition = cell.condition;
        return *this;
    }*/
};