#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<bool> not_homework(30, true);

    int n;
    for(int i = 0; i < 28; ++i)
    {
        cin >> n;
        not_homework[n - 1] = false;
    }
		
    for (int i = 0; i < 30; ++i)
    {
        if (not_homework[i])
            cout << i + 1 << endl;
    }
}