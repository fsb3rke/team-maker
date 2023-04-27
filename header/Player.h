//
// Created by berke on 4/27/2023.
//

#ifndef TEAM_MAKER_PLAYER_H
#define TEAM_MAKER_PLAYER_H

#include <iostream>
#include <utility>

class Player {
public:
    inline std::string getPlayerName() { return this->name; };
    inline explicit Player(const std::string& playerName) { this->name = playerName; }

private:
    std::string name;
};

#endif //TEAM_MAKER_PLAYER_H
