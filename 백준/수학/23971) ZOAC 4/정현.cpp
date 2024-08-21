#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int H, W, N, M;
    cin >> H >> W >> N >> M;
    
    int col = (H - 1) / (N + 1) + 1;
    int row = (W - 1) / (M + 1) + 1;

    cout << col * row << '\n';

    return 0;
}
