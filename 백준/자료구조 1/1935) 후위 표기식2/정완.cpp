#include <iostream>
#include <vector>
#include <stack>

using namespace std;

double calculate(double num1, double num2, char calc)
{
    if(calc == '+')
        return num1 + num2;

    else if(calc == '-')
        return num1 - num2;

    else if(calc == '*')
        return num1 * num2;
    
    else if(calc == '/')
        return num1 / num2;
    
    return 0;
}

int main(void)
{
    int cnt;
    cin >> cnt;

    string str;
    cin >> str;

    vector<double> vec;
    stack<double> stk;

    double num;

    for(int i=0; i<cnt; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    double num1 = 0, num2 = 0;

    for(int i=0; i<str.size(); i++)
    {
        if(isalpha(str[i]))             // 숫자인 경우
            stk.push(vec[str[i] - 'A']);

        else                            // 연산자인 경우
        {
            num2 = stk.top(); stk.pop();

            num1 = stk.top(); stk.pop();

            stk.push(calculate(num1, num2, str[i]));
        }
    }

    cout << fixed;                      // 고정 소수점 형식 적용
    cout.precision(2);                  // 소수점 2자리
    cout << stk.top();


}