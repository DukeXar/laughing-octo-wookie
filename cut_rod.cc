#include <iostream>
#include <vector>

class CutRod
{
public:
    explicit CutRod(const std::vector<unsigned> & prices):
        m_prices(prices),
        m_res(0)
    { }

    void solve()
    {
        const unsigned n = m_prices.size();
        
        m_path = std::vector<unsigned>(n, 0);
        std::vector<unsigned> res(n, 0);

        for (unsigned i = 0; i < n; ++i) {
            unsigned start = i;
            unsigned r = m_prices[i];

            for (unsigned j = 0; j < i; ++j) {
                unsigned s = m_prices[j];

                if (i - j > 0) {
                    s += res[i - j - 1];
                }

                if (s > r) {
                    start = j;
                    r = s;
                }
            }

            m_path[i] = start;
            res[i] = r;
        }

        m_res = res[n-1];
    }
    
    std::vector<unsigned> const & getPath() const { return m_path; }
    
    friend std::ostream & operator<<(std::ostream & os, CutRod const & problem)
    {
        os << "[";
        if (!problem.m_path.empty()) {
            char const * delim = "";
            int n = problem.m_path.size() - 1;
            while (n >= 0) {
                os << delim << problem.m_path[n] + 1;
                delim = ", ";
                n = n - problem.m_path[n] - 1;
            }
        }
        os << "]=" << problem.m_res;
        return os;
    }

private:
    std::vector<unsigned> m_prices;
    std::vector<unsigned> m_path;
    unsigned m_res;
};

int main()
{
    std::vector<unsigned> prices;
    unsigned price;
    while (std::cin >> price) {
        if (price == 0) {
            break;
        }
        
        prices.push_back(price);
    }
    
    CutRod problem(prices);

    problem.solve();
    std::cout << problem << std::endl;

    return 0;
}