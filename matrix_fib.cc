#include <iostream>
#include <iomanip>
#include <cmath>

struct Matrix
{
    unsigned a, b, c, d;

    Matrix operator*(Matrix const & m) const
    {
        return Matrix{
            a * m.a + b * m.c,
            a * m.b + b * m.d,
            c * m.a + d * m.c,
            c * m.b + d * m.d
        };
    }
    
    Matrix & operator*=(Matrix const & m)
    {
        *this = *this * m;
        return *this;
    }
    
    Matrix operator+(Matrix const & m) const
    {
        return Matrix{
            a + m.a, b + m.b, c + m.c, d + m.d
        };
    }

    constexpr static Matrix identity() { return Matrix{1, 0, 0, 1}; }

    friend std::ostream & operator<<(std::ostream & os, Matrix const & m)
    {
        int len1 = std::max(std::log10(m.a), std::log10(m.c)) + 1;
        int len2 = std::max(std::log10(m.b), std::log10(m.d)) + 2;

        os << '|' << std::setw(len1) << m.a << ';' << std::setw(len2) << m.b << '|' << '\n'
           << '|' << std::setw(len1) << m.c << ';' << std::setw(len2) << m.d << '|';

        return os;
    }
};

Matrix binPower(Matrix const & m, unsigned power)
{
    if (power == 0) {
        return Matrix::identity();
    }
    
    if (power == 1) {
        return m;
    }
    
    Matrix res = Matrix::identity();
    Matrix p = m;

    while (power > 0) {
        if (power % 2 == 1) {
            res *= p;
        }

        p *= p;

        power /= 2;
    }
    
    return res;
}

unsigned fastFib(unsigned n)
{
    if (n == 1 || n == 2) {
        return 1;
    }

    Matrix mult = binPower(Matrix{1, 1, 1, 0}, n-2);
    return mult.a + mult.b;
}

int main()
{
    unsigned n;
    std::cin >> n;
    std::cout << fastFib(n) << std::endl;
    return 0;
}