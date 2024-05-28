#include "iostream"
#include "algorithm"

using namespace std;

int main()
{
    int n[6];
    
    for(int i=1; i<=5; i++)
        cin >> n[i];

    for(int i=5; i>=1; i--)
        for(int j=1; j<i; j++)
        {
            if(n[j] > n[j+1])
            {
                swap(n[j], n[j+1]);
                for(int k=1; k<=5; k++)
                    cout << n[k] << " ";

                cout << "\n";
            }
        }
    
}