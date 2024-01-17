#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    unordered_map<string, string> passwordMap;

    for (int i = 0; i < N; ++i) {
        string site, password;
        cin >> site >> password;
        passwordMap[site] = password;
    }

    for (int i = 0; i < M; ++i) {
        string query;
        cin >> query;
        cout << passwordMap[query] << '\n';
    }
    return 0;
}