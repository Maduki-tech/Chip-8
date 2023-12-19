#include "includes/chip8.h"
#include <cstdint>
#include <iostream>
#include <random>
int main(int argc, char *argv[]) {
    Chip8 chip8;
    std::uniform_int_distribution<uint8_t> test = chip8.randByte;
    std::cout << "test: " << (int)test(chip8.randomGen) << std::endl;

    std::cout << "Hello World!" << std::endl;
    return 0;
}
