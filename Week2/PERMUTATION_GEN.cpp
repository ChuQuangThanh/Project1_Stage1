#include <bits/stdc++.h>

using namespace std;

int n, a[21];

void print_sol()
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

bool check(int v, int k)
{
    if (k == 0) return true;
    for (int i = 0; i < k; i++)
        if (a[i] == v) return false;
    return true;
}

void sol(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (check(i, k))
        {
            a[k] = i;
            if (k == n - 1)
                print_sol();
            else
            {
                sol(k + 1);
            }
        }
    }
}

int main()
{
    cin >> n;
    sol(0);
    return 0;
}
