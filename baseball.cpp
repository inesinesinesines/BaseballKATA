
#include <string>
#include <stdexcept>

using namespace std;
class Baseball {
public:
	int guess(const string& string) {
		if (string.length() != 3) {
			throw length_error("Must be three errors");
		}
	}
};