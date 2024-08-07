#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
    int childCount;

    TrieNode() : isEnd(false), childCount(0) {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }

    ~TrieNode() {
        for (int i = 0; i < 26; i++) {
            if (children[i]) {
                delete children[i];
            }
        }
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() : root(new TrieNode()) {}

    ~Trie() {
        delete root;
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
                node->childCount++;
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }

    int solve(const string& word) {
        int count = 1;
        TrieNode* node = root->children[word[0] - 'a'];

        for (int i = 1; i < word.length(); i++) {
            if (node->childCount > 1 || node->isEnd) {
                count++;
            }
            node = node->children[word[i] - 'a'];
        }

        return count;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(2);

    int n;
    while (cin >> n) {
        Trie trie;
        vector<string> s(n);

        for (int i = 0; i < n; i++) {
            cin >> s[i];
            trie.insert(s[i]);
        }

        double total = 0;
        for (const string& word : s) {
            total += trie.solve(word);
        }

        cout << total / n << '\n';
    }

    return 0;
}