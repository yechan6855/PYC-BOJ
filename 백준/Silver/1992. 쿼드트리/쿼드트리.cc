#include <bits/stdc++.h>
#define endl "\n"
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

vector<string> image;

string quadTree(int x, int y, int size) {
    if (size == 1) {
        return string(1, image[y][x]);
    }

    string result = "";
    char check = image[y][x];
    bool same = true;

    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (image[i][j] != check) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }

    if (same) {
        return string(1, check);
    }

    int newSize = size / 2;
    result += "(";
    result += quadTree(x, y, newSize);
    result += quadTree(x + newSize, y, newSize);
    result += quadTree(x, y + newSize, newSize);
    result += quadTree(x + newSize, y + newSize, newSize);
    result += ")";

    return result;
}

int main() {
    io;
    int N;
    cin >> N;

    image.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> image[i];
    }

    cout << quadTree(0, 0, N) << endl;

    return 0;
}