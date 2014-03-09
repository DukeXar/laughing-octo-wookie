#include <iostream>

unsigned binpower(unsigned val, unsigned power)
{
	if (val == 0) {
		return 0;
	}

	if (power == 0) {
		return 1;
	}

	unsigned x = binpower(val, power / 2);

	if (power % 2 == 0) {
		return x * x;
	} else {
		return x * x * val;
	}
}

int main()
{
	unsigned val, power;
	std::cin >> val >> power;

	std::cout << binpower(val, power) << std::endl;
	
	return 0;
}