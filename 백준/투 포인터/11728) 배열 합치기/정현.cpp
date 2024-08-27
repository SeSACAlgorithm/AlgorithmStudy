#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0); 
    
    int N, M;
    cin >> N >> M;

    vector<int> arr1(N); 
    vector<int> arr2(M); 

    for (int i = 0; i < N; ++i) {
        cin >> arr1[i]; 
    }

    for (int i = 0; i < M; ++i) {
        cin >> arr2[i]; 
    }

    int i = 0, j = 0;
    vector<int> res; 

    // 두 배열을 순회하며 작은 값부터 결과 배열에 추가
    while (i < N && j < M) {
        if (arr1[i] < arr2[j]) {
            res.push_back(arr1[i++]); // arr1의 값이 작으면 결과 배열에 추가하고 i 증가
        } else {
            res.push_back(arr2[j++]); // arr2의 값이 작으면 결과 배열에 추가하고 j 증가
        }
    }

    // 남아있는 요소들을 결과 배열에 추가
    while (i < N) {
        res.push_back(arr1[i++]);
    }

    while (j < M) {
        res.push_back(arr2[j++]);
    }

  
    for (int k = 0; k < res.size(); ++k) {
        cout << res[k] << " ";
    }
    cout << "\n";

    return 0;
}
