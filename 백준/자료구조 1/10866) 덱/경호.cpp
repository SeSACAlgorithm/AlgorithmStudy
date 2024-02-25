#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n ;
    cin >> n;

    map<string, int> idxes{ {"push_front", 1}, {"push_back", 2} , {"pop_front", 3} , {"pop_back", 4},
                            {"size", 5} , {"empty", 6} , {"front", 7} , {"back", 8}};

    int size = 0;
    vector<int> datas(20001, 0);
    int front = 10000, back = 10000;

    string query = "";
    int value = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> query;

        int idx = idxes[query];
        switch (idx)
        {
        case 1: // push_front
            cin >> value;
            front--;
            datas[front] = value;
            size++;
            if (size == 1) back = front;
            break;
        case 2: // push_back
            cin >> value;
            back++;
            datas[back] = value;
            size++;
            if (size == 1) front = back;
            break;
        case 3: // pop_front
            if (size == 0) cout << -1 << endl;
            else
            {
                cout << datas[front] << endl;
                front++;
                size--;
            }
            break;
        case 4: // pop_back
            if (size == 0) cout << -1 << endl;
            else
            {
                cout << datas[back] << endl;
                back--;
                size--;
            }
            break;
        case 5: // size
            cout << size << endl;
            break;
        case 6: // empty
            cout << (size == 0) << endl;
            break;
        case 7: // front
            if (size == 0) cout << -1 << endl;
            else cout << datas[front] << endl;
            break;
        case 8: // back
            if (size == 0) cout << -1 << endl;
            else cout << datas[back] << endl;
            break;
        }
    }
}