#include<bits/stdc++.h>
//#include<conio.h>
//#include<stdio.h>
//#include "Number_Theory.h"

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

ll countOnes(ll n)
{
    ll cnt=0;

    while(n)
    {
        n = ((n-1) & n);
        cnt++;
    }

    return cnt;
}

ll get(ll n,ll i)
{
    return (1ULL<<i) & n;
}



int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
/*
    int t; cin>>t;
    while(t--)
    {
        ll a,b; cin>>a>>b;

            ll moves = 0;

            while (a!=b) {

                ll start = -10, end = 10, middle;

                while (start < end) {

                    middle = start +(end - start) / 2;

                    if (a + middle <= b) {
                        start = middle+1;
                    } else if (a + middle > b) {
                        end = middle-1;
                    }

                }

              cout<<a<<" "<<end<<" "<<start<<endl;
                a+=end;
                moves++;

            }


        cout << moves << endl;

    }
    */

    int n; cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];


    unsigned ll len1=0,sum1=0,len2=0,sum2=0;

    for(ll mask=0; mask<(1<<n); mask++) {
        vector<ll> v;
        unsigned ll sum = 0;

        for (int i = 0; i < n; i++) {
            if (get(mask, i)) {
                v.push_back(arr[i]);
                sum += arr[i];
            }
        }

        bool dec = true, inc = true;

        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] >= v[i - 1]) {
                dec = false;
                break;
            }
        }

        if (dec && v.size() >= len2) {
            len2 = v.size();
            sum2 = max(sum2, sum);
        }

        for (int i = 1; i < v.size(); i++) {
            if (v[i] <= v[i - 1]) {
                inc = false;
                break;
            }
        }
/*
            for(int i=0;i<v.size();i++)
            {
                cout<<v[i]<<" ";
            }
            cout<<endl;

            cout<<"-- "<<inc<<" "<<dec<<endl;
*/
        if (inc && v.size() >= len1) {
            len1 = v.size();
            sum1 = max(sum1, sum);
        }

    }


    cout<<len1<<" "<<sum1<<" "<<len2<<" "<<sum2<<endl;

    return 0;
}