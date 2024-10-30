#include <bits/stdc++.h>
using namespace std;

const int MAX = 100002;
const int dx_dir[4] = {0, 1, 0, -1};
const int dy_dir[4] = {1, 0, -1, 0};

long long prefix_x[MAX], prefix_y[MAX];
int prefix_dir_arr[MAX];
long long suffix_x_arr[MAX][4], suffix_y_arr[MAX][4];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string command;
    cin >> command;
    int N = command.length();
    
    prefix_x[0] = 0;
    prefix_y[0] = 0;
    prefix_dir_arr[0] = 0;
    
    for(int i=1; i<=N; ++i){
        char c = command[i-1];
        if(c == 'L'){
            prefix_dir_arr[i] = (prefix_dir_arr[i-1] + 3) % 4;
            prefix_x[i] = prefix_x[i-1];
            prefix_y[i] = prefix_y[i-1];
        }
        else if(c == 'R'){
            prefix_dir_arr[i] = (prefix_dir_arr[i-1] + 1) % 4;
            prefix_x[i] = prefix_x[i-1];
            prefix_y[i] = prefix_y[i-1];
        }
        else if(c == 'F'){
            prefix_dir_arr[i] = prefix_dir_arr[i-1];
            prefix_x[i] = prefix_x[i-1] + dx_dir[prefix_dir_arr[i-1]];
            prefix_y[i] = prefix_y[i-1] + dy_dir[prefix_dir_arr[i-1]];
        }
    }
    
    for(int d=0; d<4; ++d){
        suffix_x_arr[N+1][d] = 0;
        suffix_y_arr[N+1][d] = 0;
    }
    
    for(int i=N; i>=1; --i){
        char c = command[i-1];
        for(int d=0; d<4; ++d){
            if(c == 'L'){
                int new_dir = (d + 3) % 4;
                suffix_x_arr[i][d] = suffix_x_arr[i+1][new_dir];
                suffix_y_arr[i][d] = suffix_y_arr[i+1][new_dir];
            }
            else if(c == 'R'){
                int new_dir = (d + 1) % 4;
                suffix_x_arr[i][d] = suffix_x_arr[i+1][new_dir];
                suffix_y_arr[i][d] = suffix_y_arr[i+1][new_dir];
            }
            else if(c == 'F'){
                suffix_x_arr[i][d] = dx_dir[d] + suffix_x_arr[i+1][d];
                suffix_y_arr[i][d] = dy_dir[d] + suffix_y_arr[i+1][d];
            }
        }
    }
    
    vector<pair<long long, long long>> final_positions;
    final_positions.reserve(200000);
    
    for(int i=1; i<=N; ++i){
        char original = command[i-1];
        vector<char> replacements;
        if(original == 'L'){
            replacements.push_back('R');
            replacements.push_back('F');
        }
        else if(original == 'R'){
            replacements.push_back('L');
            replacements.push_back('F');
        }
        else if(original == 'F'){
            replacements.push_back('L');
            replacements.push_back('R');
        }
        
        for(auto c_prime : replacements){
            long long x_new, y_new;
            int dir_new;
            if(c_prime == 'L'){
                dir_new = (prefix_dir_arr[i-1] + 3) % 4;
                x_new = prefix_x[i-1];
                y_new = prefix_y[i-1];
            }
            else if(c_prime == 'R'){
                dir_new = (prefix_dir_arr[i-1] + 1) % 4;
                x_new = prefix_x[i-1];
                y_new = prefix_y[i-1];
            }
            else if(c_prime == 'F'){
                dir_new = prefix_dir_arr[i-1];
                x_new = prefix_x[i-1] + dx_dir[prefix_dir_arr[i-1]];
                y_new = prefix_y[i-1] + dy_dir[prefix_dir_arr[i-1]];
            }
            long long final_x = x_new + suffix_x_arr[i+1][dir_new];
            long long final_y = y_new + suffix_y_arr[i+1][dir_new];
            final_positions.emplace_back(final_x, final_y);
        }
    }
    
    sort(final_positions.begin(), final_positions.end());
    int unique_count = 0;
    if(!final_positions.empty()){
        unique_count = 1;
        for(int i=1; i<final_positions.size(); ++i){
            if(final_positions[i].first != final_positions[i-1].first ||
               final_positions[i].second != final_positions[i-1].second){
                unique_count++;
            }
        }
    }
    
    cout << unique_count;
}