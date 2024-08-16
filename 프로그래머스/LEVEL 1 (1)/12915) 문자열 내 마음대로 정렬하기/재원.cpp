#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

//1. 해당 인덱스의 문자를 제일 앞에 추가하기 
//2. 정렬하기 
//3. 추가된 첫번제 문자를 제거하기 
//4. 반환하기

vector<string> solution(vector<string> strings, int n) {
   vector<string> answer;
  string temp;
  char AddWord;  
    //문자 인덱스 추가
    for(int i=0;i<strings.size();i++)
    {
        temp=strings[i];
        AddWord=temp[n];
        strings[i]=AddWord+temp;
    }
    //문자 정렬 
    std::sort(strings.begin(), strings.end());
    //추가한 문자 제거 
    for(int i=0;i<strings.size();i++)
    {
        temp=strings[i];
        temp.erase(0, 1);
        strings[i]=temp;
    }
    answer= strings;
      
    return answer;
}
