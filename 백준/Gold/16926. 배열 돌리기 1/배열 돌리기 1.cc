#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void rotateLayer(vector<vector<int>>& matrix, int layer, int n, int m) {
    int top = layer;
    int left = layer;
    int bottom = n - layer - 1;
    int right = m - layer - 1;
    
    int topleft = matrix[top][left];
    
    for (int i = left; i < right; i++) {
        matrix[top][i] = matrix[top][i + 1];
    }
    
    for (int i = top; i < bottom; i++) {
        matrix[i][right] = matrix[i + 1][right];
    }
    
    for (int i = right; i > left; i--) {
        matrix[bottom][i] = matrix[bottom][i - 1];
    }
    
    for (int i = bottom; i > top; i--) {
        matrix[i][left] = matrix[i - 1][left];
    }
    
    matrix[top + 1][left] = topleft;
}

void rotateMatrix(vector<vector<int>>& matrix, int n, int m, int r) {
    int layers = min(n, m) / 2;

    for (int i = 0; i < layers; i++) {
        int perimeter = 2 * (n + m - 4 * i) - 4;
        int actualRotations = r % perimeter;

        for (int j = 0; j < actualRotations; j++) {
            rotateLayer(matrix, i, n, m);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, r;
    cin >> n >> m >> r;

    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    rotateMatrix(matrix, n, m, r);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}