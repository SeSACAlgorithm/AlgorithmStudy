#define MAX 58

#include <iostream>
#include <string>

using namespace std;

int graph[MAX][MAX];
int answer = 0;

void FloydWarshall()
{
    for(int k = 0; k < MAX; k++)
    {
        for(int i = 0; i < MAX; i++)
        {
            for(int j = 0; j < MAX; j++)
            {
                if(graph[i][j] || i == j) continue;
                if(graph[i][k] && graph[k][j])
                {
                    graph[i][j] = 1;
                    answer++;
                }
            }
        }
    }
}

void Input()
{
    int N;
    cin >> N;
    cin.ignore();

    string str;
    int alphabet1, alphabet2;
    for(int i = 0; i < N; i++)
    {
        getline(cin, str);
        alphabet1 = str[0] - 'A';
        alphabet2 = str[str.size() - 1] - 'A';

        if(alphabet1 == alphabet2 || graph[alphabet1][alphabet2]) continue;
        answer++;
        graph[alphabet1][alphabet2] = 1;                                    // 관계 저장
    }
}

void Output()
{
    cout << answer << "\n";
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            if(graph[i][j]) 
            {
                cout << (char)(i + 'A') << " => " << (char)(j + 'A') << "\n";
            }
        }
    }
}

int main(void)
{
    Input();
    FloydWarshall();
    Output();
}