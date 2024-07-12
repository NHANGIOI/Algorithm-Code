#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);\
    cin.tie(0);\
    cout.tie(0);
int main()
{
    fastio;
    freopen("matrix.inp","r",stdin);
    freopen("matrix.out","w",stdout);
    int n,m;    cin>>n>>m;
    vector<vector<int>>sum(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x;  cin>>x;
            sum[i][j]= (sum[i-1][j]+sum[i][j-1]+x)-sum[i-1][j-1];
        }
    }
    int t;  cin>>t;
    while(t--){
        int xs,ys,xe,ye;
        cin>>xs>>ys>>xe>>ye;
        cout<<sum[xe][ye]-(sum[xs-1][ye]+sum[xe][ys-1]-sum[xs-1][ys-1])<<endl;
    }
    /**for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<setw(3)<<sum[i][j];
        }
        cout<<endl;
    }**/
    return 0;
}