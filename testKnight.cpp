/***********************************************************************
 * Source File:
 *    TEST KNIGHT
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for the knight
 ************************************************************************/

#include "testKnight.h"
#include "pieceKnight.h"     
#include "board.h"
#include "uiDraw.h"
#include <cassert>      

 /*************************************
  * +---a-b-c-d-e-f-g-h---+
  * |                     |
  * 8                     8
  * 7                     7
  * 6                     6
  * 5                     5
  * 4                     4
  * 3             p   .   3
  * 2           P         2
  * 1              (n)    1
  * |                     |
  * +---a-b-c-d-e-f-g-h---+
  **************************************/
void TestKnight::getMoves_end()
{
   // SETUP
   BoardEmpty board;
   Knight knight(7, 7, false /*white*/);
   knight.fWhite = true;
   knight.position.set(6, 0);
   board.board[6][0] = &knight;
   Black black(PAWN);
   board.board[4][1] = &black;
   White white(PAWN);
   board.board[5][2] = &white;
   set <Move> moves;

   // EXERCISE
   knight.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 2);  // many possible moves
   assertUnit(moves.find(Move("g1e2p")) != moves.end());
   assertUnit(moves.find(Move("g1h3")) != moves.end());

   // TEARDOWN
   board.board[6][0] = nullptr; // white knight
   board.board[4][1] = nullptr; // black pawn
   board.board[5][2] = nullptr; // white pawn
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7       p   p         7
 * 6     p       p       6
 * 5        (n)          5
 * 4     p       p       4
 * 3       p   p         3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKnight::getMoves_blocked()
{
   // SETUP
   BoardEmpty board;
   Knight knight(7, 7, true /*white*/);
   knight.fWhite = false;  // black
   knight.position.set(3, 4);
   board.board[3][4] = &knight;
   Black black1(PAWN);
   board.board[1][5] = &black1;
   Black black2(PAWN);
   board.board[2][6] = &black2;
   Black black3(PAWN);
   board.board[4][6] = &black3;
   Black black4(PAWN);
   board.board[5][5] = &black4;
   Black black5(PAWN);
   board.board[5][3] = &black5;
   Black black6(PAWN);
   board.board[4][2] = &black6;
   Black black7(PAWN);
   board.board[2][2] = &black7;
   Black black8(PAWN);
   board.board[1][3] = &black8;
   set <Move> moves;

   // EXERCISE
   knight.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 0);  // no possible moves

   // TEARDOWN
   board.board[3][4] = nullptr; // black knight
   board.board[1][5] = nullptr; // black1
   board.board[2][6] = nullptr; // black2
   board.board[4][6] = nullptr; // black3
   board.board[5][5] = nullptr; // black4
   board.board[5][3] = nullptr; // black5
   board.board[4][2] = nullptr; // black6
   board.board[2][2] = nullptr; // black7
   board.board[1][3] = nullptr; // black8

}  

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7       p   p         7
 * 6     p       p       6
 * 5        (N)          5
 * 4     p       p       4
 * 3       p   p         3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKnight::getMoves_capture()
{
   // SETUP
   BoardEmpty board;
   Knight knight(7, 7, false /*white*/);
   knight.fWhite = true;
   knight.position.set(3, 4);
   board.board[3][4] = &knight;
   Black black1(PAWN);
   board.board[1][5] = &black1;
   Black black2(PAWN);
   board.board[2][6] = &black2;
   Black black3(PAWN);
   board.board[4][6] = &black3;
   Black black4(PAWN);
   board.board[5][5] = &black4;
   Black black5(PAWN);
   board.board[5][3] = &black5;
   Black black6(PAWN);
   board.board[4][2] = &black6;
   Black black7(PAWN);
   board.board[2][2] = &black7;
   Black black8(PAWN);
   board.board[1][3] = &black8;
   set <Move> moves;

   // EXERCISE
   knight.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 8);
   assertUnit(moves.find(Move("d5e7p")) != moves.end());
   assertUnit(moves.find(Move("d5c7p")) != moves.end());
   assertUnit(moves.find(Move("d5b6p")) != moves.end());
   assertUnit(moves.find(Move("d5f6p")) != moves.end());
   assertUnit(moves.find(Move("d5b4p")) != moves.end());
   assertUnit(moves.find(Move("d5f4p")) != moves.end());
   assertUnit(moves.find(Move("d5c3p")) != moves.end());
   assertUnit(moves.find(Move("d5e3p")) != moves.end());

   // TEARDOWN
   board.board[3][4] = nullptr; // white knight
   board.board[1][5] = nullptr; // black1
   board.board[2][6] = nullptr; // black2
   board.board[4][6] = nullptr; // black3
   board.board[5][5] = nullptr; // black4
   board.board[5][3] = nullptr; // black5
   board.board[4][2] = nullptr; // black6
   board.board[2][2] = nullptr; // black7
   board.board[1][3] = nullptr; // black8

}  

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7       .   .         7
 * 6     .       .       6
 * 5        (n)          5
 * 4     .       .       4
 * 3       .   .         3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKnight::getMoves_free()
{
   // SETUP
   BoardEmpty board;
   Knight knight(7, 7, false /*white*/);
   knight.fWhite = true;
   knight.position.set(3, 4);
   board.board[3][4] = &knight;
   set <Move> moves;

   // EXERCISE
   knight.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 8);
   assertUnit(moves.find(Move("d5e7")) != moves.end());
   assertUnit(moves.find(Move("d5c7")) != moves.end());
   assertUnit(moves.find(Move("d5b6")) != moves.end());
   assertUnit(moves.find(Move("d5f6")) != moves.end());
   assertUnit(moves.find(Move("d5b4")) != moves.end());
   assertUnit(moves.find(Move("d5f4")) != moves.end());
   assertUnit(moves.find(Move("d5c3")) != moves.end());
   assertUnit(moves.find(Move("d5e3")) != moves.end());

   // TEARDOWN
   board.board[3][4] = nullptr;
}  



/*************************************
 * GET TYPE : knight
 * Input:
 * Output: KNIGHT
 **************************************/
void TestKnight::getType()
{
   // SETUP
   Knight knight(7, 7, false /*black*/);
   knight.fWhite = true;
   knight.position.set(3, 4);

   // EXERCISE
   PieceType pt = knight.getType();

   // VERIFY
   assertUnit(pt == PieceType::KNIGHT);
   assertUnit(knight.fWhite == true);
   assertUnit(knight.position.getCol() == 3);
   assertUnit(knight.position.getRow() == 4);

}  // TEARDOWN
