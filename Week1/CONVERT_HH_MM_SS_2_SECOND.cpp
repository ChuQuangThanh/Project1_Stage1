#include <bits/stdc++.h>

using namespace std;

int ktra(char c)
{
    if (c < '0' || c > '9') return 0;
    else return 1;
}

int main()
{
    string s;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
    {
        if (ktra(s[i]) == 0)
        {
            if (s[i] != ':' || (i != 2 && i != 5))
            {
                cout << "INCORRECT";
                return 0;
            }
        }
    }
    string h, m, s1;
    int hour, minute, sec;
    h = s.substr(0,2);
    m = s.substr(3,4);
    s1 = s.substr(6,7);
    hour = stoi(h);
    minute = stoi(m);
    sec = stoi(s1);
    if (hour > 23 || minute > 59 || sec > 59)
    {
        cout << "INCORRECT";
        return 0;
    }
    cout << hour * 3600 + minute * 60 + sec;
    return 0;
}
