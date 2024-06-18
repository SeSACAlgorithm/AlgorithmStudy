#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    stack<pair<int, int>> Stk;
    Stk.push({ 0, 100000002 });
    
    vector<int> vec;

    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        pair<int, int> num = Stk.top();
        
        while (x > num.second)
        {
            Stk.pop();
            num = Stk.top();
        }
       
        vec.push_back(num.first);
        Stk.push({ i + 1, x });

    }

    for (int i = 0; i < vec.size(); ++i)
        cout << vec[i] << ' ';

}
