#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void)
{
    int A, B, C;
    int mul = 0;
    map<char, int> m_nums;

    cin >> A >> B >> C;
    mul = A * B * C;

    string str_mul = to_string(mul);

    for (int i = 0; i < str_mul.length(); i++)
        m_nums[str_mul[i]]++;

    for (int i = 0; i <= 9; i++)
    {
        cout << m_nums[i + '0'] << "\n";
    }
}