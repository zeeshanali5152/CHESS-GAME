#include "bishop.h"
#include <cmath>
char Bishop::getSymbol() const          // move diagonally
{ 
// return B for white and b for black 
    if (color == WHITE) return 'B';
    else return 'b';
}
bool Bishop::isValidMove(int toRow, int toCol, Piece* board[8][8])
{   // to calculate vertical and horizontal distance
    if (abs(toRow - row) != abs(toCol - col)) return false;

    int rStep;
    if (toRow > row) rStep = 1;
    else rStep = -1;

    int cStep;
    if (toCol > col) cStep = 1;
    else cStep = -1;

    int r = row + rStep;
    int c = col + cStep;
    // to see if the path is clear or not --- as it cannot move over pieces
    while (r != toRow) 
    {
        if (board[r][c] != nullptr) return false;
        r += rStep;
        c += cStep;
    }
    // it will return true if the target is empty
    if (board[toRow][toCol] == nullptr || board[toRow][toCol]->getColor() != color) return true;
    return false;
}