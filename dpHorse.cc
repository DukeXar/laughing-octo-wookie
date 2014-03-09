#include <iostream>
#include <vector>

struct Entry
{
    unsigned count;
    bool visited;
};

typedef std::vector<Entry> Row;
typedef std::vector<Row> Desk;

int horseSteps(int col, int row, Desk & desk)
{
    if (col < 0 || static_cast<size_t>(col) >= desk.size()) {
        return -1;
    }

    if (row < 0 || static_cast<size_t>(row) >= desk.size()) {
        return -1;
    }

    if (desk[col][row].count == 0) {
        desk[col][row].count =
            (horseSteps(col-1, row-2, desk) + 1) +
            (horseSteps(col+1, row-2, desk) + 1) +
            (horseSteps(col-2, row-1, desk) + 1) +
            (horseSteps(col-2, row+1, desk) + 1);
    }

    return desk[col][row].count;
}

unsigned horseSteps(unsigned size)
{
    Desk desk(size, Row(size, Entry{0, false}));
    return horseSteps(size-1, size-1, desk);
}

int main()
{
    unsigned size;
    std::cin >> size;
    std::cout << horseSteps(size) << std::endl;
    return 0;
}