#include "Piezas.h"


/** CLASS Piezas
* Class for representing a Piezas vertical board, which is roughly based
* on the game "Connect Four" where pieces are placed in a column and
* fall to the bottom of the column, or on top of other pieces already in
* that column. For an illustration of the board, see:
*  https://en.wikipedia.org/wiki/Connect_Four
*
* Board coordinates [row,col] should match with:
* [2,0][2,1][2,2][2,3]
* [1,0][1,1][1,2][1,3]
* [0,0][0,1][0,2][0,3]
* So that a piece dropped in column 2 should take [0,2] and the next one
* dropped in column 2 should take [1,2].
**/
// main(){
//   Piezas board;
//   board.reset();
//   board.dropPiece(0);
//   board.dropPiece(1);
//   board.dropPiece(0);
//   board.dropPiece(3);
//   board.dropPiece(0);
//   board.dropPiece(1);
//   board.dropPiece(1);
//   board.dropPiece(3);
//   board.dropPiece(2);
//   board.dropPiece(2);
//   board.dropPiece(3);
//   board.dropPiece(2);
//   board.dropPiece(2);
//   board.wittlehelper();
//   printf("game state = %i\n", board.gameState());
//
//   board.reset();
//   board.dropPiece(0);
// 	board.dropPiece(1);
// 	board.dropPiece(0);
// 	board.dropPiece(3);
// 	board.dropPiece(2);
// 	board.dropPiece(1);
// 	board.dropPiece(3);
//   board.dropPiece(2);
//   board.dropPiece(0);
//   board.dropPiece(2);
//   board.dropPiece(1);
// 	board.dropPiece(3);
//   board.wittlehelper();
//   printf("game state = %i\n", board.gameState());
//
//
//   // printf("ahhh\n");
//   //
// 	// board.dropPiece(1); //O
// 	// board.dropPiece(3); //X
//   // board.dropPiece(2); //O
//   // board.dropPiece(0); //X
//   // board.dropPiece(2); //O
//   // board.dropPiece(1); //X
// 	// board.dropPiece(3); //O
//   //
// 	// board.dropPiece(0); //O Skip
// 	// board.dropPiece(1); //X
// 	// board.dropPiece(2); //O
// 	// board.dropPiece(2); //X
// 	// board.dropPiece(0); //O Skip
// 	// board.dropPiece(3); //X
// 	// board.dropPiece(3); //O
// 	// board.dropPiece(0); //X Skip
// 	// board.dropPiece(3); //O
//   // board.wittlehelper();
//
// }

/**
* Constructor sets an empty board (default 3 rows, 4 columns) and
* specifies it is X's turn first
**/
Piezas::Piezas()
{
  board.resize(BOARD_ROWS);
  for (int row = 0; row < BOARD_ROWS; row++){
    board[row].resize(BOARD_COLS);
    for (int col = 0; col < BOARD_COLS; col++){
      board[row][col] = Blank;
    }
  }
  turn =  X;
}

/**
* Resets each board location to the Blank Piece value, with a board of the
* same size as previously specified
**/
void Piezas::reset()
{
  for (int row = 0; row < BOARD_ROWS; row++){
    for (int col = 0; col < BOARD_COLS; col++){
      board[row][col] = Blank;
    }
  }
}

/**
* Places a piece of the current turn on the board, returns what
* piece is placed, and toggles which Piece's turn it is. dropPiece does
* NOT allow to place a piece in a location where a column is full.
* In that case, placePiece returns Piece Blank value
* X -> Out of bounds coordinates return the Piece Invalid value
* Trying to drop a piece where it cannot be placed loses the player's turn
**/
Piece Piezas::dropPiece(int column)
{
  Piece placedPiece = turn;

  //Toggling turn
  if(turn == O)
  {
    turn = X;
  }else{ turn = O; }

  // Checking for out of bounds
  if (column < 0 || column > BOARD_COLS)
  { return Invalid; }

  //Placing Piece
  for (int row = 0; row < BOARD_ROWS; row++){
    if (board[row][column] == Blank)
    {
      board[row][column] = placedPiece;
      return placedPiece;
    }
  }

  //If column is full return blank
  return Blank;
}

/**
* Returns what piece is at the provided coordinates, or Blank if there
* are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
  // Checking bounds
  if (row < 0 || row >= BOARD_ROWS || column < 0 || column >= BOARD_COLS)
  { return Invalid; }

  return board[row][column];
}

/**
* Returns which Piece has won, if there is a winner, Invalid if the game
* is not over, or Blank if the board is filled and no one has won ("tie").
* For a game to be over, all locations on the board must be filled with X's
* and O's (i.e. no remaining Blank spaces). The winner is which player has
* the most adjacent pieces in a single line. Lines can go either vertically
* or horizontally. If both X's and O's have the same max number of pieces in a
* line, it is a tie.
**/
Piece Piezas::gameState()
{
  // Values for current Score
  int XcurrentScore = 0;
  int OcurrentScore = 0;

  // Values for highscore
  int Xhighscore, Ohighscore = 0;

  // Checking horizontally
  for (int row = 0; row < BOARD_ROWS; row++){
    // Resetting scores
    XcurrentScore = 0;
    OcurrentScore = 0;
    for (int col = 0; col < BOARD_COLS; col++){
      // Blank tile indicates game is not over
      if (board[row][col] == Blank)
      { return Invalid; }
      // Current cell is O
      else if (board[row][col] == X)
      {
        //Incrementing
        XcurrentScore+=1;
        //Setting Highscore
        if ( Xhighscore < XcurrentScore)
        { Xhighscore = XcurrentScore; }
        // Resetting O Score
        OcurrentScore = 0;

      }
      // Current cell is X
      else if (board[row][col] == O)
      {
        //Incrementing
        OcurrentScore+=1;
        //Setting Highscore
        if ( Ohighscore < OcurrentScore)
        { Ohighscore = OcurrentScore; }
        // Resetting X Score
        XcurrentScore = 0;
      }
    }
  } //Finished checking horizontally

  // Checking Vertically
  for (int col = 0; col < BOARD_COLS; col++){
    // Resetting scores
    XcurrentScore = 0;
    OcurrentScore = 0;
    for  (int row = 0; row < BOARD_ROWS; row++){
      // Current cell is O
      if (board[row][col] == X)
      {
        //Incrementing
        XcurrentScore+=1;
        //Setting Highscore
        if ( Xhighscore < XcurrentScore)
        { Xhighscore = XcurrentScore; }
        // Resetting O Score
        OcurrentScore = 0;

      }
      // Current cell is X
      else if (board[row][col] == O)
      {
        //Incrementing
        OcurrentScore+=1;
        //Setting Highscore
        if ( Ohighscore < OcurrentScore)
        { Ohighscore = OcurrentScore; }
        // Resetting X Score
        XcurrentScore = 0;
      }
    }
  } // Done checking Vertically

  // Evaluating High scores
  if ( Ohighscore > Xhighscore)
  { return O; }

  else if (Xhighscore > Ohighscore)
  { return X;}

  else
  { return Blank; }
}
