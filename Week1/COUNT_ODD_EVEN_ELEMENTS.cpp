//C++
#include <bits/stdc++.h>

using namespace std;

#define MAX 100000

int a[MAX], n;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int count_odd = 0;
    int count_even = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0) count_even++;
        else count_odd++;
    }
    cout << count_odd++ << " " << count_even;
    return 0;
}
