#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);\
    cin.tie(0);\
    cout.tie(0);
#define fi first
#define se second
#define endl "\n"
using ll= long long;
const ll inf = 1e14+1;
int main()
{
    fastio;
    //freopen("syrjala.inp","r",stdin);
    //freopen("syrjala.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=0;i<m;i++){
        int x,y,w;  cin>>x>>y>>w;
        adj[x].push_back({y,w});
    }
    bool check[n+1];
    memset(check,false,sizeof(check));
    vector<ll>dist(n+1,inf);
    dist[1]=0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>q;
    q.push({0,1});
    while(!q.empty()){
        pair<ll,int> top = q.top(); q.pop();
        int u = top.se;
        if(check[u])    continue;
        check[u]=true;
        for(auto it:adj[u]){
            int v = it.fi;
            ll w = it.se;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                q.push({dist[v],v});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}