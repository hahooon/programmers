#include <iostream>
#include <string>
#include <vector>

int main() {
	int brown = 10, red = 2;
	std::vector<int> answer = {};
	int area = brown + red;
	for (int v = 1; v*v <= area; ++v) {
		int horizontal = area / v;
		if (2 * (horizontal + v - 2) == brown && (horizontal - 2)*(v - 2) == red) {
			answer.push_back(horizontal);
			answer.push_back(v);
			break;
		}
	}
	
	std::cout << answer[0] << ' ' << answer[1];

	system("pause");
}