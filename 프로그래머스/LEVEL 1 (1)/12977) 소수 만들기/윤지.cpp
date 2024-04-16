#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    vector<int> Decimals;

    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                sum = nums[i] + nums[j] + nums[k];
                // 소수 판별   
                bool check = false;
                for (int a = 2; a * a <= sum; a++) {
                    if (sum % a == 0) {
                        check = true;
                        break;
                    }
                }

                if (check == false) answer++;
            }
        }
    }

    return answer;
}