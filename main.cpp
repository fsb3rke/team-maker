#include <iostream>
#include <vector>
#include "header/Player.h"
#include "header/Team.h"
#include "tabulate/tabulate.hpp"
#include <cstdlib>
#include <conio.h>

using namespace tabulate;
// inline void add_cell_to_table(Table table, int row, std::string item) { table[row].add_cell((const std::shared_ptr<tabulate::Cell> &) std::move(item)); }
#define EXIT_WITH_MESSAGE(condition, code, msg) \
    if (!(condition)) {                                         \
        std::cout<<msg<<std::endl; \
        std::cout << "\n\n\n\nPress any key to close to the program..."; \
        getch();                                       \
        std::exit(code);                        \
    }


// TODO: SOLVE DEMANGLING PROBLEM
template<typename T>
std::vector<T> input(const int& size) {
    std::vector<T> vv;
    for (int i = 0; i < size; ++i) {
        std::string vvName;
        std::cout << typeid(T).name() << " " << (i+1) << " : ";
        std::cin >> vvName;
        T pushVv(vvName);
        vv.push_back(pushVv);
    }
    return vv;
}

int main() {
    srand(((unsigned) time(nullptr)));

    int playerSize, teamSize;
    std::cout << "Player Size: "; std::cin >> playerSize;
    std::cout << "Team Size: "; std::cin >> teamSize;

    // assert(playerSize < teamSize && "Team Size must be higher than Player Size");
    EXIT_WITH_MESSAGE(playerSize <= teamSize, -1, "Team Size must be higher than Player Size");

    std::vector<Team> teams = input<Team>(teamSize);
    std::vector<Player> players = input<Player>(playerSize);

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
        teamTable[0].format()
            .font_color(Color::blue);
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
