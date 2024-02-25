#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    int cnt = 1;
    cin >> num;

    stack<int> basic;
    vector<char> cal;

    for (int i = 0; i < num; i++) {
        int tmp;
        cin >> tmp;

        while (cnt <= tmp) {
            cal.push_back('+');
            basic.push(cnt);
            cnt++;
        }

        if (basic.top() == tmp) {
            basic.pop();
            cal.push_back('-');
        }
        else {
            cout << "NO" << endl;
            return 0;
        }

        
    }
    
    for (int i = 0; i < cal.size(); i++)
        cout << cal[i] << '\n';


    
}

