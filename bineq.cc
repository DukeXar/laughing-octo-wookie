#include <iostream>
#include <iomanip>
#include <limits>
#include <cassert>

bool get_bit(unsigned num, unsigned bit)
{
	return (num >> bit) & 0x01;
}

unsigned get_range(unsigned num, unsigned start, unsigned len)
{
	size_t const digits = std::numeric_limits<unsigned>::digits;
	
	std::cout << digits << std::endl;

	if (start + len > digits) {
		return 0;
	}

	unsigned const shift = (digits - (start + len));
	unsigned const mask = 1 << (len);

	num = num >> shift;
	num = num & ~mask;

	return num;
}

int is_bineq(unsigned num)
{
	size_t const digits = std::numeric_limits<unsigned>::digits;
	
	for (unsigned len = 0; len < digits / 2; ++len) {
		unsigned start = 0;
		bool failed = false;
		while (start + 2*len < digits) {
			failed = (get_range(num, start, len) != get_range(num, start + len, len));
			if (failed) {
				break;
			}
			start += len;
		}
		
		if (!failed) {
			return len;
		}
	}
	
	return -1;
}

int main()
{
	std::cout << std::hex << get_range(0xFF000000, 0, 8) << std::dec << std::endl; 
	assert(get_range(0xFFFFFFFF, 0, 8) == 0xFF);

	return 0;
}