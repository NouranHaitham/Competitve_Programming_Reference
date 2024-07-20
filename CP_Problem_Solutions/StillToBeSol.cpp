#include<bits/stdc++.h>

# define INF LONG_MAX
# define INF_INT INT_MAX
# define endl '\n'
# define YES cout<<"YES"<<endl;
# define NO cout<<"NO"<<endl;
# define ll long long
using namespace std;

int main2() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n; cin>>n;

    vector<vector<ll>> grid(n,vector<ll>(n));
    vector<vector<ll>> row(n,vector<ll>(n));
    vector<vector<ll>> col(n,vector<ll>(n));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>grid[i][j];
            col[j][i] = grid[i][j] ;
            row[i][j] = grid[i][j] ;
        }
    }

    for(int i=0;i<n;i++)
    {
        std::sort(row[i].begin(), row[i].end(),greater<ll>());
        std::sort(col[i].begin(), col[i].end(),greater<ll>());
    }


    int q; cin>>q;

    while(q--)
    {
        int a, b; cin>>a>>b; a--; b--;

        ll k=grid[a][b]; k--;
        cout<<row[a][k]<<" "<<col[b][k]<<endl;

    }


    return 0;
}