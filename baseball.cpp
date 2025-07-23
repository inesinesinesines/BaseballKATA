
#include <string>
#include <stdexcept>

using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
	bool operator==(const GuessResult &st1) {
		if ((this->solved == st1.solved)
			&& (this->strikes == st1.strikes)
			&& (this->balls == st1.balls))
			return true;
		else
			return false;
	}
};

class Baseball {
public:
	explicit Baseball(const string& question) : question(question) {}

	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);

		return { isCorrectAnswer(guessNumber), 
				 getStrikeCount(guessNumber), 
			 	 getBallCount(guessNumber) 
			   };
	}

	bool isCorrectAnswer(const std::string& guessNumber)
	{
		return guessNumber == question;
	}

	int getBallCount(const std::string& guessNumber)
	{
		int ball = 0;
		if (guessNumber[0] == question[1] || guessNumber[0] == question[2]) ball++;
		if (guessNumber[1] == question[0] || guessNumber[1] == question[2]) ball++;
		if (guessNumber[2] == question[0] || guessNumber[0] == question[1]) ball++;
		return ball;
	}

	int getStrikeCount(const std::string& guessNumber)
	{
		int strike = 0;
		if (guessNumber[0] == question[0]) strike++;
		if (guessNumber[1] == question[1]) strike++;
		if (guessNumber[2] == question[2]) strike++;
		return strike;
	}

	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw length_error("Must be three errors");
		}

		for (char ch : guessNumber) {
			if ('0' <= ch && ch <= '9') continue;
			throw invalid_argument("Must be number");
		}

		if (isDuplicatedNumber(guessNumber))
			throw invalid_argument("Must not have same number");
	}

	bool isDuplicatedNumber(const std::string& guessNumber)
	{
		return (guessNumber[0] == guessNumber[1] ||
			guessNumber[0] == guessNumber[2] ||
			guessNumber[1] == guessNumber[2]);
	}

private: 
	string question;
};