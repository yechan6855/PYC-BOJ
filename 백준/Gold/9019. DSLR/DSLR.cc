#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 10000;

struct State {
    int num;
    string commands;
};

int D(int n) {
    return (n * 2) % MAX;
}

int S(int n) {
    return (n == 0) ? 9999 : n - 1;
}

int L(int n) {
    int d1 = n / 1000;
    n = (n % 1000) * 10 + d1;
    return n;
}

int R(int n) {
    int d4 = n % 10;
    n = (n / 10) + (d4 * 1000);
    return n;
}

string BFS(int A, int B) {
    queue<State> q;
    bool visited[MAX];
    memset(visited, false, sizeof(visited));

    q.push({A, ""});
    visited[A] = true;

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        if (current.num == B) {
            return current.commands;
        }

        int nextD = D(current.num);
        int nextS = S(current.num);
        int nextL = L(current.num);
        int nextR = R(current.num);

        if (!visited[nextD]) {
            q.push({nextD, current.commands + "D"});
            visited[nextD] = true;
        }

        if (!visited[nextS]) {
            q.push({nextS, current.commands + "S"});
            visited[nextS] = true;
        }

        if (!visited[nextL]) {
            q.push({nextL, current.commands + "L"});
            visited[nextL] = true;
        }

        if (!visited[nextR]) {
            q.push({nextR, current.commands + "R"});
            visited[nextR] = true;
        }
    }

    return "";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int A, B;
        cin >> A >> B;

        string result = BFS(A, B);
        cout << result << '\n';
    }

    return 0;
}