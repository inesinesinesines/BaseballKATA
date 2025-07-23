#include "gmock/gmock.h"
#include "baseball.cpp"

TEST(BaseballGame, tryGameTest) {
	EXPECT_EQ(1, 1);
}

TEST(BaseballGame, ThrowExceptionWhenInputLengthIsUnmatched)
{
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}