#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);\
    cin.tie(0);\
    cout.tie(0);
#define ms(a,b) memset(a,b,sizeof(a))
#define pli pair<ll,int>
#define fi first
#define se second
#define endl "\n"
using ll = long long;
const ll inf =1e14+1;
int main()
{
    fastio;
    //freopen("fly.inp","r",stdin);
    //freopen("fly.out","w",stdout);
    int n;  long m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n+1);
    int pre[n+1];
    for(int i=0;i<m;i++){
        int x,y,w;  cin>>x>>y>>w;
        adj[x].push_back({y,w});
    }
    vector<ll>dist(n+1,inf);
    dist[1]=0;
    bool check[n+1];
    ms(check,false);
    priority_queue<pli,vector<pli>,greater<pli>>q;
    q.push({0,1});
    while(!q.empty()){
        int u=q.top().se;   q.pop();
        if(check[u])    continue;
        check[u]=true;
        for(auto it:adj[u]){
            int v=it.fi,w=it.se;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                q.push({dist[v],v});
                pre[v]=u;
            }
        }
    }
    int n_temp=n;
    vector<int>path;
    while(n_temp!=1){
        path.push_back(n_temp);
        n_temp=pre[n_temp];
    }
    path.push_back(1);
    reverse(path.begin(),path.end());
    vector<int>dis;
    for(int i=0;i<path.size()-1;i++){
        for(auto it:adj[path[i]]){
            if(it.fi==path[i+1]){
                dis.push_back(it.se);
            }
        }
    }
    //================================
    int pre1[n+1];
    vector<ll>dist1(n+1,-1);
    dist1[1]=0;
    bool check1[n+1];
    ms(check1,false);
    priority_queue<pli>q1;
    q1.push({0,1});
    while(!q1.empty()){
        int u1=q1.top().se;   q1.pop();
        if(check1[u1])    continue;
        check1[u1]=true;
        for(auto it:adj[u1]){
            int v1=it.fi,w1=it.se;
            if(dist1[v1]<dist1[u1]+w1){
                dist1[v1]=dist1[u1]+w1;
                q1.push({dist1[v1],v1});
                pre1[v1]=u1;
            }
        }
    }
    int n_temp1=n;
    vector<int>path1;
    while(n_temp1!=1){
        path1.push_back(n_temp1);
        n_temp1=pre1[n_temp1];
    }
    path1.push_back(1);
    reverse(path1.begin(),path1.end());
    vector<int>dis1;
    for(int i=0;i<path1.size()-1;i++){
        for(auto it:adj[path1[i]]){
            if(it.fi==path1[i+1]){
                dis1.push_back(it.se);
            }
        }
    }
    int maxa=(*max_element(dis.begin(),dis.end())/2);
    int maxa1=(*max_element(dis1.begin(),dis1.end())/2);
    if(dist1[n]-(*max_element(dis1.begin(),dis1.end())-maxa1)<0){
        cout<<dist[n]-(*max_element(dis.begin(),dis.end())-maxa);
    }else{
    cout<<min(dist[n]-(*max_element(dis.begin(),dis.end())-maxa),dist1[n]-(*max_element(dis1.begin(),dis1.end())-maxa1));
    }
    return 0;
}