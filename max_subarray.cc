#include <iostream>
#include <vector>

int max_subarray(std::vector<int> const & values)
{
    const int MIN = std::numeric_limits<int>::min();
    
    int max_so_far = MIN;
    int sum = 0;
    
    for (unsigned i = 0; i < values.size(); ++i) {
        int s = sum + values[i];
        if (s < 0) {
            sum = 0;
        } else {
            if (s > max_so_far) {
                max_so_far = s;
            }
            sum = s;
        }
    }

    return max_so_far;
}

int main()
{
    return 0;
}