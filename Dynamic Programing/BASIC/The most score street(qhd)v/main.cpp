#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);\
    cin.tie(0);\
    cout.tie(0);
#define f(i,a,b)    for(int i=(a);i<(b);i++)
#define f2(i,a,b)   for(int i=(a);i<=(b);i++)
const int NMAX = 100;
int n,m;
int value[NMAX][NMAX];

void doc(){
    cin>>n>>m;
    f(i,0,n){
        f(j,0,m)
            cin>>value[i][j];
    }
}
void qhd(){
    int dp[n+2][m+2];
    f2(i,0,n+1){    //điền cơ sở qhd
        f2(j,0,m+1)
            dp[i][j]=0;
    }
    f2(i,1,n){
        f2(j,1,m){
            dp[i][j]=max(dp[i][j-1]+value[i-1][j-1],dp[i-1][j]+value[i-1][j-1]);
        }
    }
    cout<<dp[n][m];
}
int main()
{
    fastio;
    freopen("in.inp","r",stdin);
    freopen("out.out","w",stdout);
    doc();
    qhd();
    return 0;
}