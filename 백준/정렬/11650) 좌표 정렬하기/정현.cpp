#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);               

    int N; 
    cin >> N;

    vector<pair<int, int>> vec(N); // 좌표를 저장할 벡터 크기를 미리 N으로 지정

    // 좌표를 입력받아 벡터에 저장
    for (int i = 0; i < N; i++) {
        cin >> vec[i].first >> vec[i].second; // 각 pair의 first와 second에 값에 입력
    }

    // 좌표 정렬
    sort(vec.begin(), vec.end());

    for (int i = 0; i < N; i++) {
        cout << vec[i].first << " " << vec[i].second << '\n';
    }

    return 0;
}
