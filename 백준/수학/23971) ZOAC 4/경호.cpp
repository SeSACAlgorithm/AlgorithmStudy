#include <iostream>

using namespace std;

int main()
{
    int row, col, n, m;
    cin >> row >> col >> n >> m;
    ++n;
    ++m;

    int xCount = col % m == 0 ? col / m : col / m + 1;
    int yCount = row % n == 0 ? row / n : row / n + 1;

    cout << xCount * yCount;
}