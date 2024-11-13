#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<double> scores;
    double score;
    
    for(int i = 0; i < N; i++) {
        cin >> score;
        scores.push_back(score);
    }
    
    sort(scores.begin(), scores.end());
    
    for(int i = 0; i < 7; i++) {
        cout.precision(3);
        cout << fixed << scores[i] << "\n";
    }
    
    return 0;
}