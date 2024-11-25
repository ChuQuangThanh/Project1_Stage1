//C++
#include <bits/stdc++.h>

using namespace std;

int checkword(string s)
{
    int check = 0, count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && check == 0)
        {
            count++;
            check = 1;
        }
        else if(s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
        {
            check = 0;
        }
    }
    return count;
}
int main()
{
    string s;
    int countword = 0;
    while (getline(cin, s))
    {
        countword += checkword(s);
    }
    cout << countword;
    return 0;
}
