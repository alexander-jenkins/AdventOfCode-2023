//
// Created by Alexander Jenkins on 12/22/23.
//

#include <iostream>
#include <fstream>
#include "day02.h"

void day02::part01()
{
    std::ifstream gameFile(INPUT);
    std::vector<Game> games;

    std::string line;
    while (std::getline(gameFile, line))
    {
        int sep = line.find(':');

        int id = std::stoi(line.substr(4, sep));
        games.push_back({id, {}});
    }

    std::cout << "Day 02 Part 01: " << games.size() << std::endl;
}