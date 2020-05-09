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
      if(board[row][col] != Blank)
      {
        isBlank = false;
        ASSERT_TRUE(isBoardBlank);
      }
    }
  }

  ASSERT_TRUE(isBoardBlank);
}

TEST(PiezasTest, dropPieceInBoundsReturnValue){
  Piezas board;
  piecePlaced = board.dropPiece(0,1);
  ASSERT_EQ(piecePlaced, 'X');
}

TEST(PiezasTest, dropPieceOutOfBoundsReturnValue){
  Piezas board;
  piecePlaced = board.dropPiece(0,12);
  ASSERT_EQ(piecePlaced, '?');
}

TEST(PiezasTest, dropPieceInBounds){
  Piezas board;
  board.dropPiece(0,1);
  ASSERT_EQ(b.pieceAt(0,1), 'X');
}


TEST(PiezasTest, pieceAtInBounds){
  Piezas board;
  board.dropPiece(0,1);
  ASSERT_EQ(b.pieceAt(0,1), 'X');
}

TEST(PiezasTest, pieceAtOutOfBounds){
  Piezas board;
  ASSERT_EQ(b.pieceAt(0,12), '?');
}

TEST(PiezasTest, CheckFirstTurn){
  Piezas board;
  ASSERT_EQ(board.turn, 'X');
}

TEST(PiezasTest, changingTurnsAfterDrop){
  Piezas board;
  EXPECT_TRUE(board.turn, 'X');
  board.dropPiece(0,1);
  EXPECT_TRUE(board.turn, 'O');
  board.dropPiece(0,2);
  EXPECT_TRUE(board.turn, 'X');
  board.dropPiece(0,3);
  ASSERT_TRUE(board.turn, 'O');
}


TEST(PiezasTest, doesBoardReset){
  Piezas board;
  board.dropPiece(0,1);
  board.reset();
  ASSERT_TRUE(board.pieceAt(0,10), Blank);
}

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
