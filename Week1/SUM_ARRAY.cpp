//C++
#include <bits/stdc++.h>

using namespace std;

#define MAX 1000000

int a[MAX], n, sum = 0;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    cout << sum;
    return 0;
}
