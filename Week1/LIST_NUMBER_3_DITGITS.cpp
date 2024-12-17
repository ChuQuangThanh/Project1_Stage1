//C++
#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    cin >> n;
    int k = 100 / n * n;
    if (k < 100) k += n;
    for (int i = k; i <= 999; i+= n)
        cout << i << " ";
    return 0;
}

