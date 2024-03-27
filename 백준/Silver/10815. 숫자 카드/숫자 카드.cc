#include <bits/stdc++.h>
using namespace std;

bool binarySearch(const vector<int>& cards, int target) {
    int low = 0, high = cards.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (cards[mid] == target) return true;
        else if (cards[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N;
    vector<int> cards(N);
    for (int i = 0; i < N; i++) {
        cin >> cards[i];
    }

    sort(cards.begin(), cards.end());

    cin >> M;
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        cout << binarySearch(cards, num) << " ";
    }
    return 0;
}