#include <string>
#include <vector>
//조건1.brown yellow의 합은 가로 세로길이의 곱이다
//조건2.가로가 더 길거나 같은 상황에서 가로의 길이 
//조건3. yellow의 크기는 (가로길이 -2)*(세로길이-2)이다
//조건4. brown의 크기는(가로길이 + 세로길이)*2-4
using namespace std;

bool qualification3(int width,int height,int yellow)
{
    if(yellow==(width-2)*(height-2))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool qualification4(int width,int height,int brown)
{
    if(brown==(width+height)*2-4)
    {
        return true;
    }
    else
    {
        return false;
    }
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int s_size = brown+yellow; //사각형의 크기
    int width;//가로 
    int height;//세로
    
    for(int i=1;i<=s_size;i++)
    {
        if(s_size%i==0)
        {
            height=i;
            width=s_size/height;
            if(qualification3(width,height,yellow)&&qualification4(width,height,brown))
            {
                answer.push_back(width);
                answer.push_back(height);
                break;
            }
        }

    }
    return answer;
}
