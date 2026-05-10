#include "board.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include <iostream>

using namespace std;

Board::Board()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++) 
        {
            grid[i][j] = nullptr;
        }
    }
}

Board::~Board() 
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++) 
        {
            if (grid[i][j] != nullptr) 
            {
                delete grid[i][j];
                grid[i][j] = nullptr;
            }
        }
    }
}
//It places the Rooks, Knights, Bishops, Queen, and King on the back ranks and fills the second/seventh ranks with Pawns.
void Board::initializeBoard() 
{
    // Explicit placement to increase line count
    grid[0][0] = new Rook(BLACK, 0, 0);
    grid[0][1] = new Knight(BLACK, 0, 1);
    grid[0][2] = new Bishop(BLACK, 0, 2);
    grid[0][3] = new Queen(BLACK, 0, 3);
    grid[0][4] = new King(BLACK, 0, 4);
    grid[0][5] = new Bishop(BLACK, 0, 5);
    grid[0][6] = new Knight(BLACK, 0, 6);
    grid[0][7] = new Rook(BLACK, 0, 7);
    for (int i = 0; i < 8; i++) grid[1][i] = new Pawn(BLACK, 1, i);

    grid[7][0] = new Rook(WHITE, 7, 0);
    grid[7][1] = new Knight(WHITE, 7, 1);
    grid[7][2] = new Bishop(WHITE, 7, 2);
    grid[7][3] = new Queen(WHITE, 7, 3);
    grid[7][4] = new King(WHITE, 7, 4);
    grid[7][5] = new Bishop(WHITE, 7, 5);
    grid[7][6] = new Knight(WHITE, 7, 6);
    grid[7][7] = new Rook(WHITE, 7, 7);
    for (int i = 0; i < 8; i++) grid[6][i] = new Pawn(WHITE, 6, i);
}

void Board::display() const 
{
    cout << endl;
    cout << "      Black Side (lowercase)" << endl;
    cout << "      a   b   c   d   e   f   g   h" << endl;
    cout << "    +---+---+---+---+---+---+---+---+" << endl;

    for (int i = 0; i < 8; i++)
    {
        cout << "  " << i << " | ";
        for (int j = 0; j < 8; j++) 
        {
            if (grid[i][j] == nullptr)
            {
                cout << ". ";
            }
            else 
            {
                cout << grid[i][j]->getSymbol() << " ";
            }
            cout << "| ";
        }
        cout << i << endl;
        cout << "    +---+---+---+---+---+---+---+---+" << endl;
    }

    cout << "      A   B   C   D   E   F   G   H" << endl;
    cout << "      White Side (UPPERCASE)" << endl;
    cout << endl;
}
//helper that scans the board for the King of a specific color and returns its coordinates.
void Board::findKing(Color c, int& kRow, int& kCol) 
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (grid[i][j] != nullptr)
            {
                char s = grid[i][j]->getSymbol();
                if (c == WHITE)
                {
                    if (s == 'K')
                    { kRow = i; kCol = j; return; }
                }
                else 
                {
                    if (s == 'k')
                    { kRow = i; kCol = j; return; }
                }
            }
        }
    }
}
//Finds the King.
//Loops through every piece on the board.
//If it finds an enemy piece, it asks: Is the King's square a valid move for you 
// If yes, the King is in Check.
bool Board::isCheck(Color kingColor) 
{
    int kr = -1, kc = -1;
    findKing(kingColor, kr, kc);
    for (int i = 0; i < 8; i++) 
    {
        for (int j = 0; j < 8; j++)
        {
            Piece* p = grid[i][j];
            if (p != nullptr) 
            {
                if (p->getColor() != kingColor) 
                {
                    if (p->isValidMove(kr, kc, grid)) 
                    { return true; }
                }
            }
        }
    }
    return false;
}
//It tries every possible move for every piece on the current player's side
//It temporarily moves the piece and checks if isCheck is still true
//If it finds even one move that leaves the King safe, it returns true.  If not, it's Checkmate.
bool Board::hasLegalMoves(Color turn)
{
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++)
        {
            Piece* p = grid[r][c];
            if (p != nullptr && p->getColor() == turn) 
            {
                for (int dr = 0; dr < 8; dr++) 
                {
                    for (int dc = 0; dc < 8; dc++) 
                    {
                        if (p->isValidMove(dr, dc, grid)) 
                        {
                            Piece* target = grid[dr][dc];
                            grid[dr][dc] = p;
                            grid[r][c] = nullptr;
                            bool safe = !isCheck(turn);
                            grid[r][c] = p;
                            grid[dr][dc] = target;
                            if (safe) return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}
//Validates the start and end coordinates.
//Checks if the piece belongs to the person whose turn it is.
//It temporarily moves the piece. If that move puts your own King in check (which is illegal in chess), it undoes the move and returns false
bool Board::movePiece(int startR, int startC, int endR, int endC, Color turn) 
{
    if (startR < 0 || startR > 7 || startC < 0 || startC > 7) return false;
    Piece* p = grid[startR][startC];
    if (p == nullptr || p->getColor() != turn) return false;

    if (p->isValidMove(endR, endC, grid)) 
    {
        Piece* target = grid[endR][endC];
        grid[endR][endC] = p;
        grid[startR][startC] = nullptr;

        if (isCheck(turn)) 
        {
            grid[startR][startC] = p;
            grid[endR][endC] = target;
            return false;
        }

        if (target != nullptr) delete target;
        p->setPosition(endR, endC);
        return true;
    }
    return false;
}