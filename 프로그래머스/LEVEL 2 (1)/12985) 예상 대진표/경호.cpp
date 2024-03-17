using namespace std;

int solution(int n, int a, int b)
{
    int count = 0;
    int low = a < b ? a : b;
    int high = a > b ? a : b;
    while(low < high)
    {
        ++count;
        low = (low & 1) == 1 ? (low + 1) / 2 : low / 2;
        high = (high & 1) == 1 ? (high + 1) / 2 : high / 2;
    }

    return count;
}