#include <bits/stdc++.h>
using namespace std;

int N;
int cnt_neg = 0;
int cnt_zero = 0;
int cnt_one = 0;

vector<vector<int>> grid;

bool check_same(int row, int col, int size, int& value) {
    value = grid[row][col];

    for(int i = row; i < row + size; ++i) {
        for(int j = col; j < col + size; ++j) {
            if(grid[i][j] != value)
                return false;
        }
    }
    return true;
}

void divide(int row, int col, int size) {
    int value;
    if(check_same(row, col, size, value)) {
        if(value == -1)
            cnt_neg++;
        else if(value == 0)
            cnt_zero++;
        else if(value == 1)
            cnt_one++;
    } else {
        int new_size = size / 3;

        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                divide(row + i * new_size, col + j * new_size, new_size);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    grid.assign(N, vector<int>(N));

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            cin >> grid[i][j];
        }
    }

    divide(0, 0, N);

    cout << cnt_neg << "\n" << cnt_zero << "\n" << cnt_one;
}