#include "gmock/gmock.h"
#include "baseball.cpp"

class BaseballFixture :public testing::Test{
public:
	Baseball game;
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
}
