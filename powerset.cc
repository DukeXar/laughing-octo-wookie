#include <iostream>
#include <set>
#include <vector>
#include <iterator>

typedef std::vector<int> Data;
typedef std::vector<int> Set;

void printSet(Set const & set)
{
    std::cout << "{";
    char const * delim = "";
    for (Set::value_type i : set) {
        std::cout << delim << i;
        delim = ", ";
    }
    std::cout << "}" << std::endl;
}

void powerset(Data const & data, size_t start, Set & out)
{
    printSet(out);

    for (size_t i = start; i < data.size(); ++i) {
        out.push_back(data[i]);
        powerset(data, i+1, out);
        out.pop_back();
    }
}

void powerset(Data const & data)
{
    Set out;
    powerset(data, 0, out);
}

int main()
{
    int val;
    std::vector<int> data;
    
    while (std::cin >> val) {
        data.push_back(val);
    }
    
    powerset(data);
    
    return 0;
}