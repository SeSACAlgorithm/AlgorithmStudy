#include <iostream>

using namespace std;

int n, m;

bool vis[10];
int arr[10];

void func(int cur)
{
    if(cur == m)
    {
        for(int i = 0; i < cur - 1; ++i)
	    if(arr[i] > arr[i + 1])
		return;

	  for(int i = 0; i < cur; ++i)
	      cout << arr[i] << ' ';

      	cout << '\n';
	return;
    }

    for(int i = 1; i <= n; ++i)
    {
        if(!vis[i])
        {
            vis[i] = true;
            arr[cur] = i;
            func(cur + 1);
            vis[i] = false;
        }

    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    func(0);
}
