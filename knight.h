#pragma once
#include "piece.h"
class Knight : public Piece
{
public:
    Knight(Color c, int r, int cy) : Piece(c, r, cy) {}
    char getSymbol() const override;
    bool isValidMove(int toRow, int toCol, Piece* board[8][8]) override;
}; 
