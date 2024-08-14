#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int N, K, cnt = 1;
    cin >> N >> K;

    vector<int> circle; 
    for (int i = 1; i <= N; i++)
        circle.push_back(i); 

    int index = 0; 
    cout << "<";

    while (!circle.empty()) {
        index = (index + K - 1) % circle.size(); 
        cout << circle[index]; 

        circle.erase(circle.begin() + index); 

        if (!circle.empty()) {
            cout << ", "; 
        }
    }

    cout << ">";
    return 0;
}
