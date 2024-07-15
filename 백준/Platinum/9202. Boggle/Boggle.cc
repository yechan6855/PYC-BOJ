#include <bits/stdc++.h>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

const int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }

    ~TrieNode() {
        for (int i = 0; i < 26; i++) {
            delete children[i];
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        delete root;
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'A';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    bool search(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'A';
            if (!node->children[index]) {
                return false;
            }
            node = node->children[index];
        }
        return node->isEndOfWord;
    }

    TrieNode* getRoot() {
        return root;
    }

private:
    TrieNode* root;
};

vector<string> board(4);
bool visited[4][4];
set<string> foundWords;
Trie trie;

void dfs(int x, int y, TrieNode* node, string word) {
    if (x < 0 || x >= 4 || y < 0 || y >= 4) return;
    if (visited[x][y]) return;

    char ch = board[x][y];
    int index = ch - 'A';
    if (!node->children[index]) return;

    visited[x][y] = true;
    word += ch;
    node = node->children[index];

    if (node->isEndOfWord) {
        foundWords.insert(word);
    }

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        dfs(nx, ny, node, word);
    }

    visited[x][y] = false;
}

int getScore(const string& word) {
    int len = word.length();
    if (len <= 2) return 0;
    if (len <= 4) return 1;
    if (len == 5) return 2;
    if (len == 6) return 3;
    if (len == 7) return 5;
    return 11;
}

int main() {
    io;
    int w, b;
    cin >> w;

    for (int i = 0; i < w; i++) {
        string word;
        cin >> word;
        trie.insert(word);
    }

    cin >> b;

    while (b--) {
        for (int i = 0; i < 4; i++) {
            cin >> board[i];
        }

        foundWords.clear();
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                dfs(i, j, trie.getRoot(), "");
            }
        }

        int totalScore = 0;
        string longestWord = "";
        int wordCount = foundWords.size();

        for (const string& word : foundWords) {
            totalScore += getScore(word);
            if (word.length() > longestWord.length() || (word.length() == longestWord.length() && word < longestWord)) {
                longestWord = word;
            }
        }

        cout << totalScore << " " << longestWord << " " << wordCount << endl;
    }

    return 0;
}