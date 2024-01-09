#include <iostream>
#include <queue>
#include <map>

#define EL "\n"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    while (N--) {
        int K;
        cin >> K;
        priority_queue<int, vector<int>, greater<int>> mQ;
        priority_queue<int, vector<int>, less<int>> MQ;
        map<int, int> data;
        while (K--) {
            char C;
            int M;
            cin >> C >> M;
            if (C == 'I') {
                mQ.push(M);
                MQ.push(M);
                data[M]++;
            }
            else if (C == 'D') {
                if (M == -1) {
                    if (mQ.empty())
                        goto OUT;
                    while (data[mQ.top()] == 0) {
                        mQ.pop();
                        if (mQ.empty())
                            goto OUT;
                    }
                    if(data.find(mQ.top()) != data.end())
                        data[mQ.top()]--;
                    mQ.pop();
                }
                else {
                    if (MQ.empty())
                        goto OUT;

                    while (data[MQ.top()] == 0) {
                        MQ.pop();
                        if (MQ.empty())
                            goto OUT;
                    }
                    if (data.find(MQ.top()) != data.end())
                        data[MQ.top()]--;
                    MQ.pop();
                }
            }
            OUT:;
        }
        while (mQ.size() && data[mQ.top()] == 0) {
            mQ.pop();
            if (mQ.empty())
                break;
        }
        while (MQ.size() && data[MQ.top()] == 0) {
            MQ.pop();
            if (MQ.empty())
                break;
        }
        if (MQ.empty())
            cout << "EMPTY" << EL;
        else
            cout << MQ.top() << " " << mQ.top() << EL;
    }
    return 0;
}