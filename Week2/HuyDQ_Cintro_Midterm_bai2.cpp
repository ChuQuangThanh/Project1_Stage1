//C++
#include <bits/stdc++.h>

using namespace std;

#define MAX 21

int a[MAX], n;

int main()
{
    cin >> n;
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i < n; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
    cout << a[n - 1];
    return 0;
}
