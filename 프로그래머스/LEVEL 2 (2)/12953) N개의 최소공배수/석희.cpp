#include <string>
#include <vector>

using namespace std;

// 유클리드 호제법
int find_gcd(int a, int b)
{
    int temp;

    while (b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}

int find_lcm(int a, int b)
{
    // 최소공배수 = 두 수의 곱 / 최대공약수
    return a * b / find_gcd(a, b);
}

int solution(vector<int> arr)
{
    int lcm = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        lcm = find_lcm(lcm, arr[i]);
    }

    return lcm;
}