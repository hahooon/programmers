#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

// sort Reverse
bool desc(int a, int b) {
	return a > b;
}

// array copy for count down if letters is in numbers.
void arrCopy(int a[], int b[]) {
	for (int i = 0; i < 10; ++i) {
		b[i] = a[i];
	}
}

// is 'a' prime number if a is prime then return true.
bool checkPrimeNumber(int a) {
	bool booleanCheck = true;
	for (int i = 2; i*i <= a; ++i) {
		if (a%i == 0) {
			booleanCheck = false;
			break;
		}
	}
	return booleanCheck;
}

// is 'a' in arr if a is in arr then return true.
bool is_a_in_arr(int a, int arr[]) {
	bool check = false;
	for (int i = 0; i < 10; ++i) {
		if (arr[i] > 0 & a == i) {
			check = true;
			break;
		}
	}
	return check;
}

// checking the duplicated using for one number and checking that prime number has wrong letters.
bool arrCheck(int arr[], int count_number[]) {
	bool checkedBoolean = true;
	for (int i = 0; i < 10; ++i) {
		if (arr[i] < 0) {
			checkedBoolean = false;
			break;
		}
	}
	return checkedBoolean;
}

// find the right number for condition and algorthim is if sub prime number in prime vector is belong to given letters.
bool findAnswer(int a, int copyArr[], int counter_number[]) {
	while (a != 0) {
		copyArr[a % 10] -= 1;
		a /= 10;
	}
	return arrCheck(copyArr, counter_number);
}

int main() {
	std::string numbers = "17";
	int answer = 0;
	int count_number[10] = { 0,0,0,0,0,0,0,0,0,0 }, copied_Arr[10] = {};
	std::sort(numbers.begin(), numbers.end(), desc);
	std::vector<int> primeVector;

	// 문자열 numbers에 대하여 숫자 갯수 새기 | 문자열 numbers -> 인트형 N 변경
	for (int i = 0; i <= numbers.length(); ++i) {
		count_number[(numbers[i] - '0')] += 1;
	}
	int N = atoi(numbers.c_str());

	// N에 대하여 N까지 소수찾고 Vector에 삽입하기.
	for (int i = 2; i <= N; ++i) {
		if (checkPrimeNumber(i) == true) {
			primeVector.push_back(i);
		}
	}

	// 소수 후보군(primeVector)에서 조건에 맞는 소수 찾아내기
	for (int i = 0; i < primeVector.size(); ++i) {
		arrCopy(count_number, copied_Arr);
		if (findAnswer(primeVector[i], copied_Arr, count_number)) {
			answer += 1;
		}
	}

	for (int i = 0; i < 10; ++i) {
		std::cout << count_number[i] << ' ';
	}
	std::cout << "\n---------- Copied Arr ----------" << std::endl;
	for (int i = 0; i < 10; ++i) {
		std::cout << copied_Arr[i] << ' ';
	}

	std::cout << '\n' << answer;

	std::cout << std::endl;
	std::cout << N-1 << std::endl;
	
	system("pause");
}