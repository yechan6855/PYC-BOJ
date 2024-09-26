#include <bits/stdc++.h>
using namespace std;

struct Participant {
    string name;
    int score;
};

bool compare(const Participant& a, const Participant& b) {
    if (a.score == b.score) {
        return a.name < b.name;
    }
    return a.score > b.score;
}

int main() {
    int N;
    cin >> N;

    vector<Participant> part(N);

    for (int i = 0; i < N; i++) {
        cin >> part[i].name >> part[i].score;
    }

    sort(part.begin(), part.end(), compare);

    cout << part[0].name << endl;

    return 0;
}