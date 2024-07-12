#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);\
    cin.tie(0);\
    cout.tie(0);
#define f(i,a,b)    for(int i=(a);i<(b);i++)
#define fe(i,a,b)   for(int i=(a);i<=(b);i++)
#define endl "\n"
string a;
void doc(){
    cin>>a;
}
void qhd(int n){
    int max_len=1;
    int max_i = 0,max_j=0;
    bool dp[n+1][n+1];
    int j=0;
    memset(dp,false,sizeof(dp));
    for(int i=0;i<=n;i++)//cơ sở qhd
        dp[i][i]=true;
    for(int len=2;len<=n;len++){
        for(int i=1,j=i+len-1;i<=n-len+1,j<=n;i++,j++){
            if(a[i-1] == a[j-1]){
                if(len==2)
                    dp[i][j]=true;
                else if (dp[i+1][j-1])
                    dp[i][j]=true;
            }
            if(dp[i][j]&& max_len<len){
                max_len = len;
                max_i=i;
                max_j=j;
            }
        }
    }
    //bảng giá trị
    fe(i,0,n){
        fe(j,0,n)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    cout<<max_len<<endl;
    f(i,max_i-1,max_j)
        cout<<a[i];
    
    

}
int main()
{   
    fastio;
    freopen("lps.inp","r",stdin);
    freopen("lps.out","w",stdout);
    doc();
    int n = a.length();
    qhd(n);
    return 0;
}