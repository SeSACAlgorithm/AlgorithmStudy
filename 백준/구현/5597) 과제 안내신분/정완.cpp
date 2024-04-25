#include <iostream>

using namespace std;

int main() {

  int students[31] = {0, };
  int all = 30;
  int student = 28;
  int n;

  for(int i = 0; i<student; i++)
  {
    cin>>n;
    students[n] = 1;
  }

  for(int j=1; j<=all; j++)
  {
    if(!students[j])
        cout<<j<<endl;
  }

  return 0;
}