#pragma once
#include "piece.h"
class Bishop : public Piece         // will move diagonally
{
public:
// constructor
    Bishop(Color c, int r, int cy) : Piece(c, r, cy) {}
    // retur  specific char to represent the bisshop on borad
    char getSymbol() const override;
    // diagonal logic 
    bool isValidMove(int toRow, int toCol, Piece* board[8][8]) override;
};