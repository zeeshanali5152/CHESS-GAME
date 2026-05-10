#pragma once
#include "piece.h"

class Board 
{
private:
// 2d array of pointers
    Piece* grid[8][8];

public:
    Board();
    ~Board();
    //Sets up the starting position—placing Pawns on the second/seventh ranks and the power pieces on the back ranks.
    void initializeBoard();
    void display() const;

    // Game Rules logic
    bool movePiece(int startR, int startC, int endR, int endC, Color turn);
    bool isCheck(Color kingColor);
    bool hasLegalMoves(Color turn);
    void findKing(Color c, int& kRow, int& kCol);
};