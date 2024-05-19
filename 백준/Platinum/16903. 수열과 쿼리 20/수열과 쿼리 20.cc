#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int MAX_BIT = 30;

struct TrieNode {
    TrieNode* children[2];
    int count;

    TrieNode() {
        children[0] = children[1] = nullptr;
        count = 0;
    }
};

class BitwiseTrie {
public:
    BitwiseTrie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;
        for (int i = MAX_BIT; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!node->children[bit]) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
            node->count++;
        }
    }

    void remove(int num) {
        TrieNode* node = root;
        for (int i = MAX_BIT; i >= 0; --i) {
            int bit = (num >> i) & 1;
            TrieNode* child = node->children[bit];
            child->count--;
            if (child->count == 0) {
                node->children[bit] = nullptr;
                delete child;
                return;
            }
            node = child;
        }
    }

    int getMaxXOR(int num) {
        TrieNode* node = root;
        int maxXOR = 0;
        for (int i = MAX_BIT; i >= 0; --i) {
            int bit = (num >> i) & 1;
            int desiredBit = 1 - bit;
            if (node->children[desiredBit]) {
                maxXOR |= (1 << i);
                node = node->children[desiredBit];
            } else {
                node = node->children[bit];
            }
        }
        return maxXOR;
    }

private:
    TrieNode* root;
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    cin >> M;

    BitwiseTrie trie;
    trie.insert(0);

    for (int i = 0; i < M; ++i) {
        int type, x;
        cin >> type >> x;
        if (type == 1) {
            trie.insert(x);
        } else if (type == 2) {
            trie.remove(x);
        } else if (type == 3) {
            cout << trie.getMaxXOR(x) << endl;
        }
    }

    return 0;
}