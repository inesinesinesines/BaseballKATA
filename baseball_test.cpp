#include "gmock/gmock.h"
#include "baseball.cpp"


class BaseballFixture :public testing::Test{
public:
	Baseball game{ "123" };
	void assertIllegalArgument(string guessNumber) {
		try {
			game.guess(string(guessNumber));
			FAIL();
		}
		catch (exception e) {
			// test pass	
		};
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase)
{
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

TEST_F(BaseballFixture, ReturnSolvedResultIFMatchedNumber) {
	GuessResult result = game.guess("123");
	GuessResult expect{ true, 3, 0 };

	EXPECT_TRUE(result == expect);
}

TEST_F(BaseballFixture, get2strike1ball) {
	GuessResult result = game.guess("129");
	GuessResult expect{ false, 2, 0 };

	EXPECT_TRUE(result == expect);
}

TEST_F(BaseballFixture, get1strike2ball) {
	GuessResult result = game.guess("321");
	GuessResult expect{ false, 1, 2 };

	EXPECT_TRUE(result == expect);
}