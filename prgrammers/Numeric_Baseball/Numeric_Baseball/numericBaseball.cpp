#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

int main() {
	std::vector<std::vector<int>> baseball = { {123,1,1},{356,1,0},{327,2,0},{489,0,1} };
	int answer = 0;
	int strikeCount = 0, ballCount = 0;
	bool guessCheck = true;
	std::string subNumber = "", checked_number = "";
	
	for (int i = 123; i <= 987; ++i) {
		subNumber = std::to_string(i);
		if (subNumber[0] == subNumber[1] || subNumber[0] == subNumber[2] || subNumber[1] == subNumber[2]) {
			continue;
		}
		else if (subNumber[0] == '0' || subNumber[1] == '0' || subNumber[2] == '0') {
			continue;
		}
		guessCheck = true;

		for (int j = 0; j < baseball.size(); ++j) {
			strikeCount = 0, ballCount = 0;

			for (int k = 0; k < 3; ++k) {
				for (int l = 0; l < 3; ++l) {
					checked_number = std::to_string(baseball[j][0]);
					if (subNumber[k] == checked_number[l] && k == l) {
						strikeCount += 1;
					}
					else if (subNumber[k] == checked_number[l] && k != l) {
						ballCount += 1;
					}
				}
			}

			if (baseball[j][1] != strikeCount || baseball[j][2] != ballCount) {
				guessCheck = false;
				break;
			}
		}
		if (guessCheck == true) {
			++answer;
		}
	}
	std::cout << answer << std::endl;

	system("pause");
}