#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void minmax(int N)
{
    vector<int> arr;
    int num=0;

    for(int i=0; i<N; i++)
    {
        cin>>num;
        arr.push_back(num);
    }

    sort(arr.begin(), arr.end(), greater<int>());

    cout<<arr.back()<<" "<<arr.front()<<'\n';
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, N;
    cin>>T;

    for(int i=0; i<T; i++)
    {
        cin>>N;
        minmax(N);
    }
}