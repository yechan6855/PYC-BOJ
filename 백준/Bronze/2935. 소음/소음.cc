#include <bits/stdc++.h>
using namespace std;

string biginteger_add(string a, string b){
    string result;
    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;

    while(i >= 0 || j >= 0 || carry > 0){
        int sum = carry;
        if(i >= 0) sum += a[i--] - '0';
        if(j >= 0) sum += b[j--] - '0';
        carry = sum / 10;
        sum = sum % 10;
        result += to_string(sum);
    }
    reverse(result.begin(), result.end());
    return result;
}

string biginteger_multiply(string a, string b) {
    int n = a.size();
    int m = b.size();
    string result(n + m, '0');

    for (int i = n - 1; i >= 0; i--) {
        int carry = 0;
        for (int j = m - 1; j >= 0; j--) {
            int temp = (result[i + j + 1] - '0') + (a[i] - '0') * (b[j] - '0') + carry;
            result[i + j + 1] = temp % 10 + '0';
            carry = temp / 10;
        }
        result[i] += carry;
    }

    size_t startpos = result.find_first_not_of("0");
    if (string::npos != startpos) {
        return result.substr(startpos);
    }
    return "0";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a,b,c;
    cin>>a>>b>>c;
    if(b=="*"){
        cout<<biginteger_multiply(a,c);
    }else{
        cout<<biginteger_add(a,c);
    }
}