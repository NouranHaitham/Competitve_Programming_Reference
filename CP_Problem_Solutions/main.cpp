#include<bits/stdc++.h>
//#include<conio.h>
#include<stdio.h>

# define INF LONG_MAX
# define INF_INT INT_MAX
# define endl '\n'
# define YES cout<<"YES"<<endl;
# define NO cout<<"NO"<<endl;
# define ll long long
using namespace std;

int dx[]={0 ,0 ,-1 ,1};
int dy[]={1,-1,0,0};


const ll mod=10e8+7;

bool inborder(int x,int y,int n,int m)
{
    if(x>=0 && y>=0 && x<n && y<m) return true;
    return false;
}



void dikgstra(vector<vector<pair<pair<ll,char>,ll>>>& graph,int n,vector<ll>& dist,vector<ll>& pred)
{
    vector<bool>visited(n+1,false);
    priority_queue<pair<ll,pair<ll,char>>> min_node;

    dist[1]=0;
    min_node.push({0,{1,'N'}});

    while(!min_node.empty())
    {

        ll cost;
        pair<ll,char>node;
        tie(cost,node)=min_node.top();
        cost*=-1;

        min_node.pop();

        if(visited[node.first]) continue;

        visited[node.first]=1;

        for(auto& [child,childCost]:graph[node.first])
        {
            if(!visited[child.first])
            {



                if(cost+childCost < dist[child.first] )
                {
                    dist[child.first]=cost+childCost;
                    min_node.push({-dist[child.first],child});
                    pred[child.first]=node.first;
                }
            }
        }



    }

/*
    ll child = n;
    vector<int> path;

    while(pred[child]!=-1)
    {
        path.push_back(child);
        child=pred[child];
    }

    path.push_back(1);

*/


}


vector<ll> Topo(vector<vector<ll>>& graph,ll n)
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


int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);






    return 0;
}