#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <deque>
#include <compare> 

enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct Point {
    int x;
    int y;

    bool is_equal(const Point &other) const {
        return x == other.x && y == other.y;
    }
};

class Snake {
    public:
        Snake();
        void move();
        void grow();

        std::deque<Point> body;
        Direction direction;
};

#endif
