//C++
#include <bits/stdc++.h>

using namespace std;

string s1, s2, s;

string processing(string s1, string s2, string s)
{
    int l1 = s1.length();
    while(s.find(s1) != string::npos)
    {
        int t = s.find(s1);
        s.erase(t, l1);
        s.insert(t, s2);
    }
    return s;
}

int main()
{
    getline(cin, s1);
    getline(cin, s2);
    while(getline(cin, s))
    {
        cout << processing(s1,s2,s) << endl;
    }
    return 0;
}
