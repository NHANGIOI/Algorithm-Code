#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);\
    cin.tie(0);\
    cout.tie(0);
#define endl "\n"
#define fi first
#define se second
using ll = long long;
const int NMAX = 1e6;
const int inf = 1e6+1;
int n,m,s,e;
vector<pair<int,int>>adj[NMAX];
void nhap(){
    cin>>n>>m>>s>>e;
    for(int i=0;i<m;i++){
        int x,y,w;  cin>>x>>y>>w;
        adj[x].push_back({y,w});
    }
}
void dikjstra(){
    vector<ll>dist(n+1,inf);
    vector<int>pre(n+1);
    //dist.reserve(n+1);
    //pre.reserve(n+1);
    dist[s]=0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>q;
    bool check[n+1];
    memset(check,false,sizeof(check));
    q.push({0,s});
    while(!q.empty()){
        pair<ll,int> top = q.top(); q.pop();
        int u=top.se;
        int len=top.fi;
        if(check[u])   continue;
        check[u]=true;
        for(auto it : adj[u]){
            ll v = it.fi;
            int w=it.se;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                q.push({dist[v],v});
                pre[v]=u;
            }
        }
    }
    cout<<dist[e]<<endl;
    int e_temp = e;
    stack<int>path;
    while(e_temp!=s){
        path.push(e_temp);
        e_temp=pre[e_temp];
    }
    while(!path.empty()){
        cout<<path.top()<<" ";  path.pop();
    }
}
int main()
{
    fastio;
    freopen("MINPATH.INP","r",stdin);
    freopen("MINPATH.OUT","w",stdout);
    nhap();
    dikjstra();
    return 0;
}