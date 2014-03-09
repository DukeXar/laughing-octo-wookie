#include <iostream>
#include <algorithm>

template<typename T>
T max(T a, T b, T c)
{
    return std::max(a, std::max(b, c));
}

int maxProd(int n)
{
    if (n <= 1) return 0;

    int res = 0;
    for (int i = 1; i < n; ++i) {
        int m = std::max(i * (n-i), res);
        res = std::max(i * maxProd(n-i), m);
    }
    
    return res;
}

unsigned maxProdDyn(unsigned n)
{
    if (n <= 1) return 0;

    std::vector<unsigned> data(n+1, 0);
    
    data[0] = 0;
    data[1] = 0;

    for (unsigned i = 2; i <= n; ++i) {
        unsigned s = 0; 
        for (unsigned j = 1; j <= i / 2; ++j)  {
            s = max(s, j * (i-j), j * data[i-j]);
        }
        data[i] = s;
    }

    return data[n];
}

int main()
{
    unsigned n;
    std::cin >> n;
    std::cout << maxProdDyn(n) << std::endl;

    return 0;
}