#include "rook.h"
char Rook::getSymbol() const 
{
    if (color == WHITE) return 'R';
    else return 'r';
}
bool Rook::isValidMove(int toRow, int toCol, Piece* board[8][8])
{
    if (row != toRow && col != toCol) return false;

    int rStep = 0;
    if (toRow > row) rStep = 1;
    else if (toRow < row) rStep = -1;

    int cStep = 0;
    if (toCol > col) cStep = 1;
    else if (toCol < col) cStep = -1;

    int r = row + rStep;
    int c = col + cStep;
    while (r != toRow || c != toCol)
    {
        if (board[r][c] != nullptr) return false;
        r += rStep;
        c += cStep;
    }

    if (board[toRow][toCol] == nullptr || board[toRow][toCol]->getColor() != color) return true;
    return false;
}