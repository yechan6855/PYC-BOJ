#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 50
using namespace std;

int N, M;
vector<int> list;
string dp[MAX+1];
bool visits[MAX+1];

bool compareRoom(string room1, string room2) {
    if(room1.length() < room2.length()) return true;
    else if (room1.length() > room2.length()) return false;
    else return room1 < room2;
}
string findMaxRoom(int m, bool isHead) {
    if(dp[m] != "" && visits[m]) return dp[m];
    string maxRoom = "", curRoom;
    for(int i = 0; i < list.size(); i++) {
        if(isHead && i == 0) continue;
        if(m - list[i] < 0) continue;
        curRoom = to_string(i) + findMaxRoom(m - list[i], false);
        if(compareRoom(maxRoom, curRoom))
            maxRoom = curRoom;
    }
    dp[m] = maxRoom;
    visits[m] = true;
    return maxRoom;
}

int main() {
    int n, maxRoom;
    string nextRoom, answer;

    for(int i = 0; i <= M; i++) {
        dp[i] = "";
    }
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> n;
        list.push_back(n);
        dp[n] = to_string(i);
    }
    cin >> M;
    findMaxRoom(M, true);

    answer = dp[M] == "" ? "0" : dp[M];
    cout << answer << '\n';

    return 0;
}