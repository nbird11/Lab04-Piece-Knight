/***********************************************************************
 * Header File:
 *    TEST MOVE 
 * Author:
 *    <your name here>
 * Summary:
 *    test the Move class
 ************************************************************************/


#include "testMove.h"
#include "move.h"
#include <cassert>

 /*************************************
  * Constructor : default
  * Input: 
  * Output: source=INVALID
  *         dest  =INVALID
  **************************************/
void TestMove::constructor_default() 
{
   // SETUP
   // EXERCISE
   Move move;

   // VERIFY
   assertUnit(move.source == 0x99);
   assertUnit(move.dest == 0x99);
   assertUnit(move.promote == PieceType::INVALID);
   assertUnit(move.capture == PieceType::INVALID);
   assertUnit(move.moveType == Move::MoveType::MOVE);
   assertUnit(move.isWhite);
   assertUnit(move.text == string(""));

}  // TEARDOWN

 /*************************************
  * CONSTRUCTOR : standard string move
  * Input:  e5e6
  * Output: source=4,4
  *         dest  =4,5
  *         type  =MOVE
  **************************************/
void TestMove::constructString_simple()
{
   // SETUP
   string input = "e5e6";

   // EXERCISE
   Move move(input, true); 

   // VERIFY
   assertUnit(move.source.colRow == 0x44);
   assertUnit(move.dest.colRow == 0x45);
   assertUnit(move.moveType == Move::MoveType::MOVE);
}  // TEARDOWN

 /*************************************
  * READ simple move 
  * Input:  e5e6
  * Output: source=4,4
  *         dest  =4,5
  *         type  =MOVE
  **************************************/
void TestMove::read_simple()
{
   // SETUP
   Move move;
   // EXERCISE
   move.read("e5e6");
   // VERIFY
   assertUnit(move.source.colRow == 0x44);
   assertUnit(move.dest.colRow == 0x45);
   assertUnit(move.moveType == Move::MoveType::MOVE);
}  // TEARDOWN

 /*************************************
  * READ capture move 
  * Input:  e5d6r
  * Output: source=4,4
  *         dest  =3,5
  *         type  =MOVE
  *         capture=ROOK
  **************************************/
void TestMove::read_capture()
{
   // SETUP
   Move move;
   // EXERCISE
   move.read("e5d6r");
   // VERIFY
   assertUnit(move.source.colRow == 0x44);
   assertUnit(move.dest.colRow == 0x35);
   assertUnit(move.moveType == Move::MoveType::MOVE);
   assertUnit(move.capture == PieceType::ROOK);
}  // TEARDOWN

 /*************************************
  * READ enpassant move 
  * Input:  e5f6E
  * Output: source=4,4
  *         dest  =5,5
  *         type  =ENPASSANT
  **************************************/
void TestMove::read_enpassant()
{
   // SETUP
   Move move;
   // EXERCISE
   move.read("e5f6E");
   // VERIFY
   assertUnit(move.source.colRow == 0x44);
   assertUnit(move.dest.colRow == 0x55);
   assertUnit(move.moveType == Move::MoveType::ENPASSANT);
}  // TEARDOWN

 /*************************************
  * READ king side castle
  * Input:  e1g1c
  * Output: source=4,0
  *         dest  =6,0
  *         type  =CASTLE_KING
  **************************************/
void TestMove::read_castleKing()
{
   // SETUP
   Move move;
   // EXERCISE
   move.read("e1g1c");
   // VERIFY
   assertUnit(move.source.colRow == 0x40);
   assertUnit(move.dest.colRow == 0x60);
   assertUnit(move.moveType == Move::MoveType::CASTLE_KING);
}  // TEARDOWN

 /*************************************
  * READ queen side castle
  * Input:  e1c1C
  * Output: source=4,0
  *         dest  =2,0
  *         type  =CASTLE_QUEEN
  **************************************/
void TestMove::read_castleQueen()
{
   // SETUP
   Move move;
   // EXERCISE
   move.read("e1c1C");
   // VERIFY
   assertUnit(move.source.colRow == 0x40);
   assertUnit(move.dest.colRow == 0x20);
   assertUnit(move.moveType == Move::MoveType::CASTLE_QUEEN);
}  // TEARDOWN

 /*************************************
  * ASSIGN simple move
  * Input:  e5e6
  * Output: source=4,4
  *         dest  =4,5
  *         type  =MOVE
  **************************************/
