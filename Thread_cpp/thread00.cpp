/**
 * This part of course of Udemy Cpp Eng by Franneck94
 */

#include <array>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <thread>
#include <chrono>

constexpr static auto NUM_THREADS = std::uint32_t{3};

void worker(const std::int32_t input, std::int32_t &output) {
    std::cout << "Called worker from Thread: " << std::this_thread::get_id() << std::endl;
    output = input * 2;
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

int main(int argc, char** argv) 
{
    auto inputs = std::array<std::int32_t, NUM_THREADS>{};
    std::iota(inputs.begin(), inputs.end(), 0);

    auto outputs = std::array<std::int32_t, NUM_THREADS>{};
    std::fill(outputs.begin(), outputs.end(), 0);
    
    std::cout << "Main Thread ID: " << std::this_thread::get_id() << std::endl;

    std::array<std::thread, NUM_THREADS> threads;
    for (std::int32_t i = 0; i < NUM_THREADS; ++i) {
        threads[i] = std::thread(worker, inputs[i], std::ref(outputs[i]));
    }

    //

    for (std::uint32_t i = 0; i < NUM_THREADS; ++i) {
        threads[i].join();
    } 
    for (std::uint32_t i = 0; i < NUM_THREADS; ++i)
    {
        std::cout << "Outputs[" << i << "] = " << outputs[i] << std::endl;
    }

    return 0;
}