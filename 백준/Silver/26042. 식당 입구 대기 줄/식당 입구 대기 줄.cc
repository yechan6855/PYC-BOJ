#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    queue<int> q;
    int ans = 0;
    int res = 0;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        if (t == 1) {
            int student;
            cin >> student;
            q.push(student);

            if (q.size() > ans) {
                ans = q.size();
                res = q.back();
            }
            else if (q.size() == ans) {
                res = min(res, q.back());
            }
        }
        else if (t == 2 && !q.empty()) {
            q.pop();
        }
    }

    cout << ans << " " << res;

    return 0;
}