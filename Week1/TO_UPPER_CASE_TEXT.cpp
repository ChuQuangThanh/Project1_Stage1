//C++
#include <bits/stdc++.h>

using namespace std;
int main()
{
    string s;
    while(getline(cin, s))
    {
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        cout << s << endl;
    }
    return 0;
}