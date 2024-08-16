#include "iostream"
#include "map"
#include "vector"
#include "algorithm"

using namespace std;

int main()
{
    map<string, int> m;
    vector<pair<int, string>> v;

    int K, L;
    cin >> K >> L;

    for(int i=0; i<L; i++)      // 학번, 순번 map에 저장
    {
        string number;
        cin >> number;

        m[number] = i+1;
    }

    for(auto entry : m)         // 최종 학번, 순번 vector에 저장
        v.push_back({entry.second, entry.first});

    sort(v.begin(), v.end());   // 저장된 vector 정렬

    for(int i=0; i<min(K, (int)v.size()); i++)  // 0 번 인덱스부터 K 또는 vector의 크기만 큼 결과 출력
        cout << v[i].second << "\n";
}