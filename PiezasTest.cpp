/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"

class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, isInitializedBoardBlank){
  Piezas board;
  bool isBoardBlank = true;

  for (int row = 0; row < BOARD_ROWS; row++){
    for (int col = 0; col < BOARD_COLS; col++){
      if( board.pieceAt(row,col) != Blank)
      {
        isBoardBlank = false;
        ASSERT_TRUE(isBoardBlank);
      }
    }
  }

  ASSERT_TRUE(isBoardBlank);
}

TEST(PiezasTest, dropPieceInBoundsReturnValue){
  Piezas board;
  Piece piecePlaced = board.dropPiece(1);
  ASSERT_EQ(piecePlaced, X);
}

TEST(PiezasTest, dropPieceOutOfBoundsReturnValue){
  Piezas board;
  Piece piecePlaced = board.dropPiece(12);
  ASSERT_EQ(piecePlaced, Invalid);
}

TEST(PiezasTest, dropPieceInBoundsX){
  Piezas board;
  board.dropPiece(1);
  ASSERT_EQ(board.pieceAt(0,1), X);
}

TEST(PiezasTest, dropPieceInBoundsO){
  Piezas board;
  board.dropPiece(1);
  board.dropPiece(2);
  ASSERT_EQ(board.pieceAt(0,2), O);
}

TEST(PiezasTest, pieceAtInBounds){
  Piezas board;
  board.dropPiece(1);
  ASSERT_EQ(board.pieceAt(0,1), X);
}

TEST(PiezasTest, pieceAtBlank){
  Piezas board;
  ASSERT_EQ(board.pieceAt(0,1), Blank);
}

TEST(PiezasTest, pieceAtOutOfBounds){
  Piezas board;
  ASSERT_EQ(board.pieceAt(0,12), Invalid);
}

TEST(PiezasTest, CheckFirstTurn){
  Piezas board;
  ASSERT_EQ(board.dropPiece(1), X);
}

TEST(PiezasTest, changingTurnsAfterDrop){
  Piezas board;
  EXPECT_EQ( board.dropPiece(1), X);
  EXPECT_EQ( board.dropPiece(2), O);
  EXPECT_EQ( board.dropPiece(3), X);
  ASSERT_EQ( board.dropPiece(1), O);
}

TEST(PiezasTest, doesBoardReset){
  Piezas board;
  board.dropPiece(1);
  board.reset();
  ASSERT_EQ(board.pieceAt(0,1), Blank);
}

TEST(PiezasTest, dropPieceInFullColumn){
  Piezas board;
  board.dropPiece(1);
  board.dropPiece(1);
  board.dropPiece(1);
  ASSERT_EQ( board.dropPiece(1), Blank);
}

TEST(PiezasTest, gameStateXwins){
  Piezas board;
  board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(2);
	board.dropPiece(1);
	board.dropPiece(0);
	board.dropPiece(2);
	board.dropPiece(0);
	board.dropPiece(3);
  ASSERT_EQ(board.gameState(), X);
}

TEST(PiezasTest, gameStateXwinsVertically){
  Piezas board;
  board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(0);
	board.dropPiece(3);
	board.dropPiece(2);
	board.dropPiece(1);
	board.dropPiece(3);
  board.dropPiece(2);
  board.dropPiece(0);
  board.dropPiece(2);
  board.dropPiece(1);
	board.dropPiece(3);
  ASSERT_EQ(board.gameState(), X);
}

TEST(PiezasTest, gameStateOwins){
  Piezas board;
  board.dropPiece(1);
  board.dropPiece(0);
  board.dropPiece(2);
  board.dropPiece(0);
  board.dropPiece(3);
  board.dropPiece(0);
  board.dropPiece(1);
  board.dropPiece(1);
  board.dropPiece(3);
  board.dropPiece(2);
  board.dropPiece(0);
  board.dropPiece(2);
  board.dropPiece(0);
  board.dropPiece(3);
  ASSERT_EQ(board.gameState(), O); 
}

TEST(PiezasTest, gameStateOwinsVertically){
  Piezas board;
  board.dropPiece(0);
  board.dropPiece(1);
  board.dropPiece(2);
  board.dropPiece(3);
  board.dropPiece(1);
  board.dropPiece(3);
  board.dropPiece(1);
  board.dropPiece(0);
  board.dropPiece(2);
  board.dropPiece(2);
  board.dropPiece(0);
  board.dropPiece(3);
  ASSERT_EQ(board.gameState(), O);
}

TEST(PiezasTest, gameStateMidGame){
  Piezas board;
  board.dropPiece(0);
  board.dropPiece(1);
  board.dropPiece(2);
  board.dropPiece(3);
  board.dropPiece(1);
  board.dropPiece(3);
  board.dropPiece(1);
  board.dropPiece(0);
  ASSERT_EQ(board.gameState(), Invalid);
}

TEST(PiezasTest, gameStateTie){
  Piezas board;
  board.dropPiece(0);
  board.dropPiece(1);
  board.dropPiece(0);
  board.dropPiece(3);
  board.dropPiece(0);
  board.dropPiece(1);
  board.dropPiece(1);
  board.dropPiece(3);
  board.dropPiece(2);
  board.dropPiece(2);
  board.dropPiece(3);
  board.dropPiece(2);
  board.dropPiece(2);
  ASSERT_EQ(board.gameState(), Blank);
}
//
// TEST(PiezasTest, XXX){
//   Piezas board;
// }
//
// TEST(PiezasTest, XXX){
//   Piezas board;
// }
//
// TEST(PiezasTest, XXX){
//   Piezas board;
// }
//
// TEST(PiezasTest, XXX){
//   Piezas board;
// }
//
// TEST(PiezasTest, XXX){
//   Piezas board;
// }
