#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    int a=0;
    int b=0;
    int c=0;
    vector<int> ans;
    vector<int> rank;
    
    int arr1[5] = {1,2,3,4,5};
    int arr2[8] = {2,1,2,3,2,4,2,5};
    int arr3[10] = {3,3,1,1,2,2,4,4,5,5};
    
    for(int i=0; i<answers.size(); i++)
    {
        if(answers[i] == arr1[i%5])
            a++;
        
        if(answers[i] == arr2[i%8])
            b++;
        
        if(answers[i] == arr3[i%10])
            c++;
    }
    
    int high = max(a,b);
    high = max(high, c);
    
    if(high == a) ans.push_back(1);
    if(high == b) ans.push_back(2);
    if(high == c) ans.push_back(3);
    
    return ans;
}
