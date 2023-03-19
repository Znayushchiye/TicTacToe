#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>

class TicTacToe
{
private:
    int randomNumber();

public:
    bool alreadyTaken(char position[9], int n);
    bool hasWon(char position[9]);
    void humanTurn(char (*position)[9], int n);
    void computerTurn(char (*position)[9]);
    void printTable(char (*position)[9]);
    void winParty(char position[9]);
};
int TicTacToe::randomNumber() // Works Perfectly
{
    int random = (rand() * 10000) % 9;
    return random;
}
bool TicTacToe::alreadyTaken(char position[9], int n) // Works Perfectly
{
    if (position[n] == 'X' || position[n] == 'O')
        return true;
    return false;
}
bool TicTacToe::hasWon(char position[9])
{
    for (int i = 0; i < 3; i++)
        if (position[i] == position[i + 3] && position[i + 3] == position[i + 6])
            return true;
    for (int i = 0; i < 9; i += 3)
        if (position[i] == position[i + 1] && position[i + 1] == position[i + 2])
            return true;
    if ((position[0] == position[4] && position[4] == position[8]) || (position[2] == position[4] && position[4] == position[6]))
        return true;
    return false;
}
void TicTacToe::humanTurn(char (*position)[9], int n) // Works Perfectly
{
    (*position)[n - 1] = 'X';
}
void TicTacToe::computerTurn(char (*position)[9]) // Works Perfectly
{
    int random;
    do
    {
        random = randomNumber();
    } while (alreadyTaken(*position, random));
    (*position)[random - 1] = 'O';
}
void TicTacToe::printTable(char (*position)[9])
{
    std::cout << " " << (*position)[0] << " | " << (*position)[1] << " | " << (*position)[2] << "\n";
    std::cout << "___|___|__\n";
    std::cout << " " << (*position)[3] << " | " << (*position)[4] << " | " << (*position)[5] << "\n";
    std::cout << "___|___|__\n";
    std::cout << " " << (*position)[6] << " | " << (*position)[7] << " | " << (*position)[8] << "\n";
    std::cout << "   |   |\n";
}
void TicTacToe::winParty(char position[9])
{
    char winner;
    for (int i = 0; i < 3; i++)
        if (position[i] == position[i + 3] && position[i + 3] == position[i + 6])
            winner = position[i];
    for (int i = 0; i < 9; i += 3)
        if (position[i] == position[i + 1] && position[i + 1] == position[i + 2])
            winner = position[i];
    if (position[0] == position[4] && position[4] == position[8])
        winner = position[0];
    if (position[2] == position[4] && position[4] == position[6])
        winner = position[2];
    if (winner == 'X')
        std::cout << "\n\nCongratulations! You win the match! \n";
    else
        std::cout << "\n\nYou lost the game :-C \n";
}

int main()
{
    char position[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    srand(time(0));
    // TicTacToe game;
    // game.computerTurn(&position);
    // game.printTable(&position);
    // return 0;

    std::string start;

    std::cout << "------------------------------------------\n";
    std::cout << "Tic-Tac-Toe Game\n";
    std::cout << "You choose 'X' and the computer chooses 'O'.\n";
    std::cout << "Whomever gets 3 in a row, column or diagonally correct, wins.\n";
    std::cout << "Do you want to begin? (y/n)\n";
    std::cin >> start;

    if (std::toupper(start.at(0)) == 'Y')
    {
        TicTacToe game;
        int count = 0;
        do
        {
            count++;
            system("cls");
            std::cout << "------------------------------------------\n";
            std::cout << ((count != 1) ? ("Current Table:\n\n") : ("Game start\n\n"));
            game.printTable(&position);
            int choice;
            do
            {
                std::cout << "\n\nEnter your choice : ";
                std::cin >> choice;
                if (game.alreadyTaken(position, choice))
                {
                    std::cout << "\nWrong choice! Enter another.\n";
                    continue;
                }
            } while (false);
            game.humanTurn(&position, choice);
            game.computerTurn(&position);
            std::cout << "------------------------------------------\n";
        } while (!game.hasWon(position));
        system("cls");
        std::cout << "------------------------------------------\n";
        std::cout << "Final Table:\n\n";
        game.printTable(&position);
        game.winParty(position);
        std::cout << "------------------------------------------\n";
    }
    else
    {
        std::cout << "Fin.\n";
        std::cout << "------------------------------------------\n";
    }
    return 0;
}