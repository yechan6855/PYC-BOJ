#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int, int>
#define mi map<int, int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define tiii tuple<int,int,int>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> bread(N);

    for (int i = 0; i < N; ++i) {
        cin >> bread[i];
        reverse(bread[i].begin(), bread[i].end());
    }
    for (int i = 0; i < N; ++i) {
        cout << bread[i] << endl;
    }

    return 0;
}