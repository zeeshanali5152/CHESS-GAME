#include "king.h"
#include <cmath>
char King::getSymbol() const 
{       // returns K for white and k for black
    if (color == WHITE) return 'K';
    else return 'k';
}
bool King::isValidMove(int toRow, int toCol, Piece* board[8][8]) 
{
    int rDiff = abs(toRow - row);
    int cDiff = abs(toCol - col);
   // if both are 1 or 0 (but not both 0), 
   //it means the King is moving exactly one square in any direction(vertically, horizontally, or diagonally).
    if (rDiff <= 1 && cDiff <= 1)
    {
        if (board[toRow][toCol] == nullptr || board[toRow][toCol]->getColor() != color) return true;
    }
    return false;
}