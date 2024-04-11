#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

long long solution(string expression) {
     long long answer = 0;

     vector<map<char, int>> priority(6);
     priority[0] = { {'+', 1}, {'-', 2}, {'*', 3} };
     priority[1] = { {'+', 1}, {'*', 2}, {'-', 3} };
     priority[2] = { {'-', 1}, {'+', 2}, {'*', 3} };
     priority[3] = { {'-', 1}, {'*', 2}, {'+', 3} };
     priority[4] = { {'*', 1}, {'+', 2}, {'-', 3} };
     priority[5] = { {'*', 1}, {'-', 2}, {'+', 3} };

     for (int i = 0; i < 6; i++)
     {
         long long result = 0;
         queue<long long> nums;
         queue<char> operators;
         int idx = 0;
         for (int i = 0; i < expression.size(); i++)
         {
             if (isdigit(expression[i])) continue;

             nums.push(stoll(expression.substr(idx, i - idx)));
             operators.push(expression[i]);
             idx = i + 1;
         }
         nums.push(stoll(expression.substr(idx, expression.size() - idx)));

         for (int order = 0; order < 3; order++)
         {
             int limit = nums.size() - 1;
             long long a = nums.front(), b = 0;
             nums.pop();
             char oper;

             for (int j = 0; j < limit; j++)
             {
                 b = nums.front();
                 nums.pop();

                 oper = operators.front();
                 operators.pop();

                 if (priority[i][oper] == order + 1)
                 {
                     long long tmp = 0;
                     switch (oper)
                     {
                     case '+':
                         tmp = a + b;
                         break;
                     case '-':
                         tmp = a - b;
                         break;
                     case '*':
                         tmp = a * b;
                         break;
                     }
                     a = tmp;
                 }
                 else
                 {
                     nums.push(a);
                     a = b;
                     operators.push(oper);
                 }
             }
             nums.push(a);
         }

         result = abs(nums.front());
         if (answer < result)
             answer = result;
     }

     return answer;
}