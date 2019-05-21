#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> d = {2,2,3,3};
	int budget = 10, answer = 0, i = 0;
	std::sort(d.begin(), d.end());
	while (budget - d[i] >= 0) {
		budget -= d[i];
		++answer;
		++i;
		if (i == d.size())	break;
	}

	std::cout << answer;

	system("pause");
}