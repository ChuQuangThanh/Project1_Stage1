//C++
#include <bits/stdc++.h>

using namespace std;

int a[9][9];
int canwrite[9][9];
int count_sol = 0;

bool check(int r, int c, int v)
{
    for (int i = 0; i < 9; i++)
        if (a[r][i] == v || a[i][c] == v)
            return false;

    int I = r/3 * 3, J = c/3 * 3;

    for (int i = I; i <= I + 2; i++)
        for (int j = J; j <= J + 2; j++)
            if (a[i][j] == v)
                return false;

    return true;
}

void sol(int r, int c)
{
    if (r == 8 && c == 8) count_sol++;

    if (c == 8) sol(r + 1, 0);

    if (!canwrite[r][c])
    {
        sol(r, c + 1);
        return;
    }

    for (int i = 1; i <= 9; i++)
        if (check(r, c, i))
        {
            a[r][c] = i;
            sol(r, c + 1);
            a[r][c] = 0;
        }
}


int main()
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> a[i][j];

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (a[i][j] == 0) canwrite[i][j] = 1;
            else canwrite[i][j] = 0;

    sol(0,0);
    cout << count_sol;
    return 0;
}
