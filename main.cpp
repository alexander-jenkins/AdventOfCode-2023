#include <iostream>
#include "day01/day01.h"
#include "day02/day02.h"

int main() {
    std::cout << "---- Advent of Code ----" << std::endl;

    // Day 01
    day01::part01("../inputs/day01.txt");
    day01::part02("../inputs/day01.txt");

    // Day 02
    day02::part01("../inputs/day02.txt");

    return 0;
}
