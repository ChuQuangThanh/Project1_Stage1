//C++
#include <bits/stdc++.h>

using namespace std;

string v, q;
set <string> s;
int main()
{
    while (1)
    {
        cin >> v;
        if (v != "*")
            s.insert(v);
        else break;
    }

    while (1)
    {
        cin >> q;
        int tmp = s.size();
        if (q == "insert")
        {
            cin >> v;
            s.insert(v);
            if (tmp == s.size()) cout << 0 << endl;
            else cout << 1 << endl;
        }
        else if (q == "find")
        {
            cin >> v;
            s.insert(v);
            if (tmp == s.size()) cout << 1 << endl;
            else
            {
                cout << 0 << endl;
                s.erase(v);
            }
        }
        else break;
    }
    return 0;
}

