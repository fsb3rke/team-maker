//
// Created by berke on 4/27/2023.
//

#ifndef TEAM_MAKER_TEAM_H
#define TEAM_MAKER_TEAM_H

#include <iostream>
#include "Player.h"

class Team {
public:
    inline std::string getTeamName() { return this->name; };
    inline explicit Team(const std::string& teamName) { this->name = teamName; };
    inline void pushPlayer(const Player& player) { this->players.push_back(player); }
    inline std::vector<Player> getPlayers() { return this->players; }
private:
    std::string name;
    std::vector<Player> players;
};

#endif //TEAM_MAKER_TEAM_H
