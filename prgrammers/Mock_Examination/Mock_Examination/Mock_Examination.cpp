#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> answers = {3,3,3,5};
	std::vector<int> answer = {};
	int count[3] = { 0, 0, 0 };
	int person1[] = { 1,2,3,4,5 };
	int person2[] = { 2,1,2,3,2,4,2,5 };
	int person3[] = { 3,3,1,1,2,2,4,4,5,5 };

	for (int i = 0; i < answers.size(); ++i) {
		if (answers[i] == person1[i % 5]) {
			++count[0];
		}
		if (answers[i] == person2[i % 8]) {
			++count[1];
		}
		if (answers[i] == person3[i % 10]) {
			++count[2];
		}
	}

	int max_Answer_Count = -1;

	for (int i = 0; i < 3; ++i) {
		if (count[i] > max_Answer_Count) {
			max_Answer_Count = count[i];
		}
	}
	for (int i = 0; i < 3; ++i) {
		if (max_Answer_Count == count[i]) {
			answer.push_back(i + 1);
		}
	}
	
	for (int i = 0; i < answer.size(); ++i) {
		std::cout << answer[i] << std::endl;
	}

	system("pause");
}