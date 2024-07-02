#include<iostream>
#include <string>

using namespace std;

int tree_num[5];

void swap_tree_num(int index)
{
    int temp = tree_num[index];
    tree_num[index] = tree_num[index + 1];
    tree_num[index + 1] = temp;
}

int main(void)
{
    string tree_str;

    for(int i = 0; i < 5; i++)
    {
        cin >> tree_num[i];
        tree_str += to_string(tree_num[i]);
    }

    int i = 0;
    while(tree_str != "12345")
    {
        if(tree_num[i] > tree_num[i+1]) 
        {
            swap_tree_num(i);

            tree_str = "";
            for(int j = 0; j < 5; j++) 
            {
                tree_str += to_string(tree_num[j]);
                cout << tree_str[j] << " ";
            }
            cout << "\n";
        }

        i++;
        if(i == 4) i = 0;
    }
}