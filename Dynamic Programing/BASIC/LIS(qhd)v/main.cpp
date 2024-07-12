#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);\
    cin.tie(0);\
    cout.tie(0);
#define lap(i,a,b)  for(int i=(a);i<(b);i++)
#define endl "\n"
int n;
vector<int>a;
vector<int>L;
void doc(){
    cin>>n;
    a.reserve(n);
    lap(i,0,n)  cin>>a[i];
}
void qhd(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[i-1]>a[j-1])
                L[i]=max(L[i],L[j]+1);
        }
    }
}
int main()
{   
    fastio;
    //freopen("lis.inp","r",stdin);
    //freopen("lis.out","w",stdout);
    doc();
    L.reserve(n+2);
    L[0]=-32000;
    for(int i=0;i<=n+1;i++)//điền cơ sở qhd
        L[i]=1;
    L[n+1]=-32000;

    qhd();
    auto maxa = 0;
    for(int i=0;i<=n;i++){
        if(maxa<L[i])   maxa=L[i];
    }
    cout<<maxa;
    return 0;
}