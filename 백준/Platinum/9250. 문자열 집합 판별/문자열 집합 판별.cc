#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int al = 26;

struct TrieNode {
    TrieNode* children[al];
    TrieNode* fail;
    bool word;
    TrieNode() {
        for (int i = 0; i < al; i++) {
            children[i] = nullptr;
        }
        fail = nullptr;
        word = false;
    }
};

class str {
public:
    str() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->word = true;
    }

    void buildfail() {
        queue<TrieNode*> q;
        root->fail = root;
        q.push(root);

        while (!q.empty()) {
            TrieNode* current = q.front();
            q.pop();

            for (int i = 0; i < al; i++) {
                TrieNode* child = current->children[i];
                if (child) {
                    if (current == root) {
                        child->fail = root;
                    } else {
                        TrieNode* failNode = current->fail;
                        while (failNode != root && !failNode->children[i]) {
                            failNode = failNode->fail;
                        }
                        if (failNode->children[i] && failNode->children[i] != child) {
                            failNode = failNode->children[i];
                        }
                        child->fail = failNode;
                    }
                    if (child->fail->word) {
                        child->word = true;
                    }
                    q.push(child);
                }
            }
        }
    }

    bool search(const string& text) {
        TrieNode* node = root;
        for (char c : text) {
            int index = c - 'a';
            while (node != root && !node->children[index]) {
                node = node->fail;
            }
            if (node->children[index]) {
                node = node->children[index];
            }
            if (node->word) {
                return true;
            }
        }
        return false;
    }

private:
    TrieNode* root;
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N;
    str ac;
    string word;

    for (int i = 0; i < N; ++i) {
        cin >> word;
        ac.insert(word);
    }

    ac.buildfail();

    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        cin >> word;
        if (ac.search(word)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}