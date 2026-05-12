#include "pawn.h"
char Pawn::getSymbol() const 
{
    if (color == WHITE)
    return 'P';
    else return 'p';
}
bool Pawn::isValidMove(int toRow, int toCol, Piece* board[8][8])
{
    int dir;
    if (color == WHITE) dir = -1;
    else dir = 1;

    // Standard forward move
    if (toCol == col && toRow == row + dir && board[toRow][toCol] == nullptr) 
    return true;

    // First move 2 steps
    int startRow;
    if (color == WHITE) 
    startRow = 6;
    else 
    startRow = 1;

    if (row == startRow && toCol == col && toRow == row + 2 * dir) 
    {
        if (board[row + dir][col] == nullptr && board[toRow][toCol] == nullptr)
        return true;
    }

    // Capture move
    if (toRow == row + dir && (toCol == col + 1 || toCol == col - 1))
    {
        if (board[toRow][toCol] != nullptr && board[toRow][toCol]->getColor() != color) 
        return true;
    }
    return false;
}