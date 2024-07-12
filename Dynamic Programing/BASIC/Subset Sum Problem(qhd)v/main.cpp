#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);\
    cin.tie(0);\
    cout.tie(0);
#define endl "\n"
#define f(i,a,b)    for(int i=(a);i<(b);i++)
#define fe(i,a,b)   for(int i=(a);i<=(b);i++)
int n,S;
vector<int>a;
void doc(){
    cin>>n>>S;
    a.reserve(n);
    f(i,0,n)    cin>>a[i];
}
extern void qhd();
int main()
{   
    fastio;
    freopen("ssp.inp","r",stdin);
    freopen("ssp.out","w",stdout);
    doc();
    qhd();
    return 0;
}
void qhd(){
    bool dp[n+1][S+1];
    //Điền cơ sở qhd
    fe(i,0,n)   dp[i][0]=true;//TH không chọn thì dãy lun có tổng bằng 0 nên TH 0 luôn đúng
    fe(i,1,S)   dp[0][i]=false;//TH không chọn thì dãy lun có tổng bằng 0 nên các TH >0 luôn sai


    fe(i,1,n){
        fe(k,1,S)
            dp[i][k]=dp[i-1][k];
        for(int j=S;j>=1;j--)
            if(dp[i][j]==true)
                continue;
            else
                dp[i][j]=dp[i][j-a[i-1]];
    }
    cout<<dp[n][S];
}