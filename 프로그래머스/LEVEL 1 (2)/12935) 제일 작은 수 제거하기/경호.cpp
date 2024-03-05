#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    if(arr.size() == 1) return vector<int>{-1};
    
    vector<int>::iterator min_it = min_element(arr.begin(), arr.end());
    arr.erase(min_it);
    return arr;
}