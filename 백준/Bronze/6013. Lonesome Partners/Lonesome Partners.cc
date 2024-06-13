#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pi pair<int,int>
#define mi map<int,int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define tiii tuple<int,int,int>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    io;
    int N;
    cin >> N;

    vector<pi> cows(N);

    for (int i = 0; i < N; i++) {
        cin >> cows[i].fi >> cows[i].se;
    }

    int idx1 = 0, idx2 = 1;
    double maxDist = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double dist = distance(cows[i].fi, cows[i].se, cows[j].fi, cows[j].se);
            if (dist > maxDist) {
                maxDist = dist;
                idx1 = i;
                idx2 = j;
            }
        }
    }

    idx1++;
    idx2++;

    if (idx1 > idx2) {
        swap(idx1, idx2);
    }

    cout << idx1 << " " << idx2 << endl;

    return 0;
}