#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    
    // 내림차순
    sort(d.begin(), d.end(), greater<int>());
    
    int totAmount = 0;
    for(int i = 0; i < d.size(); i++){
        totAmount += d[i];
    }
    
    int currentBudget = 0;
    int k = 0;
    currentBudget = totAmount;
    while(currentBudget > budget){
        currentBudget = currentBudget - d[k];
        k++;
    }
    
    answer = d.size() - k;
    
    return answer;
}
