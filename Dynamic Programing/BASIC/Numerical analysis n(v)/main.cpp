#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);\
    cin.tie(0);\
    cout.tie(0);
#define fe(i,a,b)    for(int i=(a);i<=(b);i++)
#define endl "\n"
int n;
void doc(){
    cin>>n;
}
void qhd(){
    int dp[n+1][n+1];
    fe(i,0,n){
        fe(j,0,n)
            dp[i][j]=5;
    }
    fe(i,0,n)   dp[i][0]=1;
    fe(i,1,n)   dp[0][i]=0;

    fe(i,1,n){
        fe(j,1,n){
            if(i>j)
                dp[i][j]=dp[i-1][j];
            else    
                dp[i][j]=dp[i-1][j]+dp[i][j-i];
        }
    }

    /**fe(i,0,n){
        fe(j,0,n)
            cout<<setw(3)<<dp[i][j];
        cout<<endl;
    }**/
    cout<<dp[n][n];
}
int main()
{
    fastio;
    //freopen("num.inp","r",stdin);
    //freopen("num.out","w",stdout);
    doc();
    qhd();
    return 0;
}