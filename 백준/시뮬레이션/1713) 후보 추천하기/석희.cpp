#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
    int studentNum, recommand, date;
    node(int s, int r, int d) : studentNum(s), recommand(r), date(d) {}
};

struct cmp
{
    bool operator()(node n1, node n2) const
    {
        if(n1.recommand == n2.recommand) return n1.date < n2.date;
        return n1.recommand < n2.recommand;
    }
};

int n;
int date = 0;
bool check = false;

set<node, cmp> sPhoto;                       // 사진틀(학생 번호, 추천 수, 날짜)

void RecommandStudents(int num)
{
    date++;
    check = false;

    // 이미 게시되어있는 학생
    for(auto it : sPhoto)
    {
        if(it.studentNum == num) 
        {
            sPhoto.insert({num, it.recommand+1, it.date});
            sPhoto.erase(it);
            check = true;
            break;
        }
    }

    // 게시되어 있었던 학생 X
    if(!check)
    {
        // 비어있는 사진틀 없음
        if(sPhoto.size() >= n)
        {
            sPhoto.erase(sPhoto.begin());           // 학생 삭제
        }
        
        sPhoto.insert({num, 1, date});              // 새 학생 추가 
    }
}

void Input()
{
    int recommandCount;

    cin >> n;
    cin >> recommandCount;

    int num;
    for(int i = 0; i < recommandCount; i++)
    {
        cin >> num;
        RecommandStudents(num);
    }
}

void Solve()
{
    vector<int> vAnswer;

    for(auto s : sPhoto)
    {
        vAnswer.push_back(s.studentNum);
    }

    sort(vAnswer.begin(), vAnswer.end());
    for(int i = 0; i < vAnswer.size(); i++)
    {
        cout << vAnswer[i] << " ";
    }
}

int main(void)
{
    Input();
    Solve();
}