//C++
#include <bits/stdc++.h>

using namespace std;

int n;
vector <int> v;

void print_sol()
{
    for (auto i : v)
        cout << i;
    cout << "\n";
}

void sol(int k)
{
    for(int i = 0; i <= 1; i++)
    {
        v.push_back(i);
        if (k == n) print_sol();
        else
            sol(k + 1);
        v.pop_back();
    }
}

int main()
{
    cin >> n;
    sol(1);
    return 0;
}
