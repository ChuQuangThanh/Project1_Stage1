
//C++
#include <bits/stdc++.h>

using namespace std;

#define MAX 10000

int n, max_a = -9999, min_a = 9999, sum = 0;
int a[MAX];
string input, q;
int c, d;

int max_segment(int i, int j)
{
    if (i == j) return a[i];
    return max(max_segment(i, j - 1), a[j]);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> input;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (a[i] > max_a) max_a = a[i];
        if (a[i] < min_a) min_a = a[i];
    }
    do
    {
        cin >> q;
        if (q == "find-max") cout << max_a << endl;
        else if (q == "find-min") cout << min_a << endl;
        else if (q == "find-max-segment")
        {
            cin >> c >> d;
            cout << max_segment(c - 1, d - 1) << endl;
        }
        else if (q == "sum") cout << sum << endl;
        else if (q == "***") break;
    } while(1);
    return 0;
}
