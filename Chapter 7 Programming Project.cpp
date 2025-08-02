//program that shows the number of times that a team from Teams.txt has won the worls series in
//the time period from 1903 to 2012.
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib> //for exit function
#include<iomanip> //for formatting
#include <iostream>
using namespace std;

//defining function prototypes
void getTeams(const string& fileName, vector<string>& teamList);

int findWinner(const string& teamName, const vector<string>& winnersList);


int main()
{
    std::vector<std::string> teamsList;
    std::vector<std::string> winnersList;

    string teamsFileName;
    string winnersFileName;

    std::cout << "Enter the full name for the teams list: ";
    getline(cin, teamsFileName);
    std::cout << "Enter the full name for the winners list: ";
    getline(cin, winnersFileName);
    
    getTeams(teamsFileName, teamsList);
    getTeams(winnersFileName, winnersList);

    //display all names of teams
    std::cout << "Team Names: \n";
    for (const string& team : teamsList) {
        std::cout << team << '\n';
    }
    std::cout << '\n';

    std::string userInput;
    std::cout << "Pick a team (enter quit to end):\n";
    getline(cin, userInput);
    std::cout << '\n';

    while (userInput != "quit") {
        int winCount = findWinner(userInput, winnersList);
        std::cout << userInput << " won the World Series " << winCount << " times.\n";

        std::cout << "Pick a team (enter quit to end):\n";
        getline(cin, userInput);
        std::cout << '\n';
    }

    return 0;
}

void getTeams(const string& fileName, vector<string>& teamList) {
    std::ifstream file(fileName);

    if (!file) {
        std::cerr << "Error: couldn't open file " << fileName << '\n';
        exit(1);
    }

    std::string temp;
    while (getline(file, temp)) {
        if (!temp.empty()) {
            teamList.push_back(temp);
        }
    }

    file.close();
}

int findWinner(const string& teamName, const vector<string>& winnersList) {
    int count = 0;
    for (const string& winner : winnersList) {
        if (winner == teamName) {
            ++count;
        }
    }
    return count;
}