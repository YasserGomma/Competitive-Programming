
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;

bool DLS(int src, int target, int limit)
{
    if (src == target)
        return true;

    if (limit <= 0)
        return false;

    for (auto it : adj[src])
        if (DLS(it, target, limit - 1) == true)
            return true;

    return false;
}

bool IDDFS(int src, int target, int max_dep)
{
    for (int i = 0; i <= max_dep; i++)
        if (DLS(src, target, i) == true)
            return true;
    return false;
}


int main()
{
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);

    }

    int src , target , maxDepth;
    while (cin >> src >> target >> maxDepth)
        if (IDDFS(src, target, maxDepth) == true)
            cout << "Found with max depth equal " << maxDepth << endl;
        else
            cout << "Can't found with max depth equal " << maxDepth << endl;;

}

