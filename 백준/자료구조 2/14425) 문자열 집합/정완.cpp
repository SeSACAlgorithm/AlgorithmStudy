#include "iostream"
#include "map"

using namespace std;

int main()
{
    int ans = 0;
    int N, M;
    cin >> N >> M;
    string str;
    map<string, int> Map;


    for(int i=0; i<N; i++)
    {
        cin >> str;
        Map[str]++;
    }

    for(int i=0; i<M; i++)
    {
        cin >> str;

        if(Map[str])
            ans++;
    }

    cout << ans;
}