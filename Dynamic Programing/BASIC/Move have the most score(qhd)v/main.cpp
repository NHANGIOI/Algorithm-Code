#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);\
    cin.tie(0);\
    cout.tie(0);
#define endl "\n"
#define f(i,a,b)    for(int i=(a);i<(b);i++)
#define fe(i,a,b)   for(int i=(a);i<=(b);i++)
const int NMAX =100;
int value [NMAX][NMAX];
int n,m;
void doc(){
    cin>>n>>m;
    f(i,0,n){
        f(j,0,m)
            cin>>value[i][j];
    }
}
void qhd(){
    int dp[n+2][m+2];
    fe(i,0,n+1){
        fe(j,0,m+1)
            dp[i][j]=0;
    }
    fe(j,1,m){
        fe(i,1,n)
            dp[i][j]=max({dp[i-1][j-1],dp[i][j-1],dp[i+1][j-1]})+value[i-1][j-1];
    }
    long maxa=0;
    fe(i,1,n){
        if(maxa<dp[i][m])
            maxa=dp[i][m];
    }
    cout<<maxa;
}
int main()
{   
    fastio;
    freopen("move.inp","r",stdin);
    freopen("move.out","w",stdout);
    doc();
    qhd();
    return 0;
}