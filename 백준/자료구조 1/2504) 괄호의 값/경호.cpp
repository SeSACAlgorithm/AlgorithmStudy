#include <iostream>
#include <numeric>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void calculate_value(stack<int>& stk, vector<vector<int>>& layers, int value)
{
    stk.pop();
    int cur_layer = stk.size();
    // 하위 레이어에 데이터가 있다면 곱셈
    int low_data = 1;
    if (false == layers[cur_layer + 1].empty())
    {
        low_data = accumulate(layers[cur_layer + 1].begin(), layers[cur_layer + 1].end(), 0);
        layers[cur_layer + 1].clear();
    }
    layers[cur_layer].emplace_back(low_data * value);
}

int main()
{
    string data;
    cin >> data;

    int small = 2; // 소괄호
    int big = 3;    // 대괄호

    stack<int> stk;
    vector<vector<int>> layers(30, vector<int>());

    for(const char& c : data)
    {
        if(c == '(')
        {
            stk.push(small); 
        }
        else if(c == ')')
        {
            if (stk.empty() || stk.top() != small)
            {
                cout << 0;
                return 0;
            }
            calculate_value(stk, layers, small);
        }
        else if(c == '[')
        {
            stk.push(big); 
        }
        else if(c == ']')
        {
            if (stk.empty() || stk.top() != big)
            {
                cout << 0;
                return 0;
            }
            calculate_value(stk, layers, big);
        }
    }
    
    cout << accumulate(layers[0].begin(), layers[0].end(), 0);
}