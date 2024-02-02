#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> filenames(n);

    for (int i = 0; i < n; ++i) {
        cin >> filenames[i];
    }

    int len = filenames[0].size();
    string result = "";

    for (int i = 0; i < len; ++i) {
        char commonChar = filenames[0][i];

        for (int j = 1; j < n; ++j) {
            if (filenames[j][i] != commonChar) {
                commonChar = '?';
                break;
            }
        }
        result += commonChar;
    }
    cout << result << endl;

    return 0;
}