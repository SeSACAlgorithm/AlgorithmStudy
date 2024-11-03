#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    Node(int id, int x, int y)
        : id(id), x(x), y(y) {}
    
    
    int id, x, y;
    
    Node* left = nullptr;
    Node* right = nullptr;
};

class BinarayTree
{
private:
    Node* root = nullptr;
    
    static bool compareNode(Node* a, Node* b)
    {
        if(a->y != b->y)
            return a->y > b->y;
        
        return a->x < b->x;
    }
    
    void preOrder(Node* node, vector<int>& answer)
    {
        if(node == nullptr)
            return;
        
        answer.push_back(node->id);
        preOrder(node->left,  answer);
        preOrder(node->right, answer);
    }
    
    void postOrder(Node* node, vector<int>& answer)
    {
        if(node == nullptr)
            return;
        
        postOrder(node->left, answer);
        postOrder(node->right,answer);                
        answer.push_back(node->id);
    }
    
    
public:
    BinarayTree() {}
    
    Node* addNode(Node* current, Node* newNode)
    {
        if(current == nullptr)
            return newNode;
        
        if(current->x > newNode->x)
            current->left = addNode(current->left, newNode);
        else
            current->right = addNode(current->right, newNode);
        
        return current;
    }
    
    void makeTree(const vector<vector<int>>& nodeinfo)
    {
        vector<Node*> nodes;
        
        for(int i = 0; i < nodeinfo.size(); ++i)
            nodes.push_back(new Node(i + 1, nodeinfo[i][0], nodeinfo[i][1]));
        
        sort(nodes.begin(), nodes.end(), compareNode);
        
        for(Node* node : nodes)
            root = addNode(root, node);
    }
    
    vector<vector<int>> result()
    {
        vector<vector<int>> answer(2);
        
        preOrder(root, answer[0]);
        postOrder(root, answer[1]);
        
        return answer;
    }
    
    
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo) 
{
    BinarayTree bt;
    bt.makeTree(nodeinfo);
    
    return bt.result();
}
