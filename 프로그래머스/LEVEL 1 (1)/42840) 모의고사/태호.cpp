#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr1[5] = {1, 2, 3, 4, 5};
int arr2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int arr3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int a = 0, b = 0, c = 0;
    for(int i = 0; i < answers.size(); ++i)
    {
        if(answers[i] == arr1[i % 5]) ++a;
         if(answers[i] == arr2[i % 8]) ++b;
         if(answers[i] == arr3[i % 10]) ++c;
    }
    
    if(a == b && b == c)
        for(int i = 1; i < 4; ++i)
            answer.push_back(i);
    
    else if(a > b && a == c)
    {
        answer.push_back(1);
        answer.push_back(3);
    }
    else if(a > c && a == b)
    {
        answer.push_back(1);
        answer.push_back(2);
    }
    else if(a < b && b == c)
    {
        answer.push_back(2);
        answer.push_back(3);
    }
    else if(a > b && a > c)
    {
        answer.push_back(1);
    }
    else if(b > a && b > c)
    {
        answer.push_back(2);
    }
    else if(c > a && c > b)
    {
        answer.push_back(3);
    }
    

    
    return answer;
}
