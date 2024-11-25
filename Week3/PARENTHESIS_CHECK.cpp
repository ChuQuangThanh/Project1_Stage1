//C++
#include <bits/stdc++.h>

using namespace std;

string v;
int ans = 1;
stack <char> s;

bool match(char s1, char s2)
{
    if    ((s1 == '(' && s2 == ')')
       || (s1 == '[' && s2 == ']')
       || (s1 == '{' && s2 == '}'))
      return true;
    else return false;
}

int main()
{
    cin >> v;
    int len = v.length();
    if (len % 2 == 1)
    {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < len; i++)
    {
        if (v[i] == '(' || v[i] == '{' || v[i] == '[')
            s.push(v[i]);
        else
        {
            if (!match(s.top(), v[i]) || s.empty())
            {
                cout << 0;
                return 0;
            }
            s.pop();
        }
    }
    cout << ans;
    return 0;
}
