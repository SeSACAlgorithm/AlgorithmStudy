#include "iostream"
#include "queue"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int N;
    cin >> N;
    int num = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<N*N; i++)
    {
        cin >> num;
        pq.push(num);

        if(pq.size() > N)
            pq.pop();
    }

    cout << pq.top();
}