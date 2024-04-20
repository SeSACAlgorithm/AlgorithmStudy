#include <string>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

bool vis[10];
unordered_set<int> UOS;

bool IsPrime(int Number)
{
    if (Number < 2)
        return false;

    for (int i = 2; i <= sqrt(Number); ++i)
    {
        if (Number % i == 0)
            return false;
    }

    return true;
}

void combine(const string& numbers, int myIdx = -1, string PrimeNumber = "")
{
    if (PrimeNumber != "")
    {
        int n = stoi(PrimeNumber);

        if (IsPrime(n))
            UOS.insert(n);
    }

    for (int i = 0; i < numbers.size(); ++i)
    {
        if (myIdx == i || vis[i])
            continue;

        vis[i] = true;
        combine(numbers, i, PrimeNumber + numbers[i]);
        vis[i] = false;
    }
}

int solution(string numbers)
{
    combine(numbers);

    return UOS.size();
}
