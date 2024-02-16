#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct TrieNode {
    map<string, TrieNode*> children;
};

void insertTrie(TrieNode* root, const vector<string>& path) {
    TrieNode* curr = root;
    for (const string& str : path) {
        if (curr->children.find(str) == curr->children.end()) {
            curr->children[str] = new TrieNode();
        }
        curr = curr->children[str];
    }
}

void printTree(TrieNode* node, int depth) {
    for (auto& child : node->children) {
        for (int i = 0; i < depth; ++i) {
            cout << "--";
        }
        cout << child.first << '\n';
        printTree(child.second, depth + 1);
    }
}

int main() {
    int N;
    cin >> N;

    TrieNode* root = new TrieNode();

    for (int i = 0; i < N; ++i) {
        int K;
        cin >> K;
        vector<string> ant_path(K);
        for (int j = 0; j < K; ++j) {
            cin >> ant_path[j];
        }
        insertTrie(root, ant_path);
    }

    printTree(root, 0);

    return 0;
}