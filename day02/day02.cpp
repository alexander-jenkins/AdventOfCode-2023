//
// Created by Alexander Jenkins on 12/22/23.
//

#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include "day02.h"

void day02::part01(const std::string &INPUT) {
    constexpr int MAX_RED = 12;
    constexpr int MAX_GREEN = 13;
    constexpr int MAX_BLUE = 14;

    int sum = 0;

    std::regex gameIdRegex("(\\d+)(?=:)");
    std::regex redRegex("(\\d+)(?= red)");
    std::regex greenRegex("(\\d+)(?= green)");
    std::regex blueRegex("(\\d+)(?= blue)");

    // read each line
    std::ifstream gameFile(INPUT);
    std::string line;
    while (getline(gameFile, line)) {

        // get the id of the game
        std::smatch regexMatches;
        std::regex_search(line, regexMatches, gameIdRegex);
        int currentGameId = stoi(regexMatches.str());

        // delete the game ID from the line in memory
        line = line.substr(line.find(':') + 2);

        // make a list of all the games in memory
        std::vector<std::string> games;
        while (!line.empty()) {
            // if there are more than one round, grab the current one
            if (line.find(';') != std::string::npos) {
                auto idx = line.find(';');
                games.push_back(line.substr(0, idx + 1));
                line.erase(0, idx + 1);
                continue;
            }
            games.push_back(line);
            line.erase(0);
        }

        // parse each game in the line to see if it is valid
        bool pass = true;
        for (const std::string &currentGame: games) {
            int red, green, blue;

            std::regex_search(currentGame, regexMatches, redRegex);
            red = !regexMatches.empty() ? stoi(regexMatches.str()) : 0;

            std::regex_search(currentGame, regexMatches, greenRegex);
            green = !regexMatches.empty() ? stoi(regexMatches.str()) : 0;

            std::regex_search(currentGame, regexMatches, blueRegex);
            blue = !regexMatches.empty() ? stoi(regexMatches.str()) : 0;

            if ((red > MAX_RED) || (green > MAX_GREEN) || (blue > MAX_BLUE) ||
                ((red + green + blue) > (MAX_RED + MAX_GREEN + MAX_BLUE))) {
                pass = false;
                break;
            }
        }

        if (pass)
            sum += currentGameId;

    }
    gameFile.close();
    std::cout << "Day 02 Part 01: " << sum << std::endl;
}