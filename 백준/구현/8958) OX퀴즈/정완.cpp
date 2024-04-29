#include <iostream>
#include <string>

using namespace std;

int main()
{
    int test;
    cin >> test;

    for(int i=0; i<test; i++)
    {
        string ox;
        cin >> ox;
        
        int sum, chk;
        sum = chk = 0;

        for(int j=0; j<ox.size(); j++)
        {
            if(ox[j] == 'O')
                chk++;
            else
                chk = 0;

            sum += chk;
        }

        cout << sum << '\n';
    }
}