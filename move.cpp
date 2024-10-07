/***********************************************************************
 * Source File:
 *    MOVE 
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about a single chess move
 ************************************************************************/

#include "move.h"
#include "pieceType.h"
#include <cassert>
#include <iostream>
#include <sstream>
#include <bitset>

using namespace std;

/***************************************************
 * MOVE : DEFAULT CONSTRUCTOR
 ***************************************************/
Move::Move() : promote(PieceType::INVALID), capture(PieceType::INVALID), moveType(Move::MoveType::MOVE), isWhite(true)
{
}

Move::Move(const char* text, const bool& isWhite)
{
   read(string(text));
   this->isWhite = isWhite;
}

Move::Move(const char* text)
{
   read(string(text));
   this->isWhite = true;
}

Move::Move(const string text, const bool& isWhite)
{
   read(text);
   this->isWhite = isWhite;
}

bool Move::operator==(const Move& rhs) const
{
   return this->source == rhs.source
      && this->dest == rhs.dest
      && this->promote == rhs.promote
      && this->capture == rhs.capture
      && this->moveType == rhs.moveType
      && this->isWhite == rhs.isWhite
      && this->text == rhs.text;
}

bool Move::operator!=(const Move& rhs) const
{
   return this->source != rhs.source
      || this->dest != rhs.dest
      || this->promote != rhs.promote
      || this->capture != rhs.capture
      || this->moveType != rhs.moveType
      || this->isWhite != rhs.isWhite
      || this->text != rhs.text;
}

char Move::letterFromPieceType(PieceType pt) const
{
   switch (pt)
   {
   case PieceType::SPACE:
      return ' ';
   case PieceType::PAWN:
      return 'p';
   case PieceType::BISHOP:
      return 'b';
   case PieceType::KNIGHT:
      return 'n';
   case PieceType::ROOK:
      return 'r';
   case PieceType::QUEEN:
      return 'q';
   case PieceType::KING:
      return 'k';
   }

   return -1;
}

PieceType Move::pieceTypeFromLetter(char letter) const
{
   switch (letter)
   {
   case 'p':
      return PieceType::PAWN;
   case 'b':
      return PieceType::BISHOP;
   case 'n':
      return PieceType::KNIGHT;
   case 'r':
      return PieceType::ROOK;
   case 'q':
      return PieceType::QUEEN;
   case 'k':
      return PieceType::KING;
   }

   return PieceType::INVALID;
}

void Move::read(const string& text)
{
   this->text = text;
   string firstTwo_s = text.substr(0, 2);
   const char* firstTwo = firstTwo_s.c_str();
   this->source = Position(firstTwo);

   string nextTwo_s = text.substr(2, 4);
   const char* nextTwo = nextTwo_s.c_str();
   this->dest = Position(nextTwo);

   this->moveType = MoveType::MOVE;
   promote = PieceType::INVALID;
   capture = PieceType::INVALID;

   if (this->text.length() < 5)
      return;

   string moveNotes = this->text.substr(4, 7);


   char fifthChar = text[4];
   for (char character : moveNotes)
      if (islower(character))
      {
         if (character != 'c')
            capture = pieceTypeFromLetter(fifthChar);
         else
            moveType = CASTLE_KING;

      }
      else
      {
         // if (character == 'Q')
         //    moveType = MoveType::PROMOTION;
         if (character == 'E')
            moveType = MoveType::ENPASSANT;
         if (character == 'C')
            moveType = MoveType::CASTLE_QUEEN;
      }
}

string Move::getText() const
{
   // Get PositionFrom
   string returnText;
   returnText += source.getCol() + 'a';
   returnText += source.getRow() + '1';

   // Get PositionTo
   returnText += dest.getCol() + 'a';
   returnText += dest.getRow() + '1';

   // captured a piece?
   if (capture != PieceType::INVALID && moveType != MoveType::ENPASSANT)
      returnText += letterFromPieceType(capture);

   // Enpassant?
   if (moveType == MoveType::ENPASSANT)
      returnText += 'E';

   // Promoted?
   // if (this->moveType == PROMOTED)
   //    returnText += 'Q';

   // Castled?
   if (moveType == MoveType::CASTLE_KING)
      returnText += 'c';
   if (moveType == MoveType::CASTLE_QUEEN)
      returnText += 'C';

   return returnText;
}



