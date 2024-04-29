#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int T;
    cin >> T;

    for(int i = 0; i < T; i++)
    {
        int num;
        string wrong;

        cin >> num >> wrong;

        for(int i=0; i < wrong.size(); i++)
        {
            if(i != num - 1)
                cout << wrong[i];
        }

        cout << "\n";
    }
}