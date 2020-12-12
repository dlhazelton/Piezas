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

// What an NSane dummy test you got here
TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

// Testing constructor & reset
TEST(PiezasTest, constructTest)
{
  Piezas();
  Piece dummyPiece = board[0][0];
  ASSERT_EQ(dummyPiece, Blank);
}

TEST(PiezasTest, resetTest)
{
  reset();
  Piece dummyPiece = board[0][0];
  ASSERT_EQ(dummyPiece, Blank);
}

// Testing dropPiece
TEST(PiezasTest, validEmptyDrop)
{
  dropPiece(0);
  Piece dummyPiece = board[0][0];
  ASSERT_NE(dummyPiece, Blank);
}

TEST(PiezasTest, filledColumnDrop)
{
  dropPiece(0);
  dropPiece(0);
  dropPiece(0);
  Piece dummyPiece = dropPiece(0);
  ASSERT_EQ(dummyPiece, Blank);
}

TEST(PiezasTest, invalidDrop)
{
  Piece dummyPiece = dropPiece(4);
  ASSERT_NE(dummyPiece, Invalid);
}

TEST(PiezasTest, errorDrop) {
  ASSERT_NO_THROW(dropPiece("A"));
}

// Testing pieceAt
TEST(PiezasTest, validAt)
{
  dropPiece(0);
  Piece dummyPiece = pieceAt(0, 0);
  ASSERT_NE(dummyPiece, Blank);
}

TEST(PiezasTest, emptyAt)
{
  Piece dummyPiece = pieceAt(0, 0);
  ASSERT_EQ(dummyPiece, Blank);
}

TEST(PiezasTest, invalidAt)
{
  Piece dummyPiece = pieceAt(4, 0);
  ASSERT_EQ(dummyPiece, Invalid);
}

TEST(PiezasTest, errorAt)
{
  ASSERT_NO_THROW(pieceAt("A","B"));
}

// Testing gameState
