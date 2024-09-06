#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// 트리 구현용 구조체
struct node
{
    node* left;
    node* right;
    int value;
};

// 트리 후위 순회용 재귀 함수
// 출력 후에는 메모리 반환을 위해 delete
void post_order(const node* root)
{
    if (nullptr != root->left) post_order(root->left);
    if (nullptr != root->right) post_order(root->right);
    cout << root->value << "\n";
    delete root;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 루트 노드 생성
    int root_val;
    cin >> root_val;
    node* root = new node();
    root->value = root_val;

    // 전위 순회 결과를 이용하여 이진 검색 트리 구성
    int value;
    node* cur = root;
    while (cin >> value)
    {
        // 새 노드 생성
        node* new_node = new node();
        new_node->value = value;
        // 루트부터 내려가며 현재 노드의 값보다 작다면 왼쪽, 크다면 오른쪽으로 이동
        // 이동할 방향이 nullptr이라면 해당 방향에 할당
        while(nullptr != cur)
        {
	    if(cur->value > value)
	    {
                if (nullptr == cur->left)
                {
                    cur->left = new_node;
                    break;
                }
                cur = cur->left;
	    }
            else
            {
                if (nullptr == cur->right)
                {
                    cur->right = new_node;
                    break;
                }
                cur = cur->right;
            }
        }
        // 다음 검색을 위해 루트로 초기화
        cur = root;
    }
    // 완성된 이진 검색 트리를 후위 순회
    post_order(root);
}
