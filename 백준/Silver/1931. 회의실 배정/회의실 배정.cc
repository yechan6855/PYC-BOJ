#include <bits/stdc++.h>

using namespace std;

struct Meeting {
    int start;
    int end;
};

bool compare(Meeting m1, Meeting m2) {
    if (m1.end == m2.end) return m1.start < m2.start;
    return m1.end < m2.end;
}

int main() {
    int N;
    cin >> N;

    vector<Meeting> meetings(N);
    for (int i = 0; i < N; i++) {
        cin >> meetings[i].start >> meetings[i].end;
    }

    sort(meetings.begin(), meetings.end(), compare);

    int count = 0;
    int endTime = 0;

    for (const auto& meeting : meetings) {
        if (meeting.start >= endTime) {
            endTime = meeting.end;
            count++;
        }
    }

    cout << count << endl;

    return 0;
}