void TestMove::assign_simple()
{
   // SETUP
   // EXERCISE
   Move move = "e5e6";
   // VERIFY
   assertUnit(move.source.colRow == 0x44);
   assertUnit(move.dest.colRow == 0x45);
   assertUnit(move.moveType == Move::MoveType::MOVE);
}  // TEARDOWN

 /*************************************
  * ASSIGN capture move
  * Input:  e5d6r
  * Output: source=4,4
  *         dest  =3,5
  *         type  =MOVE
  *         capture=ROOK
  **************************************/
void TestMove::assign_capture()
{
   // SETUP
   // EXERCISE
   Move move = "e5d6r";
   // VERIFY
   assertUnit(move.source.colRow == 0x44);
   assertUnit(move.dest.colRow == 0x35);
   assertUnit(move.moveType == Move::MoveType::MOVE);
   assertUnit(move.capture == PieceType::ROOK);
}  // TEARDOWN

 /*************************************
  * ASSIGN enpassant move
  * Input:  e5f6E
  * Output: source=4,4
  *         dest  =5,5
  *         type  =ENPASSANT
  **************************************/
void TestMove::assign_enpassant()
{
   // SETUP
   // EXERCISE
   Move move = "e5f6E";
   // VERIFY
   assertUnit(move.source.colRow == 0x44);
   assertUnit(move.dest.colRow == 0x55);
   assertUnit(move.moveType == Move::MoveType::ENPASSANT);
}  // TEARDOWN

 /*************************************
  * ASSIGN king side castle
  * Input:  e1g1c
  * Output: source=4,0
  *         dest  =6,0
  *         type  =CASTLE_KING
  **************************************/
void TestMove::assign_castleKing()
{
   // SETUP
   // EXERCISE
   Move move = "e1g1c";
   // VERIFY
   assertUnit(move.source.colRow == 0x40);
   assertUnit(move.dest.colRow == 0x60);
   assertUnit(move.moveType == Move::MoveType::CASTLE_KING);
}  // TEARDOWN

 /*************************************
  * ASSIGN queen side castle
  * Input:  e1c1C
  * Output: source=4,0
  *         dest  =2,0
  *         type  =CASTLE_QUEEN
  **************************************/
void TestMove::assign_castleQueen()
{
   // SETUP
   // EXERCISE
   Move move = "e1c1C";
   // VERIFY
   assertUnit(move.source.colRow == 0x40);
   assertUnit(move.dest.colRow == 0x20);
   assertUnit(move.moveType == Move::MoveType::CASTLE_QUEEN);
}  // TEARDOWN

 /*************************************
  * GET TEXT simple move
  * Input : source=4,4
  *         dest  =4,5
  *         type  =MOVE
  * Output:  e5e6
  **************************************/
void TestMove::getText_simple()
{
   // SETUP
   Move move;
   move.source = Position(4, 4);
   move.dest = Position(4, 5);
   move.moveType = Move::MoveType::MOVE;
   // EXERCISE
   string text = move.getText();
   // VERIFY
   assertUnit(text == "e5e6");
}  // TEARDOWN

 /*************************************
  * GET TEXT capture
  * Input : source=4,4
  *         dest  =4,5
  *         type  =MOVE
  *         capture=ROOK
  * Output:  e5e6r
  **************************************/
void TestMove::getText_capture()
{
   // SETUP
   Move move;
   move.source = Position(4, 4);
   move.dest = Position(4, 5);
   move.moveType = Move::MoveType::MOVE;
   move.capture = PieceType::ROOK;
   // EXERCISE
   string text = move.getText();
   // VERIFY
   assertUnit(text == "e5e6r");
}  // TEARDOWN

 /*************************************
  * GET TEXT en passant
  * Input : source=4,4
  *         dest  =5,5
  *         type  =ENPASSANT
  *         capture=PAWN
  * Output:  e5f6E
  **************************************/
