#pragma once                            
enum Color { WHITE, BLACK, NONE };
// abstract class with no object
class Piece 
{
protected:
    Color color;
    int row, col;
    public:
    Piece(Color c, int r, int cy);
    virtual ~Piece();

    // Pure virtual functions (Polymorphism)

    // virtual function 
    virtual char getSymbol() const = 0; 
    // will define movement reules 
    virtual bool isValidMove(int toRow, int toCol, Piece* board[8][8]) = 0;

    Color getColor() const;
    void setPosition(int r, int c);
};