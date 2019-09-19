#include <iostream>
#include <fstream>

int triangle_list[44] = { 0, };

void triangleNumber(int triangle_lists[]) {
	for (int i = 0; i < 45; ++i) {
		triangle_lists[i] = (i + 2)*(i+1) / 2;
	}
}

int eureka(int sub_test) {
	int sum = 0;
	for (int i = 0; i < 45; ++i) {
		sum += triangle_list[i];
		if (sum > sub_test) break;
		for (int j = 0; j < 45; ++j) {
			sum += triangle_list[j];
			for (int h = 0; h < 45; ++h) {
				sum += triangle_list[h];
				if (sum == sub_test) {
					return 1;
				}
				sum -= triangle_list[h];
			}
			sum -= triangle_list[j];
		}
		sum -= triangle_list[i];
	}
	return 0;
}



int main() {
	std::ifstream inp;
	inp.open("input.txt");
	int test, sub_test;
	inp >> test;
	triangleNumber(triangle_list);
	
	while (test--) {
		inp >> sub_test;
		std::cout << eureka(sub_test) << std::endl;
	}

	system("pause");
	return 0;
}