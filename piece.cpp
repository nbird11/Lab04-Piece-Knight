/***********************************************************************
 * Source File:
 *    PIECE 
 * Author:
 *    <your name here>
 * Summary:
 *    The Piece base class and all the derived classes:
 *       SPACE, KING, QUEEN, ROOK, KNIGHT, BISHOP, PAWN
 ************************************************************************/

#include "position.h"  // for POSITION
#include "piece.h"     // for all the PIECE class definitions
#include "pieceSpace.h"
#include "pieceKnight.h"
#include "board.h"     // for BOARD
#include "uiDraw.h"    // for draw*()
#include <cassert>     // because we are paranoid
using namespace std;


Piece::Piece(const Piece& piece)
{
   this->nMoves = piece.nMoves;
   this->fWhite = piece.fWhite;
   this->position = piece.position;
   this->lastMove = piece.lastMove;
}

/************************************************
 * PIECE : ASSIGN
 ***********************************************/
const Piece & Piece::operator = (const Piece & rhs)
{
   this->nMoves = rhs.nMoves;
   this->fWhite = rhs.fWhite;
   this->position = rhs.position;
   this->lastMove = rhs.lastMove;
   return *this;
}

bool Piece::operator==(PieceType pt) const
{
   return this->getType() == pt;
}

bool Piece::operator!=(PieceType pt) const
{
   return this->getType() != pt;
}

void Piece::setLastMove(int currentMove)
{
   lastMove = currentMove;
   nMoves++;
}

/************************************************
 * PIECE : GET MOVES
 * Iterate through the moves decorator to allow a piece to move
 ***********************************************/
void Piece::getMoves(set <Move> & movesSet, const Board & board) const
{
}

