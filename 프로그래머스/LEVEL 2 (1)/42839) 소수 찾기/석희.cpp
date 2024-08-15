#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

// 소수인지 확인
bool isPrime(int n)
{
    if (n < 2) return false;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(string numbers)
{
    int answer = 0;
    vector<char> v_c_num;
    vector<int> v_i_num;

    for (int i = 0; i < numbers.size(); i++)
    {
        v_c_num.push_back(numbers[i]);
    }

    // next_permutation을 사용하려면 오름차순 정렬해야 함
    sort(v_c_num.begin(), v_c_num.end());

    // 숫자 조합 만들기
    do
    {
        string temp = "";
        for (int i = 0; i < v_c_num.size(); i++)
        {
            // 구한 순열로 문자열 만들기
            temp += v_c_num[i];
            v_i_num.push_back(stoi(temp));
        }
    } while (next_permutation(v_c_num.begin(), v_c_num.end()));

    // 중복 제거
    set<int> s_num(v_i_num.begin(), v_i_num.end());

    // 소수인지 확인
    for (auto num : s_num)
    {
        if (isPrime(num)) answer++;
    }

    return answer;
}