#include "queen.h"
#include <cmath>
char Queen::getSymbol() const 
{
    if (color == WHITE) return 'Q';
    else return 'q';
}
bool Queen::isValidMove(int toRow, int toCol, Piece* board[8][8]) 
{
    int rDiff = abs(toRow - row);
    int cDiff = abs(toCol - col);
    //ensures the move is either perfectly horizontal, perfectly vertical, or perfectly diagonal
    if (row != toRow && col != toCol && rDiff != cDiff) return false;

    int rStep = 0;
    if (toRow > row) rStep = 1;
    else if (toRow < row) rStep = -1;

    int cStep = 0;
    if (toCol > col) cStep = 1;
    else if (toCol < col) cStep = -1;

    int r = row + rStep;
    int c = col + cStep;
    //the Queen cannot jump. This loop walk from starting square to the target. if it hits any piece (nullptr check) before reaching the destination, the move is blocked.
    while (r != toRow || c != toCol)
    {
        if (board[r][c] != nullptr) return false;
        r += rStep;
        c += cStep;
    }
    if (board[toRow][toCol] == nullptr || board[toRow][toCol]->getColor() != color)
    return true;

    return false;
}