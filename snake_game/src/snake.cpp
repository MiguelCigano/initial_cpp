#include "snake.hpp"
#include <iostream>


Snake::Snake() {
    body.push_back({10, 10});
    body.push_back({10, 11});
    body.push_back({10, 12});

    direction = Direction::UP;
}

void Snake::move() {
    Point new_head = body.front();

    switch (direction) {
        case Direction::UP: new_head.y--; break;
        case Direction::DOWN: new_head.y++; break;
        case Direction::LEFT: new_head.x--; break;
        case Direction::RIGHT: new_head.x++; break;
    }

    // Move Logic, add new head at the front
    body.push_front(new_head);

    // Remove the last part of the tail to mantain length
    body.pop_back();
}

void Snake::grow() {
    Point new_head = body.front();

    switch (direction) {
        case Direction::UP: new_head.y--; break;
        case Direction::DOWN: new_head.y++; break;
        case Direction::LEFT: new_head.x--; break;
        case Direction::RIGHT: new_head.x++; break;
    }

    // To grow, we push a new head but we do not pop the back
    body.push_front(new_head);
}
