#include <iostream>
#include <cstdlib>
#include "board.h"

using namespace std;

int main() 
{
    Board game;
    game.initializeBoard();
    Color turn = WHITE;

    while (true) 
    {
        system("cls");
        cout << "----------------------------------------" << endl;
        cout << "                CHESS GAME              " << endl;
        cout << "----------------------------------------" << endl;

        game.display();

        bool inCheck = game.isCheck(turn);
        bool canMove = game.hasLegalMoves(turn);

        if (inCheck == true) 
        {
            if (canMove == false) 
            {
                cout << "\n>>> RESULT: CHECKMATE! " << (turn == WHITE ? "BLACK WINS!" : "WHITE WINS!") << endl;
                break;
            }
            cout << "\n [!] ATTENTION: YOUR KING IS IN CHECK" << endl;
        }
        else if (canMove == false)
        {
            cout << "\n>>> RESULT: STALEMATE (DRAW)" << endl;
            break;
        }

        char sCol, eCol;
        int sRow, eRow;

        if (turn == WHITE) 
        {
            cout << "\n WHITE PLAYER (UPPERCASE A-H)" << endl;
            cout << " Enter move (e.g., E 6 E 4) or 'Q' to quit: ";
        }
        else 
        {
            cout << "\n BLACK PLAYER (lowercase a-h)" << endl;
            cout << " Enter move (e.g., e 1 e 3) or 'q' to quit: ";
        }

        cin >> sCol;
        if ((turn == WHITE && sCol == 'Q') || (turn == BLACK && sCol == 'q'))
        {
            cout << "\n Exiting game..." << endl;
            break;
        }

        cin >> sRow >> eCol >> eRow;

        int sc = -1, ec = -1;
        bool validCase = false;

        if (turn == WHITE)
        {
            if (sCol >= 'A' && sCol <= 'H' && eCol >= 'A' && eCol <= 'H') 
            {
                sc = sCol - 'A'; ec = eCol - 'A'; validCase = true;
            }
        }
        else
        {
            if (sCol >= 'a' && sCol <= 'h' && eCol >= 'a' && eCol <= 'h')
            {
                sc = sCol - 'a'; ec = eCol - 'a'; validCase = true;
            }
        }

        if (validCase == true && game.movePiece(sRow, sc, eRow, ec, turn)) 
        {
            turn = (turn == WHITE) ? BLACK : WHITE;
        }
        else
        {
            cout << "\n  Error: Invalid Move or Case. Press Enter...";
            cin.ignore(); cin.get();
        }
    }
    return 0;
}