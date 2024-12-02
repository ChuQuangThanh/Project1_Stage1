//C++
#include <bits/stdc++.h>

using namespace std;

stack<int> q;
string v;
int a;

int main()
{
    do{
        cin >> v;
        if (v == "PUSH")
        {
            cin >> a;
            q.push(a);
        }
        else if (v == "POP")
        {
            if (!q.empty())
            {
                cout << q.top() << endl;
                q.pop();
            }
            else cout << "NULL" << endl;
        }
    } while (v != "#");
    return 0;
}
