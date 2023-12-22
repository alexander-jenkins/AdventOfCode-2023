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

    while (std::getline(inputFile, line)) {
        int first = line[line.find_first_of("123456789")] - '0';
        int last = line[line.find_last_of("123456789")] - '0';
        int calibrationValue = (first * 10) + last;
        sum += calibrationValue;
    }

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