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


int main3() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;

        if(n==1) cout<<1<<endl;
        else if(n==2) cout<<-1<<endl;
        else
        {

            vector<vector<ll>> mat(n,vector<ll>(n));

            ll num=1;

            // main diagonals

            for(int i=0;i<n;i+=2)
            {
                ll x=i,y=0;
                while(x<n && x>=0 && y>=0 && y<n && mat[x][y]==0)
                {
                    mat[x][y]=num;
                    x--;
                    y++;
                    num++;
                }
            }

            for(int i=n-1;i>=0;i-=2)
            {
                ll x=n-1,y=i;
                while(x<n && x>=0 && y>=0 && y<n && mat[x][y]==0)
                {
                    mat[x][y]=num;
                    x--;
                    y++;
                    num++;
                }
            }

            // side diagonals

            for(int i=1;i<n;i+=2)
            {
                ll x=i,y=0;
                while(x<n && x>=0 && y>=0 && y<n && mat[x][y]==0)
                {
                    mat[x][y]=num;
                    x--;
                    y++;
                    num++;
                }
            }

            for(int i=n-2;i>=0;i-=2)
            {
                ll x=n-1,y=i;
                while(x<n && x>=0 && y>=0 && y<n && mat[x][y]==0)
                {
                    mat[x][y]=num;
                    x--;
                    y++;
                    num++;
                }
            }




            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cout<<mat[i][j]<<" ";
                }
                cout<<endl;
            }


        }

    }



    return 0;
}