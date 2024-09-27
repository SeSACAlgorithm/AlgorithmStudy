#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    int n = s.size(); //매번 사이즈 검사를 하지 않기 위해 넣어두기
    int minLength = n; //최소 사이즈 지정 

    for (int blockSize = 1; blockSize <= n / 2; ++blockSize)//블럭사이즈는 최대 본래 s의 절반까지만 줄어들수 있음
    {
        string compressed;
        string prev = s.substr(0, blockSize); 
        int count = 1;

        for (int j = blockSize; j < n; j += blockSize) {
            string curr = s.substr(j, blockSize);
            if (prev == curr) {
                count++; //잘라낸 단어가 일치하면 증가 
            } else {
                compressed += prev;//틀리면 잘라낸 단어를 붙이고
                if (count > 1) {
                    compressed += to_string(count);//굳이 숫자가 앞에 붙을 필요가 없으므로 카운트를 더한다 
                }
                prev = curr;
                count = 1;
            }
        }

        // 마지막 블록 추가
        compressed += prev;
        if (count > 1) {
            compressed += to_string(count);
        }

        minLength = min(minLength, (int)compressed.size()); //최솟값구하기 
    }

    return minLength;
    
    
   
    return answer=minLength;
}
