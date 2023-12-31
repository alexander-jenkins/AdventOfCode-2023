//
// Created by Alexander Jenkins on 12/21/23.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "day01.h"

void day01::part01() {
    std::ifstream inputFile(INPUT);
    std::string line;
    int sum = 0;

    // loop through every line in the input file
    while (std::getline(inputFile, line)) {

        // empty list to hold all the numbers that appear in the string
        std::vector<int> list;

        // linear search thru the line to find all numbers, when found push to the list
        for (char c : line)
            if (isnumber(c)) list.push_back(c - '0');

        // add the calibration value of the line to the sum of all calibration values
        sum += (list.front() * 10) + list.back();
    }

    // housekeeping
    inputFile.close();

    std::cout << "Day 01 Part 01: " << sum << std::endl;
}

void day01::part02() {
    std::ifstream inputFile(INPUT);
    std::string line;
    int sum = 0;

    while (std::getline(inputFile, line)) {
        std::vector<int> numbers;

        // loop over each char
        for (int i = 0; i < line.length(); i++) {

            // look forward
            for (int j = 0; (j < line.length() && j <= 5); j++) {

                if (isdigit(line[j])) {
                    numbers.push_back(line[j] - '0');
                    break;
                }
            }
        }
    }

    inputFile.close();
    std::cout << "Day 01 Part 02: " << sum << std::endl;
}