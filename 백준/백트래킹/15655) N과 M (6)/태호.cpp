int n, m;
int arr[10];
int idx[10];
int sub[10];
bool vis[10];

void func(int cur)
{
     if(cur == m)
     {
         for(int i = 0; i < m; ++i)
             cout << arr[i] << ' ';

        cout << '\n';
	return;
      }

    int st = 0;

    if(cur != 0)
		st = sub[cur - 1] + 1;

    for(int i = st; i < n; ++i)
    {
        if(!vis[i])
        {
            sub[cur] = i;
            vis[i] = true;
            arr[cur] = idx[i];
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

    for(int i = 0; i < n; ++i)
        cin >> idx[i];

    sort(idx, idx + n);

    func(0);
}
