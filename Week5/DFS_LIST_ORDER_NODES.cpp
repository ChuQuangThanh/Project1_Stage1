//C++
#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

int n, m;
vector <int> adj[MAX];
bool visited[MAX];

void dfs(int root)
{
    visited[root] = true;
    cout << root << " ";
    for (auto i : adj[root])
    {
        if (!visited[i])
            dfs(i);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    fill_n(visited, n + 1, false);
    dfs(1);
    return 0;
}
