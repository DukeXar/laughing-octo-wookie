#include <iostream>
#include <vector>

unsigned getSmsCount(unsigned noPresses)
{
    std::vector<unsigned> presses(noPresses+1, 0);

    presses[0] = 1; // one empty message

    unsigned result = 0;

    for (unsigned i = 1; i < presses.size(); ++i) {
        unsigned s = presses[i-1] * 8;

        if (i >= 2) {
            s += presses[i-2] * 8;
        }

        if (i >= 3) {
            s += presses[i-3] * 8;
        }

        if (i >= 4) {
            s += presses[i-4] * 2;
        }

        presses[i] = s;
        result += s;
    }
    
    return result;
}

int main()
{
    unsigned noPresses;
    std::cin >> noPresses;
    std::cout << getSmsCount(noPresses) << std::endl;
    return 0;
}