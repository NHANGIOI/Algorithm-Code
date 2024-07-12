#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);\
    cin.tie(0);\
    cout.tie(0);
#define fi first
#define se second
#define endl "\n"
using ll= unsigned long long;
const ll inf = 1e14+1;
int main()
{
    fastio;
    //freopen("cities.inp","r",stdin);
    //freopen("cities.out","w",stdout);
    int n;
    long m;
    long qq;
    cin>>n>>m>>qq;
    vector<vector<pair<int,ll>>>adj(n+1);
    for(int i=0;i<m;i++){
        int x,y,w;  cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    while(qq--){
        int s,e;    cin>>s>>e;
        bool check[n+1];
        memset(check,false,sizeof(check));
        vector<ll>dist(n+1,inf);
        dist[s]=0;
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>q;
        q.push({0,s});
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
        if(dist[e]==inf){
            cout<<-1<<endl;
        }else{  cout<<dist[e]<<endl;}
    }
    return 0;
}