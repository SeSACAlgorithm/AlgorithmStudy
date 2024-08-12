#include "iostream"
#include "string"

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int cnt = 0;
    string str;

    for(int i=0; i<=n; i++)
    {
        for (int j=0; j<=59; j++)
        {
            for(int k=0; k<=59; k++)
            {
                if(i / 10 == 0)
                    str += "0";
                str += to_string(i);

                if(j / 10 == 0)
                    str += "0";
                str += to_string(j);

                if(k / 10 == 0)
                    str += "0";
                str += to_string(k);

                if(str.find(to_string(m)) != -1)
                    cnt++;

                str.clear();
            }
        }
        
    }

    cout << cnt;
}