void TestMove::getText_enpassant()
{
   // SETUP
   Move move;
   move.source = Position(4, 4);
   move.dest = Position(5, 5);
   move.moveType = Move::MoveType::ENPASSANT;
   move.capture = PieceType::PAWN;
   // EXERCISE
   string text = move.getText();
   // VERIFY
   assertUnit(text == "e5f6E");
}  // TEARDOWN

 /*************************************
  * GET TEXT king side castle
  * Input : source=4,0
  *         dest  =6,0
  *         type  =CASTLE_KING
  * Output:  e1g1c
  **************************************/
void TestMove::getText_castleKing()
{
   // SETUP
   Move move;
   move.source = Position(4, 0);
   move.dest = Position(6, 0);
   move.moveType = Move::MoveType::CASTLE_KING;
   // EXERCISE
   string text = move.getText();
   // VERIFY
   assertUnit(text == "e1g1c");
}  // TEARDOWN

 /*************************************
  * GET TEXT queen side castle
  * Input : source=4,0
  *         dest  =2,0
  *         type  =CASTLE_QUEEN  
  * Output:  e1c1C
  **************************************/
void TestMove::getText_castleQueen()
{
   // SETUP
   Move move;
   move.source = Position(4, 0);
   move.dest = Position(2, 0);
   move.moveType = Move::MoveType::CASTLE_QUEEN;
   // EXERCISE
   string text = move.getText();
   // VERIFY
   assertUnit(text == "e1c1C");
}  // TEARDOWN

 /*************************************
  * LETTER FROM PIECE TYPE space
  * Input :  SPACE
  * Output:  ' '
  **************************************/
void TestMove::letterFromPieceType_space()
{
   // SETUP
   Move move;

   // EXERCISE
   char letter = move.letterFromPieceType(PieceType::SPACE);

   // VERIFY
   assertUnit(letter == ' ');

}  // TEARDOWN

 /*************************************
  * LETTER FROM PIECE TYPE pawn
  * Input : PAWN
  * Output:  'p'
  **************************************/
void TestMove::letterFromPieceType_pawn()
{
   Move move;

   // EXERCISE
   char letter = move.letterFromPieceType(PieceType::PAWN);

   // VERIFY
   assertUnit(letter == 'p');

} // TEARDOAWN

 /*************************************
  * LETTER FROM PIECE TYPE bishop
  * Input : BISHOP
  * Output:  'b'
  **************************************/
void TestMove::letterFromPieceType_bishop()
{
   Move move;

   // EXERCISE
   char letter = move.letterFromPieceType(PieceType::BISHOP);

   // VERIFY
   assertUnit(letter == 'b');

}  // TEARDOWN

 /*************************************
  * LETTER FROM PIECE TYPE knight
  * Input : KNIGHT
  * Output:  'n'
  **************************************/
void TestMove::letterFromPieceType_knight()
{
   Move move;

   // EXERCISE
   char letter = move.letterFromPieceType(PieceType::KNIGHT);

   // VERIFY
   assertUnit(letter == 'n');

}  // TEARDOWN

 /*************************************
  * LETTER FROM PIECE TYPE rook
  * Input : ROOK
  * Output:  'r'
  **************************************/
void TestMove::letterFromPieceType_rook()
{
   Move move;

   // EXERCISE
   char letter = move.letterFromPieceType(PieceType::ROOK);

   // VERIFY
   assertUnit(letter == 'r');

}  // TEARDOWN

 /*************************************
  * LETTER FROM PIECE TYPE queen
  * Input : QUEEN
  * Output:  'q'
  **************************************/
void TestMove::letterFromPieceType_queen()
{
   Move move;

   // EXERCISE
   char letter = move.letterFromPieceType(PieceType::QUEEN);

   // VERIFY
   assertUnit(letter == 'q');

}  // TEARDOWN

 /*************************************
  * LETTER FROM PIECE TYPE king
  * Input : KING
  * Output:  'k'
  **************************************/
void TestMove::letterFromPieceType_king()
{
   Move move;

   // EXERCISE
   char letter = move.letterFromPieceType(PieceType::KING);

   // VERIFY
   assertUnit(letter == 'k');

}  // TEARDOWN

 /*************************************
  * PIECE TYPE FROM LETTER pawn
  * Input : 'p'
  * Output:  PAWN
  **************************************/
