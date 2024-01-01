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
        for (char c: line)
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

    // loop through every line in the input file
    while (std::getline(inputFile, line)) {

        // empty list to hold all the numbers that appear in the string
        std::vector<int> list;

        // linear search thru the line to find all numbers, when found push to the list
        for (int i = 0; i < line.length(); i++) {
            // get the current character
            char c = line.at(i);
            int numLeft = line.length() - i;

            // if the character is a number, add to the list and go to the next iteration of the loop
            if (isnumber(c)) {
                list.push_back(c - '0');
                continue;
            }

                // if not, check to see if the next few characters spell out a number
            else {
                // check if this letter is even the start of a valid word
                switch (c) {
                    case 'o':
                        if (numLeft >= 2) {
                            std::string slice = line.substr(i, 3);
                            if (slice == "one") list.push_back(1);
                        }
                        break;

                    case 't':
                        if (numLeft >= 2) {
                            std::string slice = line.substr(i, 3);
                            std::string slice2 = line.substr(i, 5);
                            if (slice == "two") list.push_back(2);
                            if (slice2 == "three") list.push_back(3);
                        }
                        break;

                    case 'f':
                        if (numLeft >= 4) {
                            std::string slice = line.substr(i, 4);
                            if (slice == "four") list.push_back(4);
                            if (slice == "five") list.push_back(5);
                        }
                        break;

                    case 's':
                        if (numLeft >= 3) {
                            std::string slice = line.substr(i, 5);
                            std::string slice2 = line.substr(i, 3);
                            if (slice == "seven") list.push_back(7);
                            if (slice2 == "six") list.push_back(6);
                        }
                        break;

                    case 'e':
                        if (numLeft >= 4) {
                            std::string slice = line.substr(i, 5);
                            if (slice == "eight") list.push_back(8);
                        }
                        break;

                    case 'n':
                        if (numLeft >= 3) {
                            std::string slice = line.substr(i, 4);
                            if (slice == "nine") list.push_back(9);
                        }
                        break;

                    default:
                        continue;
                }
            }
        }

        // add the calibration value of the line to the sum of all calibration values
        sum += (list.front() * 10) + list.back();
    }

    // housekeeping
    inputFile.close();
    std::cout << "Day 01 Part 02: " << sum << std::endl;
}