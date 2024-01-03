//
// Created by Alexander Jenkins on 12/22/23.
//

#include <iostream>
#include <fstream>
#include <regex>
#include "day02.h"

void day02::part01()
{
    constexpr int MAX_RED = 12;
    constexpr int MAX_GREEN = 13;
    constexpr int MAX_BLUE = 14;

    std::ifstream gameFile("../inputs/day02_part01.txt");
    std::string line;

    std::regex gameIdRegex("/(\\d+)(?=:)/g");

    int sum = 0;

    // read each line
    while(getline(gameFile, line)) {

        // get the id of the game
        std::regex_iterator matches(line.begin(), line.end(), gameIdRegex);
        std::cout << 1 << matches.str() << "\n";

        std::cout << line << "\n";
    }
    gameFile.close();


    std::cout << "Day 02 Part 01: " << 0 << std::endl;
}