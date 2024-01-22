#include <iostream>
#include <unordered_map>
using namespace std;

class TreeNode {
public:
    char data;
    TreeNode* left;
    TreeNode* right;

    // 트리 노드 생성자
    TreeNode(char value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    TreeNode* root;

public:
    // 이진 트리 생성
    void buildTree(int n) {
        unordered_map<char, TreeNode*> nodeMap;

        for (int i = 0; i < n; ++i) {
            char parent, leftChild, rightChild;
            cin >> parent >> leftChild >> rightChild;

            TreeNode* parentNode = getNode(parent, nodeMap);

            if (leftChild != '.') {
                parentNode->left = getNode(leftChild, nodeMap);
            }

            if (rightChild != '.') {
                parentNode->right = getNode(rightChild, nodeMap);
            }
        }

        root = getNode('A', nodeMap); // 루트 노드 설정
    }

    // 전위 순회
    void preorderTraversal(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        cout << node->data; // 루트 노드 출력
        preorderTraversal(node->left); // 왼쪽 서브트리 전위 순회
        preorderTraversal(node->right); // 오른쪽 서브트리 전위 순회
    }

    // 중위 순회
    void inorderTraversal(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        inorderTraversal(node->left); // 왼쪽 서브트리 중위 순회
        cout << node->data; // 루트 노드 출력
        inorderTraversal(node->right); // 오른쪽 서브트리 중위 순회
    }

    // 후위 순회
    void postorderTraversal(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        postorderTraversal(node->left); // 왼쪽 서브트리 후위 순회
        postorderTraversal(node->right); // 오른쪽 서브트리 후위 순회
        cout << node->data; // 루트 노드 출력
    }

    // 노드 생성 또는 가져오기
    TreeNode* getNode(char value, unordered_map<char, TreeNode*>& nodeMap) {
        if (nodeMap.find(value) == nodeMap.end()) {
            nodeMap[value] = new TreeNode(value);
        }

        return nodeMap[value];
    }

    // 전위, 중위, 후위 순회 결과 출력
    void printTraversals() {
        preorderTraversal(root);
        cout << "\n";

        inorderTraversal(root);
        cout << "\n";

        postorderTraversal(root);
        cout << "\n";
    }
};

int main() {
    int n;
    cin >> n;

    BinaryTree tree;
    tree.buildTree(n);
    tree.printTraversals();

    return 0;
}