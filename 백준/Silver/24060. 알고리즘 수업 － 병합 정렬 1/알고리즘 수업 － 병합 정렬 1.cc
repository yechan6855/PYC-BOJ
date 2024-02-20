#include <iostream>
#include <cmath>
using namespace std;

int A[500001] = { 0 };
int tmp[500001] = { 0, };
int cnt = 0;
int N, K;
bool flag = false;
void merge(int A[], int p, int q, int r)
{
    int i = p;
    int j = q + 1;
    int t = 1;
    while (i <= q && j <= r)
    {
        if (A[i] <= A[j])
        {
            tmp[t++] = A[i++];
        }
        else
        {
            tmp[t++] = A[j++];
        }
    }
    while (i <= q)
    {
        tmp[t++] = A[i++];
    }
    while (j <= r)
    {
        tmp[t++] = A[j++];
    }
    i = p;
    t = 1;
    while (i <= r)
    {
        A[i++] = tmp[t++];
        cnt++;
        if (cnt == K)
        {
            cout << A[i - 1];
            flag = true;
            return;
        }
    }
}

void merge_sort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = floor((p + r) / 2);
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    merge_sort(A, 0, N - 1);
    if (!flag)
        cout << -1;
    return 0;
}