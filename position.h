/***********************************************************************
 * Header File:
 *    POSITION
 * Author:
 *    <your name here>
 * Summary:
 *    The position of a piece, the cursor, or a possible move on a chess board
 ************************************************************************/

#pragma once

#include <string>
#include <cassert>
#include <cstdint>
using std::string;
using std::ostream;
using std::istream;

const int SIZE_SQUARE  = 32;   // number of pixels in a square by default
const int OFFSET_BOARD = 50;   // boarder between the board and the edge of screen

/***********************************************
 * DELTA
 * Movement in a direction (dRow and dCol)
 **********************************************/
struct Delta
{
   int dRow;
   int dCol;
};

const Delta ADD_R = { 1,  0};
const Delta ADD_C = { 0,  1};
const Delta SUB_R = {-1,  0};
const Delta SUB_C = { 0, -1};


class PositionTest;
class TestMove;
class TestBoard;

/***************************************************
 * POSITION
 * The location of a piece on the board
 ***************************************************/
class Position
{
   friend class PositionTest;
   friend class TestMove;
   friend class TestBoard;
public:

   // Position :    The Position class can work with other positions,
   //               Allowing for comparisions, copying, etc.
   Position(const Position & rhs) { this->colRow = rhs.colRow;    }
   Position() : colRow(0x99)      {                               }
   bool isInvalid() const         { return (bool)(colRow & 0x88); }
   bool isValid()   const         { return !isInvalid();          }
   void setValid()                {                               }
   void setInvalid()              {                               }
   bool operator <  (const Position & rhs) const { return this->colRow < rhs.colRow; }
   bool operator == (const Position & rhs) const { return this->colRow == rhs.colRow; }
   bool operator != (const Position & rhs) const { return this->colRow != rhs.colRow; }
   const Position & operator = (const Position & rhs) { colRow = rhs.colRow; return *this; }
   
   // Location : The Position class can work with locations, which
   //            are 0...63 where we start in row 0, then row 1, etc.
   Position(int location) : colRow(0x99) {                                 }
   int getLocation() const               { return getRow() * 8 + getCol(); }
   void setLocation(int location)        {                                 }

   
   // Row/Col : The position class can work with row/column,
   //           which are 0..7 and 0...7
   Position(int c, int r)                 { set(c, r); }
   virtual int getCol() const             { return isValid() ? (int)((colRow & 0xf0) >> 4) : -1; }
   virtual int getRow() const             { return isValid() ? (int)((colRow & 0x0f) >> 0) : -1; }
   void setRow(int r)                     { colRow = (colRow & 0xf0) | (r << 0); if (isInvalid()) colRow = 0xff; }
   void setCol(int c)                     { colRow = (colRow & 0x0f) | (c << 4); if (isInvalid()) colRow = 0xff; }
   void set(int c, int r) {
      colRow = (colRow & 0x0f) | (c << 4);
      colRow = (colRow & 0xf0) | (r << 0);
      if (isInvalid())
         colRow = 0xff;
   }

   // Text:    The Position class can work with textual coordinates,
   //          such as "d4"
   
   Position(const char * s);
   const Position & operator = (const char* rhs);
   const Position & operator = (const string& rhs);

   
   // Pixels:    The Position class can work with screen coordinates,
   //            a.k.a. Pixels, these are X and Y coordinates. Note that
   //            we need to scale them according to the size of the board.
   int getX()   const { return 99; }
   int getY()   const { return 99; }
   void setXY(double x, double y) { }
   double getSquareWidth()  const { return 99; }
   double getSquareHeight() const { return 99; }
   void setSquareWidth (double width )  {  }
   void setSquareHeight(double height)  {  }

   // Delta:    The Position class can work with deltas, which are
   //           offsets from a given location. This helps pieces move
   //           on the chess board.
   Position(const Position & rhs, const Delta & delta) : colRow(-1) {  }
   void adjustRow(int dRow)   { }
   void adjustCol(int dCol)   { }
   const Position& operator += (const Delta& rhs) {
      setCol(getCol() + rhs.dCol);
      setRow(getRow() + rhs.dRow);
      return *this;
   }
   Position operator + (const Delta & rhs) const { return *this; }

private:
   void set(uint8_t colRowNew) { }
   
   uint8_t colRow;
   static double squareWidth;
   static double squareHeight;
};


ostream & operator << (ostream & out, const Position & pos);
istream & operator >> (istream & in,  Position & pos);
      

class TestMove;

class PositionDummy : public Position
{
   friend class TestMove;
public:
   PositionDummy() : Position()                    {                }
   PositionDummy(const Position& rhs) : Position() { assert(false); }
   PositionDummy(int location) : Position()        { assert(false); }
   PositionDummy(int c, int r) : Position()        { assert(false); }
   PositionDummy(const char * s) : Position()      { assert(false); }
   PositionDummy(const Position & rhs, const Delta & delta) { assert(false); }

   bool isInvalid() const         { assert(false); return false; }
   bool isValid()   const         { assert(false); return false; }
   void setValid()                { assert(false);               }
   void setInvalid()              { assert(false);               }
   int getLocation() const        { assert(false); return 0;     }
   void setLocation(int location) { assert(false);               }

   virtual int getCol() const             { assert(false); return 0; }
   virtual int getRow() const             { assert(false); return 0; }
   void setRow(int r)                     { assert(false);           }
   void setCol(int c)                     { assert(false);           }
   void set(int c, int r)                 { assert(false);           }

   int getX()   const { assert(false); return 0; }
   int getY()   const { assert(false); return 0; }
   void setXY(double x, double y) { assert(false);           }
   double getSquareWidth()  const { assert(false); return 0; }
   double getSquareHeight() const { assert(false); return 0; }
   void setSquareWidth (double width )  { assert(false); }
   void setSquareHeight(double height)  { assert(false); }

   void adjustRow(int dRow)   { assert(false); }
   void adjustCol(int dCol)   { assert(false); }
};
