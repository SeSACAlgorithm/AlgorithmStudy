#include <iostream>

using namespace std;

struct Node
{
    Node(Node* lc, Node* rc, int num)
        : left(lc), right(rc), node(num) {};

	Node* left;
	Node* right;

    int node;
};

struct BinaryTree 
{
private:
    Node* root = nullptr;

    Node* Insert(Node* current, Node* newNode)
    {
	  if (current == nullptr)
		return newNode;

	  if (current->node > newNode->node)
		current->left = Insert(current->left, newNode);
		else
		current->right = Insert(current->right, newNode);

	   return current;
     }

     void PostOrder(Node* current)
     {
          if(current == nullptr)
              return;

          if(current->left)
	      PostOrder(current->left);
		
          if(current->right)
               PostOrder(current->right);

	   cout << current->node << '\n';
      }

public:
    void MakeNode(int value)
    {
        root = Insert(root, new Node(nullptr, nullptr, value));
    }

    void CallPostOrder()
    {
        PostOrder(root);
    }
};


int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int node;
    BinaryTree BT;


    while (cin >> node)
        BT.MakeNode(node);

    BT.CallPostOrder();

    return 0;
}
