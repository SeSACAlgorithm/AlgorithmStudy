#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    bool arr[3001] = { false, };

    if (n == 1) return 1;

    for (int i = 1; i <= n / 2; i++)
    {
        if (arr[i] == false) {
            if (n % i == 0)
            {
                int num = n / i;
                answer += i;
                // 4일 때, 2 2가 나오니까 그 경우 제외
                if(i != num)
                    answer += num;

                arr[i] = true;
                arr[num] = true;
            }
        }
    }

    return answer;
}