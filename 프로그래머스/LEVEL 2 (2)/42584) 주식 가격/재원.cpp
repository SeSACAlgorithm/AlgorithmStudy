#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<int> st; 

    for (int i = 0; i < prices.size(); i++) {
    
        while (!st.empty() && prices[i] < prices[st.top()]) {
            int idx = st.top();  
            st.pop();            
            answer[idx] = i - idx;  
        }
        st.push(i);  
    }

    
    while (!st.empty()) {
        int idx = st.top();
        st.pop();
        answer[idx] = prices.size() - 1 - idx;  
    }

    return answer;
}
