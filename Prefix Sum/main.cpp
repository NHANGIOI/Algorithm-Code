#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);\
    cin.tie(0);\
    cout.tie(0);
#define endl "\n"
int main()
{
    fastio;
    freopen("inp.inp","r",stdin);
    freopen("out.out","w",stdout);
    int n;  cin>>n;
    vector<long>sum(n+1);
    sum[0]=0;
    for(int i=1;i<=n;i++){
        int x;  cin>>x;
        sum[i]=sum[i-1]+x;
    }
    int t;
    cin>>t;
    while(t--){
        int l,r;    cin>>l>>r;
        cout<<sum[r]-sum[l-1]<<endl;
    }
    return 0;
}