#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);\
    cin.tie(0);\
    cout.tie(0);
#define f(i,a,b)    for(unsigned long i=(a);i<(b);i++)
#define fe(i,a,b)   for(unsigned long i=(a);i<=(b);i++)
unsigned long n;
unsigned long m_weight;
vector<unsigned long>weight;
vector<int>value;
void doc(){
    cin>>n>>m_weight;
    weight.reserve(n);
    value.reserve(n);
    f(i,0,n)
        cin>>weight[i]>>value[i];
}

void qhd(){
    unsigned long dp[n+1][m_weight+1];
    //đièn cơ sở qhd
    fe(i,0,m_weight)
        dp[0][i]=0;
    fe(i,0,n)
        dp[i][0]=0;
    fe(i,1,n){
        fe(j,1,m_weight){
            if(weight[i-1]>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i-1]]+value[i-1]);
        }
    }
    cout<<dp[n][m_weight];
}

int main()
{   
    fastio;
    freopen("balo1.inp","r",stdin);
    freopen("balo1.out","w",stdout);
    doc();
    qhd();
    return 0;
}