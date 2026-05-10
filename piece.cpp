#include "piece.h"                          // done-----
// construcutr to set color and row, column
Piece::Piece(Color c, int r, int cy)
{
    color = c;
    row = r;
    col = cy;
}

Piece::~Piece() {}
// to determine whose turn is 
Color Piece::getColor() const
{
    return color;
}
// move the piece   set the new position for piece on board
void Piece::setPosition(int r, int c) 
{
    row = r;
    col = c;
}