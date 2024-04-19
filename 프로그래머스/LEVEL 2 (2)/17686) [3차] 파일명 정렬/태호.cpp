#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


struct FileStream
{
    string Head;
    string originHead;
    string Number;
    string Tail = "";
};

bool cmp(const FileStream& A, const FileStream& B)
{
    if (A.Head == B.Head)
    {
        int a = stoi(A.Number);
        int b = stoi(B.Number);
        if (stoi(A.Number) == stoi(B.Number))
        {
            return false;
        }

        return a < b;
    }

    return A.Head < B.Head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<FileStream> vecString;

    for (int i = 0; i < files.size(); ++i)
    {
        string str = "";
        FileStream FS;

        bool bHead = false;
        bool bNumber = false;

        for (int j = 0; j < files[i].size(); ++j)
        {
            if (!bHead && isdigit(files[i][j]))
            {
                FS.originHead = str;
                transform(str.begin(), str.end(), str.begin(), ::tolower);
                FS.Head = str;
                str = "";
                bHead = true;
            }
            else if (bHead && !bNumber && !isdigit(files[i][j]))
            {
                FS.Number = str;
                str = "";
                bNumber = true;
            }

            str += files[i][j];
        }

        if (!str.empty())
        {
            if(FS.Number.empty())
                FS.Number = str;
            else
                FS.Tail = str;
        }
            

        vecString.push_back(FS);
    }

    sort(vecString.begin(), vecString.end(), cmp);

    for (int i = 0; i < vecString.size(); ++i)
        answer.push_back(vecString[i].originHead + vecString[i].Number + vecString[i].Tail);

    return answer;
}
