#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    int sum = 0;
    // 3���� ���ҵ� ���ϱ�
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                sum = nums[i] + nums[j] + nums[k];
                //sum�� �Ҽ����� Ȯ��
                bool Decimal = true;

                for (int a = 2; a < sum; a++) {
                    if (sum % a == 0) {
                        Decimal = false;
                        break;
                    }
                }
                if (Decimal) answer++;
            }

        }
    }


    return answer;
}