#ifndef GAME_HPP
#define GAME_HPP

#include "Snake.hpp"
#include <atomic>
#include <thread>
#include <random>

class Game {
    public:
        Game();
        // Destructor, good practice
        ~Game() = default;

        // Main loop, runs game
        void run();
    private:
        void render();
        void update_logic();
        void process_input();
        void spawn_food();

        // Game State
        Snake snake;
        Point food;

        // std::atomic ensures thread safety
        // between the input thread and game thread
        std::atomic<bool> is_runnig;
        
        const int width = 20;
        const int height = 10;

        std::mt19937 rng;
}

#endif

