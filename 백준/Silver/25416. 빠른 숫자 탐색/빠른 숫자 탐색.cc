#include <bits/stdc++.h>
using namespace std;

struct Cell {
    int r;
    int c;
    int moves;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> grid(5, vector<int>(5));
    int target_r, target_c;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin >> grid[i][j];
            if(grid[i][j] ==1){
                target_r = i;
                target_c = j;
            }
        }
    }

    int start_r, start_c;
    cin >> start_r >> start_c;

    vector<pair<int, int>> directions = { {-1,0}, {1,0}, {0,-1}, {0,1} };
    vector<vector<bool>> visited(5, vector<bool>(5, false));

    queue<Cell> q;

    q.push(Cell{start_r, start_c, 0});
    visited[start_r][start_c] = true;

    int result = -1;

    while(!q.empty()){
        Cell current = q.front();
        q.pop();

        if(current.r == target_r && current.c == target_c){
            result = current.moves;
            break;
        }

        for(auto dir: directions){
            int new_r = current.r + dir.first;
            int new_c = current.c + dir.second;

            if(new_r <0 || new_r >=5 || new_c <0 || new_c >=5) continue;
            if(grid[new_r][new_c] != -1 && !visited[new_r][new_c]){
                visited[new_r][new_c] = true;
                q.push(Cell{new_r, new_c, current.moves +1});
            }
        }
    }

    cout << result;
}