#include <bits/stdc++.h>

using namespace std;

int a,b,c;
queue<pair<int, int>> q;
pair<int, int> p;
bool visited[600][600];
int step = 0;

pair<int, int> test1(int x, int y) {
    if (x == 0) {
        x = a;
        if (!visited[x][y]) {
            visited[x][y] = true;
            return make_pair(x, y);
        }
    }
    return make_pair(-1, -1);
}

pair<int, int> test2(int x, int y) {
    if (y == 0) {
        y = b;
        if (!visited[x][y]) {
            visited[x][y] = true;
            return make_pair(x, y);
        }
    }
    return make_pair(-1, -1);
}

pair<int, int> test3(int x, int y) {
    x = 0;
    if (!visited[x][y]) {
        visited[x][y] = true;
        return make_pair(x, y);
    }
    return make_pair(-1, -1);
}

pair<int, int> test4(int x, int y) {
    y = 0;
    if (!visited[x][y]) {
        visited[x][y] = true;
        return make_pair(x, y);
    }
    return make_pair(-1, -1);
}

pair<int, int> test5(int x, int y) {
    if (x + y >= a) {
        y = x + y - a;
        x = a;
    } else {
        x += y;
        y = 0;
    }
    if (!visited[x][y]) {
        visited[x][y] = true;
        return make_pair(x, y);
    }
    return make_pair(-1, -1);
}

pair<int, int> test6(int x, int y) {
    if (x + y >= b) {
        x = x + y - b;
        y = b;
    } else {
        y += x;
        x = 0;
    }
    if (!visited[x][y]) {
        visited[x][y] = true;
        return make_pair(x, y);
    }
    return make_pair(-1, -1);
}
int main()
{
    cin >> a >> b >> c;
    q.push(make_pair(0, 0));
    int x, y;
    for (int i = 0; i <= 31; i++)
        for (int j = 0; j <= 31; j++)
            visited[i][j] = false;
    visited[0][0] = true;
    while(!q.empty())
    {
        int size = q.size();
        step++;

        while (size--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == c || y == c || x + y == c) {
                cout << step - 1;
                return 0;
            }

            pair<int, int> res1 = test1(x, y);
            if (res1.first != -1) q.push(res1);

            pair<int, int> res2 = test2(x, y);
            if (res2.first != -1) q.push(res2);

            pair<int, int> res3 = test3(x, y);
            if (res3.first != -1) q.push(res3);

            pair<int, int> res4 = test4(x, y);
            if (res4.first != -1) q.push(res4);

            pair<int, int> res5 = test5(x, y);
            if (res5.first != -1) q.push(res5);

            pair<int, int> res6 = test6(x, y);
            if (res6.first != -1) q.push(res6);
        }
    }
    cout << "-1";
    return 0;
}
