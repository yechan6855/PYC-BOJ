#include <bits/stdc++.h>
#define cd complex<double>
#define vi vector<int>
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

const double PI = acos(-1);

void fft(vector<cd> &a, bool invert) {
    int n = a.size();
    if (n == 1) return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[i * 2];
        a1[i] = a[i * 2 + 1];
    }

    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }
}

vi multiply(vi const& a, vi const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vi result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());

    int carry = 0;
    for (int i = 0; i < n; i++) {
        result[i] += carry;
        carry = result[i] / 10;
        result[i] %= 10;
    }

    while (result.size() > 1 && result.back() == 0)
        result.pop_back();
    return result;
}

int main() {
    string sa, sb;
    cin >> sa >> sb;
    vi a(sa.size()), b(sb.size());
    for (int i = 0; i < sa.size(); i++)
        a[i] = sa[sa.size() - 1 - i] - '0';
    for (int i = 0; i < sb.size(); i++)
        b[i] = sb[sb.size() - 1 - i] - '0';

    vi result = multiply(a, b);

    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i];
    return 0;
}