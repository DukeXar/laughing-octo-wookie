// longest arithmetic progression
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

unsigned lap(std::vector<unsigned> const & data)
{
    unsigned res = 0;

    for (unsigned i = 0; i < data.size(); ++i) {
        for (unsigned j = i; j < data.size(); ++j) {
            unsigned delta = data[j] - data[i];
            
            unsigned curr_res = 2;
            unsigned prev = data[j];

            for (unsigned k = j + 1; k < data.size(); ++k) {
                if (data[k] - prev == delta) {
                    prev = data[k];
                    ++curr_res;
                }
            }

            using namespace std;
            res = max(res, curr_res);
        }
    }
    
    return res;
}

bool arithThree(std::vector<unsigned> const & data)
{
    if (data.size() < 3) {
        return false;
    }

    for (unsigned k = 1; k < data.size(); ++k) {
        unsigned i = k - 1;
        unsigned j = k + 1;
        
        while (i >= 0 && j < data.size()) {
            if (data[i] + data[j] == 2 * data[k]) {
                return true;
            }
            
            if (data[i] + data[j] > 2 * data[k]) {
                --i;
            } else {
                ++j;
            }
        }
    }
    
    return false;
}

unsigned lapDyn(std::vector<unsigned> const & data)
{
    if (data.size() < 3) {
        return data.size();
    }

    struct Entry
    {
        unsigned delta;
        unsigned len;
    };
    
    typedef std::vector<Entry> Row;
    typedef std::vector<Row> Dyn;

    const size_t N = data.size();

    Dyn dyn(data.size(), Row(data.size(), {0, 0}));

    for (unsigned row = 0; row < dyn.size(); ++row) {
        dyn[row][N-1] = Entry{data[N-1] - data[row], 2};
    }
    
    unsigned maxLap = 2;

    for (int col = N-2; col >= 0; --col) {
        for (int row = col-1; row >= 0; --row) {
            unsigned delta = data[col] - data[row];
            dyn[row][col] = Entry{delta, 2};
            
            for (unsigned k = row + 1; k < N; ++k) {
                Entry const & en = dyn[col][k];
                if (en.delta == delta) {
                    dyn[row][col].len = en.len + 1;
                    break;
                }
            }
            
            if (dyn[row][col].len > maxLap) {
                maxLap = dyn[row][col].len;
            }
        }
    }
    
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            std::cout << std::setw(2) << dyn[row][col].len << "," << std::setw(2) << dyn[row][col].delta << "| ";
        }
        std::cout << std::endl;
    }

    return maxLap;
}

int main()
{
    std::vector<unsigned> data;

    while (true) {
        unsigned n;
        std::cin >> n;

        if (!std::cin || !n) {
            break;
        }

        data.push_back(n);
    }
    
    std::cout << lapDyn(data) << std::endl;

    return 0;
}