void TestMove::pieceTypeFromLetter_pawn()
{
   // SETUP
   Move move;

   // EXERCISE
   PieceType pieceType = move.pieceTypeFromLetter('p');

   // VERIFY
   assertUnit(pieceType == PieceType::PAWN);

}  // TEARDOWN

 /*************************************
  * PIECE TYPE FROM LETTER bishop
  * Input : 'b'
  * Output:  BISHOP
  **************************************/
void TestMove::pieceTypeFromLetter_bishop()
{
   // SETUP
   Move move;

   // EXERCISE
   PieceType pieceType = move.pieceTypeFromLetter('b');

   // VERIFY
   assertUnit(pieceType == PieceType::BISHOP);

}  // TEARDOWN

 /*************************************
  * PIECE TYPE FROM LETTER knight
  * Input : 'n'
  * Output:  KNIGHT
  **************************************/
void TestMove::pieceTypeFromLetter_knight()
{
   // SETUP
   Move move;

   // EXERCISE
   PieceType pieceType = move.pieceTypeFromLetter('n');

   // VERIFY
   assertUnit(pieceType == PieceType::KNIGHT);

}  // TEARDOWN

 /*************************************
  * PIECE TYPE FROM LETTER rook
  * Input : 'r'
  * Output:  ROOK
  **************************************/
void TestMove::pieceTypeFromLetter_rook()
{
   // SETUP
   Move move;

   // EXERCISE
   PieceType pieceType = move.pieceTypeFromLetter('r');

   // VERIFY
   assertUnit(pieceType == PieceType::ROOK);

}  // TEARDOWN

 /*************************************
  * PIECE TYPE FROM LETTER queen
  * Input : 'q'
  * Output:  QUEEN
  **************************************/
void TestMove::pieceTypeFromLetter_queen()
{
   // SETUP
   Move move;

   // EXERCISE
   PieceType pieceType = move.pieceTypeFromLetter('q');

   // VERIFY
   assertUnit(pieceType == PieceType::QUEEN);

}  // TEARDOWN

 /*************************************
  * PIECE TYPE FROM LETTER king
  * Input : 'k'
  * Output:  KING
  **************************************/
void TestMove::pieceTypeFromLetter_king() 
{
   // SETUP
   Move move;

   // EXERCISE
   PieceType pieceType = move.pieceTypeFromLetter('k');

   // VERIFY
   assertUnit(pieceType == PieceType::KING);

}  // TEARDOWN


 /*************************************
  * EQUAL - NOT
  * Input : b2b4 == b2b5
  * Output: false
  **************************************/
void TestMove::equal_not()
{
   // SETUP
   Move moveb4("b2b4", true);
   Move moveb5("b2b5", true);
   
   // EXERCISE   
   // VERIFY
   assertUnit(moveb4 != moveb5);

}  // TEARDOWN

 /*************************************
  * EQUAL - EQUALS
  * Input : b2b4 == b2b4
  * Output: true
  **************************************/
void TestMove::equal_equals()
{
   // SETUP
   Move move1("b2b4", true);
   Move move2("b2b4", true);

   // EXERCISE
   // VERIFY
   assertUnit(move1 == move2);

}  // TEARDOWN

 /*************************************
  * LESS THAN - LESS THAN
  * Input : b2b2 < b2b4
  * Output: true
  **************************************/
void TestMove::lessthan_lessthan()
{
   // SETUP
   Move moveb2("b2b2", true);
   Move moveb4("b2b4", true);

   // EXERCISE
   // VERIFY
   assertUnit(moveb2 < moveb4);

}  // TEARDOWN

 /*************************************
  * LESS THAN - EQUALS
  * Input : b2b4 < b2b4
  * Output: false
  **************************************/
void TestMove::lessthan_equals()
{
   // SETUP
   Move move1("b2b4", true);
   Move move2("b2b4", true);

   // EXERCISE
   // VERIFY
   assertUnit(move1 < move2 == false);

}  // TEARDOWN

 /*************************************
  * LESS THAN - GREATAER THAN
  * Input : b2b4 < b2b2
  * Output: false
  **************************************/
void TestMove::lessthan_greaterthan()
{
   // SETUP
   Move moveb4("b2b4", true);
   Move moveb2("b2b2", true);

   // EXERCISE
   // VERIFY
   assertUnit(moveb4 < moveb2 == false);

}  // TEARDOWN
