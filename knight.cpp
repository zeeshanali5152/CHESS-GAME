#include "knight.h"
#include <cmath>
//The Knight moves in a very specific 2 *1  or 1*2
char Knight::getSymbol() const 
{
    if (color == WHITE) return 'N';
    else return 'n';
}
bool Knight::isValidMove(int toRow, int toCol, Piece* board[8][8]) 
{
    int rDiff = abs(toRow - row);
    int cDiff = abs(toCol - col);
    if ((rDiff == 2 && cDiff == 1) || (rDiff == 1 && cDiff == 2)) 
    {
        if (board[toRow][toCol] == nullptr || board[toRow][toCol]->getColor() != color) return true;
    }
    return false;
}