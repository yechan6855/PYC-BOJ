#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Process {
    int id, time, priority;
    Process(int id, int time, int priority) : id(id), time(time), priority(priority) {}
    bool operator<(const Process& other) const {
        if (priority == other.priority) return id > other.id;
        return priority < other.priority;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t >> n;

    priority_queue<Process> pq;
    for (int i = 0; i < n; i++) {
        int id, time, priority;
        cin >> id >> time >> priority;
        pq.push(Process(id, time, priority));
    }

    for (int i = 0; i < t && !pq.empty(); i++) {
        Process cur = pq.top();
        pq.pop();

        cout << cur.id << '\n';

        if (--cur.time > 0) {
            cur.priority--;
            pq.push(cur);
        }
    }

    return 0;
}