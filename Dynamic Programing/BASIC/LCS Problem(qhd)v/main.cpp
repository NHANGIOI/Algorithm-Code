#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);\
    cin.tie(0);\
    cout.tie(0);
#define f(i,a,b)    for(int i=(a);i<(b);i++)
#define fe(i,a,b)   for(int i=(a);i<=(b);i++)
string x,y;
vector<char>a;
void doc(){
    cin>>x>>y;
}
void qhd(int n, int m){
    int dp[n+1][m+1];
    //cơ sở qhd
    fe(i,0,n)   dp[i][0]=0;
    fe(i,1,m)   dp[0][i]=0;
    fe(i,1,n){
        fe(j,1,m){
            if(x[i-1]==y[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    /**fe(i,0,n){
        fe(j,0,m)
            cout<<setw(3)<<dp[i][j];
        cout<<endl;
    }**/
    int f=m;
    for(int i=n;i>=1;i--){
        if(dp[i][f]!=dp[i-1][f]){
            a.push_back(x[i-1]);
            f--;
        }
    }
    reverse(a.begin(),a.end());
    cout<<dp[n][m]<<"\n";
    for(vector<char>:: iterator it = a.begin();it != a.end();it++)
        cout<<*it;
}

int main()
{
    fastio;
    freopen("lcs.inp","r",stdin);
    freopen("lcs.out","w",stdout);
    doc();
    int n=x.length();
    int m=y.length();
    qhd(n,m);
    return 0;
}