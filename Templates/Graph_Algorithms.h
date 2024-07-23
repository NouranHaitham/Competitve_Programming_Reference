#ifndef CP_TRAINING_GRAPH_ALGORITHMS_H
#define CP_TRAINING_GRAPH_ALGORITHMS_H

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// For only 4 directions
int dx[]={0 ,0 ,-1 ,1};
int dy[]={1,-1,0,0};


bool inborder(int x,int y,int n,int m)
{
    if(x>=0 && y>=0 && x<n && y<m) return true;
    return false;
}


vector<ll> BFS(ll source, vector<vector<ll>>& graph)
{
    vector<bool> vis(graph.size(),false);
    queue<ll> q;

    q.push(source);

    vector<ll> bfs;
    while(!q.empty())
    {
        // get the topmost element in the queue
        int node = q.front();
        q.pop();

        if(!vis[node])
        {
            bfs.push_back(node);
            for (auto it: graph[node]) {
                if (!vis[it])
                {
                    q.push(it);
                }
            }
        }

    }

    return bfs;
}


vector<ll> DFS_V1(ll source, vector<vector<ll>>& graph)
{
    vector<bool> vis(graph.size(),false);
    stack<ll> s;

    s.push(source);

    vector<ll> dfs;
    while(!s.empty())
    {
        // get the topmost element in the queue
        int node = s.top();
        s.pop();

        if(!vis[node])
        {
            dfs.push_back(node);
            for (auto it: graph[node]) {
                if (!vis[it])
                {
                    s.push(it);
                }
            }
        }

    }

    return dfs;
}

void DFS_V2(ll source, vector<vector<ll>>& graph,vector<bool>& vis, vector<int>& df)
{
    vis[source] = 1;
    df.push_back(source);
    // traverse all its neighbours
    for(auto it : graph[source]) {
        // if the neighbour is not visited
        if (!vis[it]) {
            DFS_V2(it, graph, vis, df);
        }
    }
}


bool CycleDetectionUndirected(ll node,ll parent, vector<vector<ll>>& graph,vector<bool>& vis)
{
    vis[node] = 1;

    for(auto it : graph[node])
    {
        if (!vis[it])
        {
           if(CycleDetectionUndirected(it,node, graph, vis) == true)
               return true;
        }
        else if(vis[it] && it!=parent)
        {
            return true;
        }
    }

    return false;
}


bool ans=false;
void CycleDirectedDFS(int node,vector<vector<ll>>& graph,vector<bool>& visited)
{
    visited[node]=-1;

    for(auto& edge : graph[node])
    {
        if(!visited[edge]) {

            CycleDirectedDFS(edge,graph,visited);
        }
        else if(visited[edge]==-1) {
            ans = true;
            return;
        }

    }

    visited[node]=1;
}


void Grid_Search(int n,int m,vector<vector<pair<int,int>>>& grid)
{

    vector<vector<int>> visit(n+3,vector<int>(m+3,0));
    queue<pair<int,int>> explore;


    while(!explore.empty())
    {
        pair<int, int> curr = explore.front();
        explore.pop();

        //  cout<<curr.first<<" "<<curr.second<<endl;

        if(!visit[curr.first][curr.second])
        {
            visit[curr.first][curr.second] = 1;

            for (int i = 0; i < 4; i++) {

                ll newX=curr.first + dx[i];
                ll newY=curr.second + dy[i];

                if (inborder(newX,newY,n,m) &&  !visit[newX][newY])
                {
                    explore.push(pair<int, int>(newX, newY));
                }
            }

        }

    }

}



void TOPO_V1(ll source, vector<vector<ll>>& graph,vector<bool>& vis, vector<int>& df)
{
   for(auto it : graph[source]) {
        // if the neighbour is not visited
        if (!vis[it]) {
            DFS_V2(it, graph, vis, df);
        }
    }

    vis[source] = 1;
    df.push_back(source);
}

vector<ll> TOPO_V2(vector<vector<ll>>& graph,ll n)
{
    vector<ll> inDegrees(n+1,0);

    for(int i=1;i<=n;i++)
    {
        for(auto& child: graph[i])
        {
            inDegrees[child]++;
        }
    }

    queue<int> q;

    for(int i=1;i<=n;i++)
    {
        if(inDegrees[i]==0)
        {
            q.push(i);
        }
    }


    vector<ll> topo;

    while(!q.empty())
    {
        int task=q.front();
        q.pop();

        topo.push_back(task);

        for(auto& child: graph[task])
        {
            inDegrees[child]--;
            if(inDegrees[child]==0) q.push(child);
        }
    }


    return topo;
}


void dijkstra(int node,vector<vector<pair<int,int>>>& graph,vector<ll>& dist,vector<ll>& pred)  // must be weighted in positive
{

 //   vector<int> dist(graph.size(),INF_INT);
 //   vector<int> pred(graph.size(),-1);


    vector<int> vis(graph.size()+1,false);
    priority_queue<pair<int,int>> min_cost;

    dist[node]=0;
    min_cost.push({0,node});

    while(!min_cost.empty())
    {
        int min_node=-1*min_cost.top().second;
        min_cost.pop();

        if(vis[min_node]) continue;



        vis[min_node]=1;
        for(auto& child: graph[min_node])
        {
            if(!vis[child.first] && (dist[min_node]+child.second < dist[child.first]))
            {
                dist[child.first]=dist[min_node]+child.second;
                pred[child.first]=min_node;

                min_cost.push({-dist[child.first],child.first});

            }

        }
    }


    ll child = graph.size(); //target node
    vector<int> path;

    while(pred[child]!=-1)
    {
        path.push_back(child);
        child=pred[child];
    }

    path.push_back(1);


}


class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0;i<=n;i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

// MSP
int spanningTree(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int, int>,
            vector<pair<int, int> >, greater<pair<int, int>>> pq;

    vector<int> vis(V, 0);
    // {wt, node}
    pq.push({0, 0});
    int sum = 0;
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;

        if (vis[node] == 1) continue;
        // add it to the mst
        vis[node] = 1;
        sum += wt;
        for (auto it : adj[node]) {
            int adjNode = it[0];
            int edW = it[1];
            if (!vis[adjNode]) {
                pq.push({edW, adjNode});
            }
        }
    }
    return sum;
}


bool CycleDetectionDirected(int node, vector<int> adj[], int vis[], int pathVis[]) {
    vis[node] = 1;
    pathVis[node] = 1;

    // traverse for adjacent nodes
    for (auto it : adj[node]) {
        // when the node is not visited
        if (!vis[it]) {
            if (CycleDetectionDirected(it, adj, vis, pathVis) == true)
                return true;
        }
            // if the node has been previously visited
            // but it has to be visited on the same path
        else if (pathVis[it]) {
            return true;
        }
    }

    pathVis[node] = 0;
    return false;
}

bool Bipartite(int node, int col, int color[], vector<int> adj[]) {
    color[node] = col;

    // traverse adjacent nodes
    for(auto it : adj[node]) {
        // if uncoloured
        if(color[it] == -1) {
            if(Bipartite(it, !col, color, adj) == false) return false;
        }
            // if previously coloured and have the same colour
        else if(color[it] == col) {
            return false;
        }
    }

    return true;
}


#endif //CP_TRAINING_GRAPH_ALGORITHMS_H
