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
            if (s[i] != '-' || (i != 4 && i != 7))
            {
                cout << "INCORRECT";
                return 0;
            }
        }
    }
    string y, m, d;
    int year, month, day;
    y = s.substr(0,4);
    m = s.substr(5,6);
    d = s.substr(8,9);
    year = stoi(y);
    month = stoi(m);
    day = stoi(d);
    if (day > 31 || month > 12)
    {
        cout << "INCORRECT";
        return 0;
    }
    cout << year << " " << month << " " << day;
    return 0;
}
