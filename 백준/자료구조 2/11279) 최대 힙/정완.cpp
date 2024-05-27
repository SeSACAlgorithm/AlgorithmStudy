#include "iostream"
#include "queue"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int x;
    cin >> n;
    priority_queue<int> pq;


    for(int i=0; i<n; i++)
    {
        cin >> x;

        if(x !=0)
            pq.push(x);

        else
        {
            if(pq.empty())
                cout << "0" << "\n";

            else
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }
}