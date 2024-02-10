#include <iostream>  
#include <vector>  
#include <algorithm>  
  
using namespace std;  
  
bool isPrefix(const string &a, const string &b) {  
    // 문자열 b가 문자열 a의 접두어인지 확인하는 함수  
    if (a.length() > b.length()) {  
        return false;  
    }  
    return equal(a.begin(), a.end(), b.begin());  
}  
  
int main() {  
    int t;  
    cin >> t;  
  
    while (t--) {  
        int n;  
        cin >> n;  
  
        vector<string> phoneNumbers(n);  
  
        for (int i = 0; i < n; i++) {  
            cin >> phoneNumbers[i];  
        }  
  
        // 전화번호를 사전순으로 정렬  
        sort(phoneNumbers.begin(), phoneNumbers.end());  
  
        bool consistent = true;  
  
        for (int i = 0; i < n - 1; i++) {  
            if (isPrefix(phoneNumbers[i], phoneNumbers[i + 1])) {  
                consistent = false;  
                break;  
            }  
        }  
  
        if (consistent) {  
            cout << "YES\n";  
        } else {  
            cout << "NO\n";  
        }  
    }  
    return 0;  
}