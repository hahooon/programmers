#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::ifstream inp;
	inp.open("input.txt");
	int test = 0;
	inp >> test;

	while (test--) {
		int a, b, c;
		inp >> a;
		inp >> b;
		inp >> c;

		if (c / a >= 10) {
			if (c%a == 0) {
				std::cout << a << (c / a) << std::endl;
			}
			else {
				std::cout << c % a << (c / a) + 1 << std::endl;
			}
		}
		else {
			if (c%a == 0) {
				std::cout << a << '0' << (c / a) << std::endl;
			}
			else {
				std::cout << c % a << '0' << (c / a) + 1 << std::endl;
			}
		}
	}
	inp.close();
	system("pause");
	return 0;
}