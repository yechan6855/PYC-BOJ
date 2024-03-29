#include <bits/stdc++.h>
using namespace std;

long long largestRectangle(vector<int>& heights) {
    stack<int> s;
    long long maxArea = 0;
    int n = heights.size();
    for (int i = 0; i <= n; ++i) {
        while (!s.empty() && (i == n || heights[s.top()] >= heights[i])) {
            int height = heights[s.top()];
            s.pop();
            int width;
            if (s.empty())
                width = i;
            else
                width = i - s.top() - 1;
            maxArea = max(maxArea, (long long)height * width);
        }
        if (i < n) {
            s.push(i);
        }
    }
    return maxArea;
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        vector<int> heights(n);
        for (int i = 0; i < n; ++i) {
            cin >> heights[i];
        }
        cout << largestRectangle(heights) << endl;
    }
    return 0;
}