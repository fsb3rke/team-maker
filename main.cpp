#include <iostream>
#include <vector>
#include "header/Player.h"
#include "header/Team.h"
#include "tabulate/tabulate.hpp"
#include <cstdlib>
#include <conio.h>

using namespace tabulate;
// inline void add_cell_to_table(Table table, int row, std::string item) { table[row].add_cell((const std::shared_ptr<tabulate::Cell> &) std::move(item)); }


std::vector<Player> inputPlayers(const int& playerSize);
std::vector<Team> inputTeams(const int& teamSize);


int main() {
    srand((unsigned) time(nullptr));

    int playerSize, teamSize;
    std::cout << "Player Size: "; std::cin >> playerSize;
    std::cout << "Team Size: "; std::cin >> teamSize;
    std::vector<Team> teams = inputTeams(teamSize);
    std::vector<Player> players = inputPlayers(playerSize);

    int teamIndex;
    teamIndex = 0;
    while (!players.empty()) {
        if (teamIndex > teamSize-1) teamIndex = 0;

        // Select a random player for emplace to the team which as we have selected randomly
        int randPlayerIndex = rand() % players.size();

        teams.at(teamIndex)
            .pushPlayer(
                    players.at(randPlayerIndex)
                    );

        // Delete to the selected player from players vector
        players.erase(players.begin() + randPlayerIndex);

        teamIndex++;
    }


    // CREATING TO THE TEAM TABLE
    Table teamTable;

    // teamTable.add_row({});
    for (Team& team : teams) {
        // add_cell_to_table(teamTable, 0, team.getTeamName());
        teamTable.add_row({ team.getTeamName() });
        for (Player& player : team.getPlayers()) {
            teamTable.add_row({ player.getPlayerName() });
        }

        std::cout << teamTable << std::endl;
        teamTable = *new Table;
    }

    std::cout << "\n\n\n\nPress any key to close to the program...";
    getch();
    return 0;
}

std::vector<Player> inputPlayers(const int& playerSize) {
    std::vector<Player> players;
    for (int i = 0; i < playerSize; i++) {
        std::string playerName;
        std::cout << "Player " << (i+1) << " : ";
        std::cin >> playerName;
        Player pushPlayer(playerName);
        players.push_back(pushPlayer);
    }

    return players;
}

std::vector<Team> inputTeams(const int& teamSize) {
    std::vector<Team> teams;
    for (int i = 0; i < teamSize; i++) {
        std::string teamName;
        std::cout << "Team " << (i+1) << " : ";
        std::cin >> teamName;
        Team pushTeam(teamName);
        teams.push_back(pushTeam);
    }

    return teams;
}