//
// Created by Alexander Jenkins on 12/22/23.
//

#ifndef ADVENTOFCODE_DAY02_H
#define ADVENTOFCODE_DAY02_H

namespace day02 {
    void part01(const std::string& INPUT);
    void part02(std::string INPUT);

    struct Result
    {
        int red;
        int green;
        int blue;
    };

    struct GameID
    {
        int id;
    };

    struct Game
    {
        GameID id;
        Result rolls;
    };

}

#endif //ADVENTOFCODE_DAY02_H
