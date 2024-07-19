#include <iostream>
using namespace std;
int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int H, W, N;
        cin >> H >> W >> N;
        int floor = N % H;
        if (floor == 0) {
            floor = H;
        }
        int room_number = (N - 1) / H + 1;
        cout << floor * 100 + room_number << endl;
    }
    return 0;
}