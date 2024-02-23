#include<iostream>
#include<deque>

using namespace std;

int main (void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    deque<int> d;
    string str;

    for(int i = 0; i < n; i++) {
        cin >> str;
            int dq;

        if(str == "push_front") {
            cin >> dq;
            d.push_front(dq);
        } else if (str == "push_back") {
            cin >> dq;
            d.push_back(dq);
        } else if (str == "pop_front") {
            if (d.empty()) {
                cout << "-1" << "\n";
            } else {
                cout << d.front() << "\n";
                d.pop_front();
            }
        } else if (str == "pop_back") {
            if (d.empty()) {
                cout << "-1" << "\n";
            } else {
                cout << d.back() << "\n";
                d.pop_back();
            }
        } else if (str == "size") {
            cout << d.size() << "\n";
        } else if (str == "empty") {
            if (d.empty()) {
                cout << "1" << "\n";
            } else {
                cout << "0" << "\n";
            }
        } else if (str == "front") {
            if (d.empty()) {
                cout << "-1" << "\n";
            } else {
                cout << d.front() << "\n";
            }
        } else if (str == "back") {
            if (d.empty()) {
                cout << "-1" << "\n";
            } else {
                cout << d.back() << "\n";
            }
        }
    }
      return 0;
} 
