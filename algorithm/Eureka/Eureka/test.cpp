#include <iostream>

int main() {
	for (int i = 1; i < 10; i += 2) {
		std::cout << "k : " << k << std::endl;
		for (int j = 0; j < 10; j += 2) {
			std::cout << "k : " << k << std::endl;
			for (int k = 0; k < 10; k += 10) {
				std::cout << "k : " << k << std::endl;
				std::cout << i + j + k << std::endl;

			}
		}
	}
}