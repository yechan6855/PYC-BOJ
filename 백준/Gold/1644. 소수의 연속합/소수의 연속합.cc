#include <iostream>
#include <vector>

using namespace std;

// 에라토스테네스의 체를 사용하여 소수를 구함
vector<int> getPrimes(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;

    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // 소수 구하기
    vector<int> primes = getPrimes(N);

    int answer = 0;
    int left = 0, right = 0;
    int sum = 0;

    while (true) {
        if (sum >= N) {
            sum -= primes[left++];
        } else if (right == primes.size()) {
            break;
        } else {
            sum += primes[right++];
        }

        if (sum == N) {
            answer++;
        }
    }
    cout << answer << '\n';

    return 0;
}