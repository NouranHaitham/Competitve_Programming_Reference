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


int main1() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


    ll n,m; cin>>n>>m;
    int q; cin>>q;


    vector<vector< ll>> preRow(n+4,vector< ll>(m+4,0)),preCol(n+4,vector< ll>(m+4,0));


    while(q--)
    {
        char s;
        ll k,i,j,x;

        cin>>s>>k>>i>>j>>x;

        if(s=='R')
        {
            preRow[k][i]+=x;
            preRow[k][j+1]-=x;
        }
        else
        {
            preCol[i][k]+=x;
            preCol[j+1][k]-=x;

        }
    }


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            preRow[i][j]+=preRow[i][j-1];
        }
    }


    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            preCol[j][i]+=preCol[j-1][i];
        }
    }

    ll mx=preRow[1][1]+preCol[1][1];

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            mx=max(mx,preRow[i][j]+preCol[i][j]);
        }
    }


    cout<<mx<<endl;


    return 0;
}