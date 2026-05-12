#pragma once
#include "piece.h"
class Pawn : public Piece
{
public:
    Pawn(Color c, int r, int cy) : Piece(c, r, cy) {}
    char getSymbol() const override;
    bool isValidMove(int toRow, int toCol, Piece* board[8][8]) override;
};