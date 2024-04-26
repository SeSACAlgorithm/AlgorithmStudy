bool vis[60002];

int solution(vector<vector<int>> routes) {

    int answer = 0;
    sort(routes.begin(), routes.end(), [](vector<int>& A, vector<int>& B)
    {
		if(A[1] == B[1])
			return A[0] < B[0];

        return A[1] < B[1];
    });

    for(int i = 0; i < routes.size(); ++i)
    {
	    int a = routes[i][0] + 30000, b = routes[i][1] + 30000;
        bool visted = true;

        for(int i = a; i <= b; ++i)
        {
	        if(vis[i])
	        {
                visted = false;
                break;
	        }
        }

        if(visted)
        {
            ++answer;
            vis[b] = true;
        }
			
    }

    return answer;
}
