//C++
#include <bits/stdc++.h>

using namespace std;

#define MAX 1000000

int n, k;
int q = 0;
int a[MAX], b[MAX];

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    b[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        b[i] = b[i - 1] + a[i - 1];
    }
    for (int i = 0; i <= n - k; i++)
    {
        if ((b[i + k] - b[i]) % 2 == 0)
            q++;
    }
    cout << q;
    return 0;
}
