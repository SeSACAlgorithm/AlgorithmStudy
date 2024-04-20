vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    int idx = 0;

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < columns; ++j)
            board[i][j] = ++idx;

    for (int i = 0; i < queries.size(); ++i)
    {
        int y1 = queries[i][0] - 1, x1 = queries[i][1] - 1;
        int y2 = queries[i][2] - 1, x2 = queries[i][3] - 1;

        int n = 4;
        int pre = board[y1][x1];
        pair<int, int> cur = { y1, x1 };
        int mn = pre;

        while (n)
        {
            int temp;

            if (n == 4)
            {
                ++cur.second;
                temp = board[y1][cur.second];
                board[y1][cur.second] = pre;
                pre = temp;

                if (cur.second == x2)
                    --n;

                mn = min(mn, board[y1][cur.second]);
            }
            else if (n == 3)
            {
                ++cur.first;

                temp = board[cur.first][x2];
                board[cur.first][x2] = pre;
                pre = temp;

                if (cur.first == y2)
                    --n;

                mn = min(mn, board[cur.first][x2]);
            }
            else if (n == 2)
            {
                --cur.second;
                temp = board[y2][cur.second];
                board[y2][cur.second] = pre;
                pre = temp;

                if (cur.second == x1)
                    --n;

                mn = min(mn, board[y2][cur.second]);
            }
            else if (n == 1)
            {
                --cur.first;

                temp = board[cur.first][x1];
                board[cur.first][x1] = pre;
                pre = temp;

                if (cur.first == y1)
                    --n;

                mn = min(mn, board[cur.first][x1]);
            }

        }

        answer.push_back(mn);
    }

    return answer;
}
